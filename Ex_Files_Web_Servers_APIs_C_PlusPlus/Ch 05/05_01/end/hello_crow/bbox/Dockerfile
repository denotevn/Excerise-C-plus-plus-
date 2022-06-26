FROM gcc:7.3.0

RUN apt-get -qq update
RUN apt-get -qq upgrade
RUN apt-get -qq install cmake

RUN apt-get -qq install libboost-all-dev=1.62.0.1
RUN apt-get -qq install build-essential libtcmalloc-minimal4 && \
  ln -s /usr/lib/libtcmalloc_minimal.so.4 /usr/lib/libtcmalloc_minimal.so

WORKDIR /usr/src

RUN git clone https://github.com/mongodb/mongo-c-driver.git \
&& cd mongo-c-driver && git checkout 1.10.1 \
&& mkdir cmake-build && cd cmake-build \
&& cmake -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF .. \
&& make && make install && ldconfig /usr/local/lib

RUN git clone https://github.com/mongodb/mongo-cxx-driver.git \
--branch releases/stable --depth 1 \
&& cd mongo-cxx-driver/build && cmake \
-DBSONCXX_POLY_USE_MNMLSTC=1 \
-DCMAKE_BUILD_TYPE=Release \
-DCMAKE_INSTALL_PREFIX=/usr/local \
-DLIBMONGOC_DIR=/usr/lib/x86_64-linux-gnu \
-DLIBBSON_DIR=/usr/lib/x86_64-linux-gnu \
-DCMAKE_MODULE_PATH=/usr/src/mongo-cxx-driver-r3.0.3/cmake .. \
&& make EP_mnmlstc_core && make && make install && ldconfig /usr/local/lib
