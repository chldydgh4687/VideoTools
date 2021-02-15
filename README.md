# VideoTools
frequently used video code & tools ( in ubuntu 18.04 )
자주쓰는 비디오 코드 & 툴 ( in ubuntu 18.04 )

# FFMPEG
- Linux_install
```sh
$sudo apt update
$sudo apt install ffmpeg
$ffmpeg -version
```
- Windows_install
https://blog.naver.com/chandong83/222095346417
``` 
Simply Description
WindowsDownload >> .dev link >> .7z file download >> zip in C:\ >> environment path edit
```

```sh
png files >> mp4 ( lossless )
png파일들 > 영상 ( lossless )
ffmpeg -i input%05d.png -v:c libx265 -crf 0 -f 30 -preset veryslow -pixel_format yuv420p8le output.mp4

파일 시작번호가 100부터 진행될 경우
png files ( 100 ~ ) >> mp4 
ffmpeg -start_number 100 -i input%05d.png -v:c libx265 -crf 0 -f 30 -preset veryslow -pixel_format yuv420p8le output.mp4

mp4 >> yuv (작업 운영체제가 일치하지 않으면 영상이 깨짐)
ffmpeg -i output.mp4 -q 0 output.yuv

png >> yuv
ffmpeg -i input.png -pix_fmt yuv420p output.yuv 

yuv >> png
ffmpeg -f rawvideo -s 1920x1080 -i input.yuv -f image2 -vcodec png output.png 
```


# YUView
- 리눅스에서 yuv 보여주는 view
- https://flathub.org/apps/details/de.rwth_aachen.ient.YUView
```sh
#flatpak (like ubuntu app center) 
$sudo apt install flatpak
$sudo apt install gnome-software-plugin-flatpak
$sudo flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo

#해당 YUView링크에서 flatpak 파일을 다운로드
$flatpak install $파일명 --user

#Run
$flatpak run de.rwth_aachen.ient.YUView
```

---

# TMIV 7.1v(To Immersive Video Coding)
- Windows : Visual_Studio 2019 / CMake 3.15 / 
- Linux : Clang-tidy-10 / gcc-9 / g++-9 /
- https://gitlab.com/mpeg-i-visual/tmiv/-/tree/v7.1#building-and-installing-tmiv

# TMIV 8.0v
- Windows : Visual_Studio 2019 / CMake 3.15 / 
- Linux : Clang-tidy-10 / gcc-9 / g++-9 /
- VVCENC/DEC 추가 - issues make_error 에서 설명

|tool name| |Location|Release|
|---|---|---|---|
|TMIV|[N0050]|https://gitlab.com/mpeg-i-visual/tmiv|v8.0|
|VVenC| |https://github.com/fraunhoferhhi/vvenc/tree/v0.2.0.0|v0.2.0.0|
|VVdeC| |https://github.com/fraunhoferhhi/vvdec/tree/v0.2.0.0|v0.2.0.0|
|VMAF|[VMAF]|https://github.com/Netflix/vmaf|v1.3.14|
|IV-PSNR|[N 0013]|https://gitlab.com/mpeg-i-visual/ivpsnr|v3.0|
|IVDE|[N 0058]|https://gitlab.com/mpeg-i-visual/ivde|v3.0|

---

# RTX 3090 CUDA 설치 ( in Windows10 )
- https://n1094.tistory.com/42 ( cuda 설치 방법 )
- https://koos808.tistory.com/41 ( cuda 버전, tf-nightly-gpu 버전, pytorch )
