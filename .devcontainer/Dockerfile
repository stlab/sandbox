# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.195.0/containers/cpp/.devcontainer/base.Dockerfile
# [Choice] Debian / Ubuntu version (use Debian 11/9, Ubuntu 18.04/21.04 on local arm64/Apple Silicon): debian-11, debian-10, debian-9, ubuntu-21.04, ubuntu-20.04, ubuntu-18.04
ARG VARIANT=debian-11
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

RUN apt-get update && apt-get install -y software-properties-common

WORKDIR /sandbox-setup-scripts

# ADD & RUN one file at a time for more efficient layer caching.
ADD ./scripts/install_cmake.sh .
RUN ./install_cmake.sh

ADD ./scripts/install_clang_tooling.sh .
RUN ./install_clang_tooling.sh

ADD ./scripts/install_ninja.sh .
RUN ./install_ninja.sh
