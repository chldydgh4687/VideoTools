#!/bin/sh

sudo apt-get remove -y clang-tidy
sudo apt-get remove -y clang
sudo apt-get remove -y clang++

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

#remove alternatives order
#sudo update-alternatives --remove-all gcc
