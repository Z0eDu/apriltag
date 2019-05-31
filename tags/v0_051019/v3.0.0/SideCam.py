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
#os.putenv('SDL_VIDEODRIVER', 'fbcon')
#os.putenv('SDL_FBDEV', '/dev/fb1')
#os.putenv('SDL_MOUSEDRV', 'TSLIB')
#os.putenv('SDL_MOUSEDEV', '/dev/input/touchscreen')



pollen = []
times = []
size = width, height = 320, 240
pygame.init()
pygame.mouse.set_visible(True)
screen = pygame.display.set_mode(size)
font = pygame.font.Font(pygame.font.get_default_font(), 12)
white = 255, 255, 255
black = 0, 0, 0
red = 255, 0, 0
green = 0, 255, 0
blue = 0, 0, 255
yellow = 255, 255, 0
GPIO.setmode(GPIO.BCM)
GPIO.setup(19, GPIO.OUT)     #ring light 1
GPIO.setup(13, GPIO.OUT)     #ring light 2
GPIO.setup(27, GPIO.IN, pull_up_down=GPIO.PUD_UP) #bailout button
GPIO.setup(5, GPIO.IN, pull_up_down=GPIO.PUD_UP)     #beam sensor 1
GPIO.setup(26, GPIO.IN, pull_up_down=GPIO.PUD_UP)     #beam sensor 2



#instantiate variables
sensor1 = False     #exiting sensor
sensor2 = False     #entering sensor
current_time = ""
hasPollen = False
cnt = 0
dl = 500        #minimum 100, maximum 6000, steps of 25
ss = 100        #100 is minimum already, maximum 1000, steps of 25

r_thr = 255
g_thr = 240
b_thr = 0

side = "default.png"
num_name = ""
yellow_pix = 0
threshold = 1000


#test
img = cv2.imread("default.png", 1)
hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
color = np.uint8([[[b_thr, g_thr, r_thr]]])
hsv_color = cv2.cvtColor(color, cv2.COLOR_BGR2HSV)
hue = hsv_color[0][0][0]
lower_bound = np.array([hue-10, 100, 100], dtype = np.uint8)
upper_bound = np.array([hue+10, 255, 255], dtype = np.uint8)
mask = cv2.inRange(hsv, lower_bound, upper_bound)
cv2.imwrite("default_side.jpg", mask)
side_mask = "default_side.jpg"
yellow_pix = cv2.countNonZero(mask)
if(yellow_pix > threshold) :
    hasPollen = True
else :
    hasPollen = False
#end test
paused = False

def GPIO27_callback(channel):
    GPIO.output(19, GPIO.LOW)
    GPIO.output(13, GPIO.LOW)
    GPIO.cleanup()
    file = open("PollenData.txt", "w+")
    file.write("Pollen Data:\n")
    file.write("Pollen: " + str(pollen) + "\n")
    file.write("Time Stamps: " + str(times) + "\n")
    file.close()
    quit()

GPIO.add_event_detect(27, GPIO.FALLING, callback=GPIO27_callback, bouncetime=300)

