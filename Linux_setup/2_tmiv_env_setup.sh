#!/bin/sh
#2.tmiv_env_setup 
sudo apt-get remove -y clang-tidy
sudo apt-get remove -y clang
sudo apt-get remove -y clang++

sudo apt install -y git
sudo apt-get install -y clang-tidy-10

sudo update-alternatives --install /usr/bin/clang clang /usr/bin/clang-10 10
sudo update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-10 10
sudo update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-10 10

sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt update
sudo apt install -y gcc-9
sudo apt install -y g++-9
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 10
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 10

unzip Catch2-2.11.1.zip
unzip fmt-7.0.3.zip
unzip HM-16.16.zip
unzip tmiv-v7.1.zip 

mv ./tmiv-v7.1 ./tmiv

mkdir ./tmiv_build
mkdir ./tmiv_install
#remove alternatives order
#sudo update-alternatives --remove-all gcc
