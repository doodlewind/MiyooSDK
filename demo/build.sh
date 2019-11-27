#!/bin/sh
docker run -d --rm -v `pwd`:/home \
    miyoo_sdk \
    make
