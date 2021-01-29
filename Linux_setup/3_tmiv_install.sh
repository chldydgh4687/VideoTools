#!/bin/sh
#3.tmiv_install
cd tmiv_build

cmake -DCMAKE_INSTALL_PREFIX=../tmiv_install -DCMAKE_BUILD_TYPE=Release ../tmiv
cmake --build . --parallel --config Release
cmake --build . --parallel --config Release --target install
