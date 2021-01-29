#!/bin/sh
#1.tmiv_cmake_install
unzip CMAKE-3.15.0.zip
cd CMAKE-3.15.0
./bootstrap && sudo make && sudo make install
