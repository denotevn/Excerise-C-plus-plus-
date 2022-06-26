FROM debian:stretch

RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get -y install cmake

RUN apt-get -y install libboost-all-dev
RUN apt-get -qq install build-essential libtcmalloc-minimal4 && \
  ln -s /usr/lib/libtcmalloc_minimal.so.4 /usr/lib/libtcmalloc_minimal.so


