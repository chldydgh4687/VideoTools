from PIL import Image
import cv2
import numpy as np
import glob

# 파일명의 형식 : 파일이름_size_qp.png

DS_folder='./Left-above-downsampling/*'

for i, org in enumerate(glob.glob(DS_folder)):
    filename = org.split('_')
    print(filename)
    img = cv2.imread(org)
    resize_img = []
    for j, img_row in enumerate(img):
        resize_row = []
        if j % 2 != 0:
            continue
        for k, pixel in enumerate(img_row):
            if k % 2 == 0:
                resize_row.append(pixel)
        resize_img.append(resize_row)
    resize_img = np.array(resize_img)
    print(resize_img.shape)
    cv2.imwrite('{}_{}_{}_DS.png'.format(filename[0],filename[1],filename[2][:-4]),resize_img)