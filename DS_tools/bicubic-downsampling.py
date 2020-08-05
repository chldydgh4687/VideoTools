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

def main():
    convert_bicubic()
if __name__ == "__main__":
    main()