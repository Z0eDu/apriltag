import cv2
import numpy as np
import sys

#img = sys.argv[1]
img = cv2.imread('download.jpeg', 1)
hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

color = np.uint8([[[0, 240, 255]]])
hsv_color = cv2.cvtColor(color, cv2.COLOR_BGR2HSV)
hue = hsv_color[0][0][0]

lower_bound = np.array([hue-10, 100, 100], dtype = np.uint8)
upper_bound = np.array([hue+10, 255, 255], dtype = np.uint8)

mask = cv2.inRange(hsv, lower_bound, upper_bound)

white  = cv2.countNonZero(mask)
print("Amount of yellow: " + str(white))
cv2.imshow('mask', mask)
cv2.imshow('image', img)

while(1):
    k = cv2.waitKey(0)
    if (k ==27): break
cv2.destroyAllWindows()


