# Addon to connect with mongoDB server

## ** Linux ** 

## Prerequisites

**mongo driver installation** 

### Install mongo-c 

http://mongoc.org/libmongoc/current/installing.html 
    version: 1.12.0
    built on Debian 4.9.110-1

according to "Build from tarball" instructions:
```shell
$ wget https://github.com/mongodb/mongo-c-driver/releases/download/1.12.0/mongo-c-driver-1.12.0.tar.gz
$ tar xzf mongo-c-driver-1.12.0.tar.gz
$ cd mongo-c-driver-1.12.0
$ mkdir cmake-build
$ cd cmake-build
```
build command for static libraries: 
```shell
$ cmake -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF -DCMAKE_BUILD_TYPE=Release -DENABLE_STATIC=ON ..
$ make
$ sudo make install
```
### Install mongocxx

https://mongodb.github.io/mongo-cxx-driver/mongocxx-v3/installation/

    version: 3.2.x
    built on Debian 4.9.110-1

according to instructions:
```shell
$ git clone https://github.com/mongodb/mongo-cxx-driver.git \
    --branch releases/stable --depth 1
$ cd mongo-cxx-driver/build
```
build command for static libraries: 
```shell
$ cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local -DBUILD_SHARED_LIBS=OFF ..
$ sudo make EP_mnmlstc_core
$ make
$ sudo make install
```

/usr/local/include/* headers and /usr/local/lib/* static libraries are linked through the ADDON_PKG_CONFIG_LIBRARIES directive (addon_config.mk)

## ** OSX ** 

## Prerequisites

### Build Cyrus
https://cyrusimap.org/sasl/sasl/installation.html#quick-install-guide

```shell
cd (directory it was untarred into)
./configure
make
sudo make install
```

### XCODE Project

Use projectGenerator adding ofxMongo.

Add Cyrus SASL framework to XCODE project:
General>Linked Frameworks and Libraries
add libsasl2.tbd

Add resolv
General>Linked Frameworks and Libraries
add libresolv.9.tbd

You should already see headers included in Build Settings>Header Search Paths as
../../../addons/ofxMongo/src
../../../addons/ofxMongo/include

**mongo driver installation** 

The headers included in this addon were copied from:

/usr/local/include/bsoncxx/v_noabi/bsoncxx

/usr/local/include/mongocxx/v_noabi/mongocxx

/usr/local/include/libbson-1.0

/usr/local/include/libmongoc-1.0

and

/usr/local/opt/openssl/include/openssl

The static libraries included in this addon were copied from:

/usr/local/lib/

and

/usr/local/opt/openssl/lib/libcrypto.a
/usr/local/opt/openssl/lib/libssl.a

If you need/want to build your own libraries, follow steps below then copy the files from OS into the addon.

### Install mongo-c 

http://mongoc.org/libmongoc/current/installing.html

    version: 1.12.0

according to "Building on Mac OS X" instructions,
install XCode CLI 
```shell
$ xcode-select --install
```
install Homebrew

https://brew.sh/

install cmake:
```shell
$ brew install cmake
```

Download and build:
```shell
$ curl -LO https://github.com/mongodb/mongo-c-driver/releases/download/1.12.0/mongo-c-driver-1.12.0.tar.gz
$ tar xzf mongo-c-driver-1.12.0.tar.gz
$ cd mongo-c-driver-1.12.0
$ mkdir cmake-build
$ cd cmake-build
```
build command for static libraries: 
```shell
$ cmake -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF -DCMAKE_BUILD_TYPE=Release -DENABLE_STATIC=ON ..
$ make
$ sudo make install
```
### Install mongocxx

https://mongodb.github.io/mongo-cxx-driver/mongocxx-v3/installation/

    version: 3.2.x

according to instructions:
```shell
$ git clone https://github.com/mongodb/mongo-cxx-driver.git \
    --branch releases/stable --depth 1
$ cd mongo-cxx-driver/build
```
build command for static libraries: 
```shell
$ cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local -DBUILD_SHARED_LIBS=OFF ..
$ sudo make EP_mnmlstc_core
$ make
$ sudo make install
```