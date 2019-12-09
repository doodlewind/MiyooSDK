FROM debian:9
ADD toolchain.tar.gz /opt
ENV PATH="${PATH}:/opt/miyoo/bin"
ENV ARCH="arm"
ENV CROSS_COMPILE="arm-miyoo-linux-uclibcgnueabi-"
RUN apt-get update && apt-get install -y \
    build-essential bc libssl-dev \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /root
