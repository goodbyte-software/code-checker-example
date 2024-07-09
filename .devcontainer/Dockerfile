FROM ubuntu:22.04

ARG USER=developer
ARG UID=1000
ARG GID=1000
ARG PW=1234

# add user
SHELL ["/bin/bash", "-o", "pipefail", "-c"]
RUN useradd -m ${USER} --uid=${UID} && echo "${USER}:${PW}" | chpasswd

ENV TZ 'Europe/Warsaw'
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# Basic set of dev tools
RUN apt-get update --fix-missing && \
    apt-get install -y \
    git \
    cmake \
    build-essential \
    g++-12 \
    gcc-12 \
    gdb \
    zsh \
    sudo \
    vim \
    tree \
    clang \
    clang-format

RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-12 20 && \
    update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-12 20

# Zephyr dependencies
RUN apt-get install -y --no-install-recommends \
    ninja-build \
    gperf \
    ccache \
    dfu-util \
    device-tree-compiler \
    wget \
    python3-dev \
    python3-pip \
    python3-pyelftools \
    python3-setuptools \
    python3-tk \
    python3-wheel \
    xz-utils \
    file \
    gcc-multilib \
    g++-multilib \
    libsdl2-dev \
    libmagic1 \
    libstdc++6

# Finally we can install west
RUN pip install west codechecker

# Install Zephyr SDK
WORKDIR /opt
ENV ZEPHYR_SDK_INSTALL_DIR /opt/zephyr-sdk-0.16.8
RUN wget https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.16.8/zephyr-sdk-0.16.8_linux-x86_64.tar.xz \
    && tar xvf zephyr-sdk-0.16.8_linux-x86_64.tar.xz \
    && ${ZEPHYR_SDK_INSTALL_DIR}/setup.sh -h -t arm-zephyr-eabi\
    && ${ZEPHYR_SDK_INSTALL_DIR}/setup.sh -t x86_64-zephyr-elf \ 
    && rm zephyr-sdk-0.16.8_linux-x86_64.tar.xz

# Install clang-tidy
RUN apt install -y clang-tidy && \
    ln -sf /usr/bin/clang-apply-replacements-14 /usr/bin/clang-apply-replacements

RUN usermod -aG sudo ${USER}
USER ${UID}:${GID}
WORKDIR /home/${USER}
CMD [ "bash" ]
