import RPi.GPIO as GPIO
import time as t
import os
import subprocess
import sys
import pygame
import datetime
import cv2
import numpy as np
from pygame.locals import *

#piTFT environment variables
os.putenv('SDL_VIDEODRIVER', 'fbcon')
os.putenv('SDL_FBDEV', '/dev/fb1')
os.putenv('SDL_MOUSEDRV', 'TSLIB')
os.putenv('SDL_MOUSEDEV', '/dev/input/touchscreen')

class Bee(object) :
    def __init__(self):
        entries = []
        exits = []

size = width, height = 320, 240
pygame.init()
pygame.mouse.set_visible(True)
screen = pygame.display.set_mode(size)
font = pygame.font.Font(pygame.font.get_default_font(), 12)
white = 255, 255, 255
black = 0, 0, 0
color = 127, 15, 111
GPIO.setmode(GPIO.BCM)
GPIO.setup(19, GPIO.OUT)     #ring light 1
GPIO.setup(13, GPIO.OUT)     #ring light 2
GPIO.setup(27, GPIO.IN, pull_up_down=GPIO.PUD_UP) #bailout button
GPIO.setup(17, GPIO.IN, pull_up_down=GPIO.PUD_UP) #pause/start button
GPIO.setup(5, GPIO.IN, pull_up_down=GPIO.PUD_UP)     #beam sensor 1
GPIO.setup(26, GPIO.IN, pull_up_down=GPIO.PUD_UP)     #beam sensor 2

#instantiate variables
sensor1 = False     #exiting sensor
sensor2 = False     #entering sensor
current_time = 0.0
hasPollen = False
cnt = 0
num_name = ""
delay = 500         #minimum 100, maximum 6000, steps of 25
ss = 100            #100 is minimum already, maximum 1000, steps of 25
tag = -1
global paused

paused = False

ss_up_button = pygame.draw.rect(screen, white, [20, 200, 50, 30])
ss_down_button = pygame.draw.rect(screen, white, [90, 200, 50, 30])
delay_up_button = pygame.draw.rect(screen, white, [180, 200, 50, 30])
delay_down_button = pygame.draw.rect(screen, white, [250, 200, 50, 30])
top = "default.png"

bees = []
pics_taken = []
for x in range(50) :
    bee = Bee()
    bee.entries = []
    bee.exits = []
    bees.append(bee)

def GPIO27_callback(channel):
    GPIO.output(19, GPIO.LOW)

    GPIO.output(13, GPIO.LOW)
    GPIO.cleanup()
    file = open("BeeData.txt", "w+")
    file.write("Bee Data: \n")
    for x in range(50):
        file.write("Bee %d:\n" %x)
        bee = bees[x]
        file.write("Entries: " +  str(bee.entries) + "\n")
        file.write("Exits: " + str(bee.exits) + "\n")
        file.write("\n")
    file.close()
    quit()

def GPIO17_callback(channel):
    paused = not paused

GPIO.add_event_detect(27, GPIO.FALLING, callback=GPIO27_callback, bouncetime=300)
GPIO.add_event_detect(17, GPIO.FALLING, callback=GPIO17_callback, bouncetime=300)


