import numpy as np
import pandas as pd
from PIL import Image
from glob import glob
import cv2
import shutil
import os

outfolder='./psnrsub/*'
targetfolder='./psnrtarget/*'

#형식 : 이름_크기_qp.png

def psnr():
    pandas_list = []
    for i, org in enumerate(sorted(glob(targetfolder))):
        org_file = org.split('_')
        print(org_file)
        org_file[2] = org_file[2][:-4]
        org_file[0] = org_file[0][13:]
        target_name = org_file[0]
        print(target_name)
        for j, name in enumerate(sorted(glob(outfolder))):
            print(name)
            file = name.split('_')
            file[2] = file[2][:-4]
            file[0] = file[0][12:]
            qp_name = file[0]

            if target_name == qp_name:
                seq_list = []
                target_img = cv2.imread(org)
                qp_img = cv2.imread(name)
                psnr = cv2.PSNR(target_img, qp_img)
                print(target_name, file[1], file[2], psnr)
                seq_list.append(file[0])
                seq_list.append(file[2])
                seq_list.append(psnr)

def main():
    psnr()

if __name__ == "__main__":
    main()