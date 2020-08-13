import numpy as np
import pandas as pd
from PIL import Image
from glob import glob
import cv2
import shutil
import os

infolder='./bicubic-downsampling'

def convert_bicubic():
    # 깃허브에서 최적화된 모델을 사용.
    # 416x240, 832x480, DCSCNDATA(원본YUV) -> test_yuv_png.sh -> PNG
    # 원본PNG 는 DCSCNORG
    # 테스트PNG 는 DCSCNPNG(infloder) 로

    # bicubicPNG
    for i, name in enumerate(sorted(glob(infolder+'/*'))):
        file = name.split('_')
        print(file)
        file[2] = file[2][:-4]
        bi_target = Image.open(name)
        size = file[1].split('x')
        print((int((float(size[0]) / 2)), int((float(size[1]) / 2))))
        out = bi_target.resize((int((float(size[0]) / 2)), int((float(size[1]) / 2))),3)
        out.save("{}_{}_{}_bi.png".format(file[0],file[1],file[2]))

    # bicubicPNG에서 파일 테스트
def load_image(name):
    try:
        image = np.atleast_3d()
def normal_png_convert_bicubic():

    # for i, name in enumerate(glob(infolder+'/*')):
    #     bi_target = Image.open(name)
    #     name = name[:-4]
    #     size_x = np.array(bi_target).shape[0]
    #     size_y = np.array(bi_target).shape[1]
    #     print((int((float(size_x) / 2)), int((float(size_y) / 2))))
    #     out = bi_target.resize((int((float(size_y) / 2)), int((float(size_x) / 2))),3)
    #     out.save("{}_{}x{}_bi.png".format(name,int((float(size_y) / 2)),int((float(size_x) / 2))))

    for i, name in enumerate(glob(infolder + '/*')):
        image = Image.open(load_image(name))
        name = name[:-4]


        width, height = image.shape[1], image.shape[0]
        new_width = int(width * 0.5)
        new_height = int(height * 0.5)
        method = Image.BICUBIC


        if len(image.shape) == 3 and image.shape[2] == 3:
            image = Image.fromarray(image, "RGB")
            image = image.resize([new_width, new_height], resample=method)
            image = np.asarray(image)
        elif len(image.shape) == 3 and image.shape[2] == 4:
            # the image may has an alpha channel
            image = Image.fromarray(image, "RGB")
            image = image.resize([new_width, new_height], resample=method)
            image = np.asarray(image)
        else:
            image = Image.fromarray(image.reshape(height, width))
            image = image.resize([new_width, new_height], resample=method)
            image = np.asarray(image)
            image = image.reshape(new_height, new_width, 1)




def shutil_move():
    for i, name in enumerate(glob(infolder + '/*')):
        image = Image.open(name)
        size_x = np.array(image).shape[0]
        size_y = np.array(image).shape[1]
        shutil.move(name,name[:-4]+"_{}x{}_org.png".format(size_y,size_x))

def main():
    #convert_bicubic()
    #normal_png_convert_bicubic()
    shutil_move()

if __name__ == "__main__":
    main()