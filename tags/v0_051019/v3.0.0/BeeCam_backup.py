import RPi.GPIO as GPIO
import time
import os
import subprocess
import sys
import pygame
import datetime
import cv2
import numpy as np
from pygame.locals import *

#piTFT environment variables
#os.putenv('SDL_VIDEODRIVER', 'fbcon')
#os.putenv('SDL_FBDEV', '/dev/fb1')
#os.putenv('SDL_MOUSEDRV', 'TSLIB')
#os.putenv('SDL_MOUSEDEV', '/dev/input/touchscreen')

class Bee(object) :
    entries = list()
    exits = list()

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

bees = list()
for x in range(50) :
    bee = Bee()
    bees.append(bee)


def GPIO27_callback(channel):
    GPIO.output(19, GPIO.LOW)
    GPIO.output(13, GPIO.LOW)
    GPIO.cleanup()
    file = open("BeeData.txt", "w+")
    file.write("Bee Data: \n")
    for x in range(50):
        file.write("Bee %d:\r\n" %x)
       # num_entries = len(bees.get(x).entries)
       # num_exits = len(bees.get(x).exits)
        file.write("Entries:\r ")
        #for y in range(num_entries):
           # file.write("%d , " %bees.get(x).entries.get(y))
        file.write("\n")
        file.write("Exits:\r ")
        #for z in range(num_exits):
           # file.write("%d , " %bees.get(x).entries.get(z)
        file.write("\n")
    quit()

def GPIO17_callback(channel):
    global paused
    paused = not paused

GPIO.add_event_detect(27, GPIO.FALLING, callback=GPIO27_callback, bouncetime=300)
GPIO.add_event_detect(17, GPIO.FALLING, callback=GPIO17_callback, bouncetime=300)


while(True):
    sensor1 = not GPIO.input(5)
    sensor2 = not GPIO.input(26)
    if (sensor1 or sensor2):
        GPIO.output(19, GPIO.HIGH)
        GPIO.output(13, GPIO.HIGH)
        current_time = time.time();
        cnt = cnt + 1

        if(sensor1):
            num_name = str(cnt) + "_s1"
        else: 
            num_name = str(cnt) + "_s2"

        os.system("sudo raspistill -t "+delay+" -ex sport -ss "+ss+" -o top" + num_name + ".jpg")
        os.system("./apriltag_demo -f tag36h11 top" + num_name + ".jpg > " + num_name + ".txt &")
        PollenDetect("side" + num_name + ".jpg")
        #omehow wait for file to be created
        f = open(num_name + ".txt", r)
        line = f.readline()
        f.close()
        if "detection" in line : 
            indx  = line.index('-')
            if (line.charAt(indx+2)).isDigit() :
                tag = int(line[indx+1:indx+2])
            else : 
                tag = int(line.charAt(indx+1))
        else : 
            tag = -1
        if (tag != -1) : 
            bee = bees.get(tag)
            if sensor1 : 
                bee.exits.append(current_time)
            else : 
                bee.entries.append(current_time)
        time.sleep(.5)
    else:
        GPIO.output(19, GPIO.LOW)
        GPIO.output(13, GPIO.LOW)
   
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
    
    
