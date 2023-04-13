#!/bin/bash

# Remove default clang (11) in image
apt-get remove -y clang

# Install latest available clang
# "all" is a little much for our container, including LLVM and a bunch of stuff we probably don't need.
# May want to revisit for a slimmer image, but this is sufficient for now.
# bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)" "16 all"
wget https://apt.llvm.org/llvm.sh
chmod +x ./llvm.sh
./llvm.sh 16 all
