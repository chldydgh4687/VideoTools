# VideoTools
자주쓰는 비디오 코드 & 툴 ( in ubuntu 18.04 )

# FFMPEG
```sh
$sudo apt update
$sudo apt install ffmpeg
$ffmpeg -version
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

# TMIV 7.1v(To Immersive Video Coding)
- https://gitlab.com/mpeg-i-visual/tmiv/-/tree/v7.1#building-and-installing-tmiv

# RTX 3090 CUDA 설치 ( in Windows10 )
- https://n1094.tistory.com/42 ( cuda 설치 방법 )
- https://koos808.tistory.com/41 ( cuda 버전, tf-nightly-gpu 버전, pytorch )
