#!/bin/bash

CMAKE_VERSION=3.26.3

apt-get update && \
apt-get -y install build-essential && \
apt-get install -y wget && \
rm -rf /var/lib/apt/lists/* && \
wget https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}-linux-$(uname -m).sh -q -O /tmp/cmake-install.sh && \
chmod u+x /tmp/cmake-install.sh && \
mkdir /opt/cmake-${CMAKE_VERSION} && \
/tmp/cmake-install.sh --skip-license --prefix=/opt/cmake-${CMAKE_VERSION} && \
rm /tmp/cmake-install.sh && \
ln -s /opt/cmake-${CMAKE_VERSION}/bin/* /usr/local/bin