while True: 
    if not paused :
        sensor1 = not GPIO.input(5)
        sensor2 = not GPIO.input(26)
        if (sensor1 or sensor2):
            GPIO.output(19, GPIO.HIGH)
            GPIO.output(13, GPIO.HIGH)
            current_time = t.gmtime(t.time())
            times.append(current_time)
            cnt = cnt + 1
            if(sensor1):
                num_name = str(cnt) + "_s1"
            else: 
                num_name = str(cnt) + "_s2"
            os.system("sudo raspistill -t " + str(dl) + " -ex sports -ss " + str(ss) + " -hf -vf -o side" + num_name + ".jpg")
            side = "side" + num_name + ".jpg"

            img = cv2.imread("side" + num_name + ".jpg", 1)
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
            pollen.append(num_name + ": " + str(hasPollen))
            t.sleep(.2)
        else:
            GPIO.output(19, GPIO.LOW)
            GPIO.output(13, GPIO.LOW)
   
    pygame.draw.rect(screen, black, [0, 0, 320, 240])
    pygame.draw.rect(screen, white, [1, 20, 152, 122])
    image1 = pygame.image.load(side_mask)
    image2 = pygame.image.load(side)
    image1 = pygame.transform.scale(image1, (150, 120))
    image2 = pygame.transform.scale(image2, (70, 70))
    image1_rect = image1.get_rect()
    image2_rect = image2.get_rect()
    image1_rect = image1_rect.move(2, 21)
    image2_rect = image2_rect.move(160, 20)

    red_up_button = pygame.draw.rect(screen, red, [20, 180, 30, 20])
    red_down_button = pygame.draw.rect(screen, red, [20, 210, 30, 20])

    green_up_button = pygame.draw.rect(screen, green, [60, 180, 30, 20])
    green_down_button = pygame.draw.rect(screen, green, [60, 210,30, 20])

    blue_up_button = pygame.draw.rect(screen, blue, [100, 180, 30, 20])
    blue_down_button = pygame.draw.rect(screen, blue, [100, 210, 30, 20])

    ss_up = pygame.draw.rect(screen, white, [160, 125, 30, 20])
    ss_down = pygame.draw.rect(screen, white, [210, 125, 30, 20])

    dl_up = pygame.draw.rect(screen, white, [160, 167, 30, 20])
    dl_down = pygame.draw.rect(screen, white, [210, 167,30, 20])

    pixel_up = pygame.draw.rect(screen, white, [160, 210, 35, 20])
    pixel_down = pygame.draw.rect(screen, white, [210, 210, 35, 20])

    ss_up_b = font.render("SS+", True, black)
    ss_down_b = font.render("SS-", True, black)
    ss_up_r = ss_up_b.get_rect()
    ss_up_r.center = ss_up.center
    ss_down_r = ss_down_b.get_rect()
    ss_down_r.center = ss_down.center

    dl_up_b = font.render("DL+", True, black)
    dl_down_b = font.render("DL-", True, black)
    dl_up_r = dl_up_b.get_rect()
    dl_up_r.center = dl_up.center
    dl_down_r = dl_down_b.get_rect()
    dl_down_r.center = dl_down.center

    run_b = pygame.draw.rect(screen, yellow, [235, 50, 72, 20])
    run = font.render("Run Again", True, black)
    run_r = run.get_rect()
    run_r.center = run_b.center

    red_up_b = font.render("+", True, black)
    red_up_b_rect = red_up_b.get_rect()
    red_up_b_rect.center = red_up_button.center  
    red_down_b = font.render("-", True, black)
    red_down_b_rect = red_down_b.get_rect()
    red_down_b_rect.center = red_down_button.center  

    green_up_b = font.render("+", True, black)
    green_up_b_rect = green_up_b.get_rect()
    green_up_b_rect.center = green_up_button.center 
    green_down_b = font.render("-", True, black)
    green_down_b_rect = green_down_b.get_rect()
    green_down_b_rect.center = green_down_button.center 
    
    blue_up_b = font.render("+", True, black)
    blue_up_b_rect = blue_up_b.get_rect()
    blue_up_b_rect.center = blue_up_button.center  
    blue_down_b = font.render("-", True, black)
    blue_down_b_rect = blue_down_b.get_rect()
    blue_down_b_rect.center = blue_down_button.center 

    pixel_up_b = font.render("Pix+", True, black)
    pixel_up_b_rect = pixel_up_b.get_rect()
    pixel_up_b_rect.center = pixel_up.center  
    pixel_down_b = font.render("Pix-", True, black)
    pixel_down_b_rect = pixel_down_b.get_rect()
    pixel_down_b_rect.center = pixel_down.center  


    thr_vals = font.render("Threshold Values:", True, white)
    thr_vals_r = thr_vals.get_rect()
    thr_vals_r.left = 15
    thr_vals_r.top = 145

    vals = font.render("R=" + str(r_thr) + " G=" + str(g_thr) + " B=" + str(b_thr), True, white)
    vals_r = vals.get_rect()
    vals_r.left = 15
    vals_r.top = 160
    
    m_thr = font.render("Pixel # Threshold: " + str(threshold), True, white)
    m_thr_r = thr_vals.get_rect()
    m_thr_r.left = 160
    m_thr_r.top = 194

    shuttersp = font.render("Shutter Speed: " + str(ss) + " us", True, white)
    shutter_r = shuttersp.get_rect()
    shutter_r.left = 160
    shutter_r.top = 110

    delay = font.render("Delay Time: " + str(dl) + " ms", True, white)
    delay_r = delay.get_rect()
    delay_r.left = 160
    delay_r.top = 151

    pol_pix = font.render("Pollen Pixel #: " + str(yellow_pix), True, white)
    pol_pix_r = pol_pix.get_rect()
    pol_pix_r.left = 160
    pol_pix_r.top = 95

    pollen_id = font.render("Pollen? " + str(hasPollen), True, white)
    pollen_id_r = pollen_id.get_rect()
    pollen_id_r.left = 235
    pollen_id_r.top = 20
    
    filter_b = font.render("Filtered: ", True, white)
    filter_r = filter_b.get_rect()
    filter_r.left = 1
    filter_r.top = 3

    og = font.render("Original: ", True, white)
    og_r = og.get_rect()
    og_r.left = 160
    og_r.top = 3


    for event in pygame.event.get():
        if(event.type is MOUSEBUTTONDOWN):
            mouse_pos = pygame.mouse.get_pos()
            if(red_up_button.collidepoint(mouse_pos)):
                r_thr = min(r_thr+2, 255)
            if(red_down_button.collidepoint(mouse_pos)):
                r_thr = max(r_thr-2, 0)
            if(green_up_button.collidepoint(mouse_pos)):
                g_thr = min(g_thr+2, 255)
            if(green_down_button.collidepoint(mouse_pos)):
                g_thr = max(g_thr-2, 0)
            if(blue_up_button.collidepoint(mouse_pos)):
                b_thr = min(b_thr+2, 255)
            if(blue_down_button.collidepoint(mouse_pos)):
                b_thr = max(b_thr-2, 0)
            if(run_b.collidepoint(mouse_pos)):
                img = cv2.imread("side" + num_name + ".jpg", 1)
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

            if(ss_up.collidepoint(mouse_pos)):
                ss = min(ss + 20, 1000)
            if(ss_down.collidepoint(mouse_pos)):
                ss = max(ss - 20, 100)
            if(dl_up.collidepoint(mouse_pos)):
                dl = min(dl + 20, 3000)
            if(dl_down.collidepoint(mouse_pos)):
                dl = max(dl - 20, 50)
            if(pixel_up.collidepoint(mouse_pos)):
                threshold = min(threshold+25, 100000)
            if(pixel_down.collidepoint(mouse_pos)):
                threshold = max(threshold-25, 300)



    
    screen.blit(dl_up_b, dl_up_r)
    screen.blit(m_thr, m_thr_r)
    screen.blit(dl_down_b, dl_down_r)
    screen.blit(ss_up_b, ss_up_r)
    screen.blit(ss_down_b, ss_down_r)
    screen.blit(pol_pix, pol_pix_r)
    screen.blit(pollen_id, pollen_id_r)
    screen.blit(thr_vals, thr_vals_r)
    screen.blit(pixel_up_b, pixel_up_b_rect)
    screen.blit(pixel_down_b, pixel_down_b_rect)
    screen.blit(vals, vals_r)
    screen.blit(run, run_r)
    screen.blit(delay, delay_r)
    screen.blit(shuttersp, shutter_r)
    screen.blit(filter_b, filter_r)
    screen.blit(og, og_r)
    screen.blit(red_up_b, red_up_b_rect)
    screen.blit(red_down_b, red_down_b_rect)
    screen.blit(blue_up_b, blue_up_b_rect)
    screen.blit(blue_down_b, blue_down_b_rect)
    screen.blit(green_up_b, green_up_b_rect)
    screen.blit(green_down_b, green_down_b_rect)
    screen.blit(image1, image1_rect)
    screen.blit(image2, image2_rect)

    pygame.display.flip()
 
    
