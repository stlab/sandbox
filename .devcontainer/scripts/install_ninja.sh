#!/bin/bash

NINJA_VERSION=1.11.1
ZIP_FILE_NAME=ninja-linux.zip

# Remove installation from base image
apt-get remove -y ninja-build

# Install from GitHub - will work for x86 machines, not aarch64. So, build from source!
# Note Ninja does not vend Linux amd64 binaries: https://github.com/ninja-build/ninja/issues/2284
# wget https://github.com/ninja-build/ninja/releases/download/v${NINJA_VERSION}/${ZIP_FILE_NAME}
# unzip ${ZIP_FILE_NAME} -d /usr/bin

git clone https://github.com/ninja-build/ninja.git /ninja-build-src
cd /ninja-build-src
git checkout tags/v${NINJA_VERSION}
cmake -B build-cmake
cmake --build build-cmake
cp ./build-cmake/ninja /usr/bin/ninja
