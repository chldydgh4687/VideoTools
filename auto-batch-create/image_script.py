from glob import glob
import os
import PIL
def auto_sequence_create(filepath,savepath):
    with open("test-loop.bat", "w") as f1:
        for i, name in enumerate(sorted(glob(filepath+"/*"))):
            path = os.getcwd()
            f = name.split('.')
            file_name = f[1][10:]
            print(file_name)
            #
            print("for %%i IN (22,32) do call test_img.bat\t\t{}\t\t{}x{}\t\t%%i\t30\n".format(file_name, 481, 321))
            data="for %%i IN (22,32) do call test_img.bat\t\t{}\t\t{}x{}\t\t%%i\t30\n".format(file_name, 481, 321)
            f1.write(data)

            with open(savepath+file_name+".cfg","w") as f2:
                f2.writelines("#======== File I/O ===============\n")
                f2.writelines("InputFile                     : {}\{}\n".format(path,name[2:]))
                f2.writelines("InputBitDepth                 : 8           # Input bitdepth\n")
                f2.writelines("InputChromaFormat             : 420         # Ratio of luminance to chrominance samples\n")
                f2.writelines("FrameRate                     : 30          # Frame Rate per second\n")
                f2.writelines("FrameSkip                     : 0           # Number of frames to be skipped in input\n")
                f2.writelines("SourceWidth                   : 481         # Input  frame width\n")
                f2.writelines("SourceHeight                  : 321         # Input  frame height\n")
                f2.writelines("FramesToBeEncoded             : 1         # Number of frames to be coded\n")
                f2.write("\n")
                f2.writelines("Level                         : 2\n")
            f2.close

        f1.close


def main():
    yuv_data='./yuvimage'
    save_sequence='./sequence/'
    auto_sequence_create(yuv_data,save_sequence)

if __name__ == "__main__":
    main()