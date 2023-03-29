#!/bin/bash

# Possible TODO: Install clang-tidy

wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key|sudo apt-key add - && \
apt-add-repository "deb http://apt.llvm.org/stretch/ llvm-toolchain-stretch main" && \
apt-get update && \
apt-get install -y clang-format
