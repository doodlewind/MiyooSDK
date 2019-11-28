FROM debian:9
ADD toolchain.tar.gz /opt
ENV PATH="${PATH}:/opt/miyoo/bin"
RUN apt-get update && apt-get install -y build-essential \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /root
VOLUME /root