while(True):
    if (not paused):    
        sensor1 = not GPIO.input(5)
        sensor2 = not GPIO.input(26)
        if (sensor1 or sensor2):
            GPIO.output(19, GPIO.HIGH)
            GPIO.output(13, GPIO.HIGH)
            current_time = t.gmtime(t.time())
            cnt = cnt + 1

            if(sensor1):
                num_name = str(cnt) + "_s1"
            else: 
                num_name = str(cnt) + "_s2"

            os.system("sudo raspistill -t " + str(delay) + " -ex sports -ss " + str(ss) + " -o top" + num_name + ".jpg")
            pics_taken.append(num_name)
            os.system("./apriltag_demo -f tag36h11 top" + num_name + ".jpg > " + num_name + ".txt &")
            os.system("./file_analyze "  + num_name + " &")
            top = "top" + num_name + ".jpg"
            t.sleep(.2)
        else:
            GPIO.output(19, GPIO.LOW)
            GPIO.output(13, GPIO.LOW)
           # img = cv2.imread("side" + num_name + ".jpg", 1)
            hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

            color = np.uint8([[[b_thr, g_thr, r_thr]]])
            hsv_color = cv2.cvtColor(color, cv2.COLOR_BGR2HSV)
            hue = hsv_color[0][0][0]

            lower_bound = np.array([hue-10, 100, 100], dtype = np.uint8)
            upper_bound = np.array([hue+10, 255, 255], dtype = np.uint8)

            mask = cv2.inRange(hsv, lower_bound, upper_bound)
            cv2.imwrite("smask.jpg", mask)
            side_mask = "smask.jpg"
            yellow_pix = cv2.countNonZero(mask)
            if(yellow_pix > threshold) :
                hasPollen = True
            else :
                hasPollen = False

    if len(pics_taken) != 0 : 
        pic = pics_taken[0]
        print(os.path.exists("done_" + pic + ".txt"))
        if os.path.exists("done_" + pic + ".txt") :
            pics_taken.pop(0)
            f = open("done_" + pic + ".txt")
            line = f.readline()
            if not "-1" in line :
                print(line[4:])
                tag = int(line[4:])

   
    pygame.draw.rect(screen, black, [0, 0, 320, 200])

    image1 = pygame.image.load(top)
    image1 = pygame.transform.scale(image1, (160, 160))
    
    image1_rect = image1.get_rect()
    image1_rect = image1_rect.move(80, 10)

    ss_up_button = pygame.draw.rect(screen, white, [20, 200, 50, 30])
    ss_down_button = pygame.draw.rect(screen, white, [90, 200, 50, 30])
    delay_up_button = pygame.draw.rect(screen, white, [180, 200, 50, 30])
    delay_down_button = pygame.draw.rect(screen, white, [250, 200, 50, 30])
 
    
    ss_up_b = font.render("SS+", True, black)
    ss_up_b_rect = ss_up_b.get_rect()
    ss_up_b_rect.center = ss_up_button.center  

    ss_down_b = font.render("SS-", True, black)
    ss_down_b_rect = ss_down_b.get_rect()
    ss_down_b_rect.center = ss_down_button.center  

    delay_up_b = font.render("DELAY+", True, black)
    delay_up_b_rect = delay_up_b.get_rect()
    delay_up_b_rect.center = delay_up_button.center  

    delay_down_b = font.render("DELAY-", True, black)
    delay_down_b_rect = delay_down_b.get_rect()
    delay_down_b_rect.center = delay_down_button.center  

    shs = font.render("Shutter Speed: " + str(ss) + " us", True, white)
    shs_r = shs.get_rect()
    shs_r.left = 18
    shs_r.top = 180
    
    dl = font.render("Delay: " + str(delay) + " ms", True, white)
    dl_r = dl.get_rect()
    dl_r.left = 180
    dl_r.top = 180

    file_name = font.render(num_name + ".txt", True, white)
    file_r = file_name.get_rect()
    file_r.left = 5
    file_r.top = 45

    tagid = font.render("Tag ID# :", True, white)
    tagid_r = tagid.get_rect()
    tagid_r.left = 5
    tagid_r.top = 10

    idNum = font.render(str(tag), True, white)
    idNum_r = idNum.get_rect()
    idNum_r.left = 5
    idNum_r.top = 25 
    
    date = font.render("Date:", True, white)
    date_r = date.get_rect()
    date_r.left = 255
    date_r.top = 10

    time = font.render(str(current_time), True, white)
    time_r = time.get_rect()
    time_r.left = 255
    time_r.top = 25

    for event in pygame.event.get():
        if(event.type is MOUSEBUTTONDOWN):
            mouse_pos = pygame.mouse.get_pos()
            if(ss_up_b_rect.collidepoint(mouse_pos)):
                ss = min(ss + 25, 1000)
            if(ss_down_b_rect.collidepoint(mouse_pos)):
                ss = max(ss - 25, 100)
            if(delay_up_b_rect.collidepoint(mouse_pos)):
                delay = min(delay + 25, 6000)
            if(delay_down_b_rect.collidepoint(mouse_pos)):
                delay = max(delay - 25, 100)
    
    screen.blit(file_name, file_r)
    screen.blit(shs, shs_r)
    screen.blit(dl, dl_r)
    screen.blit(time, time_r)
    screen.blit(tagid, tagid_r)
    screen.blit(idNum, idNum_r)
    screen.blit(date, date_r)
    screen.blit(ss_up_b, ss_up_b_rect)
    screen.blit(ss_down_b, ss_down_b_rect)
    screen.blit(delay_up_b, delay_up_b_rect)
    screen.blit(delay_down_b, delay_down_b_rect)
    screen.blit(image1, image1_rect)
    
    pygame.display.flip()
    
    
