# pico-dual-core
Dual Core Programming on the Raspberry Pi Pico.

* [tutorial video](https://youtu.be/7h6mTR0oNcg)
* [Pico SDK github](https://github.com/raspberrypi/pico-sdk)

# 1. Setup
```sh
$ cd ~/workspace_arm

$ git clone git@github.com:raspberrypi/pico-sdk.git --depth 1
$ cd pico-sdk
$ git submodule update --init
$ cd ..

$ mkdir pico-dual-core
$ cd pico-dual-core/

# import pico sdk
$ cp ~/workspace_arm/pico-sdk/external/pico_sdk_import.cmake ./
$ export PICO_SDK_PATH=~/workspace_arm/pico-sdk

# Build
$ mkdir build
$ cd build/
/build$ cmake ..
/build$ make
/build$ ll
total 584
drwxr-xr-x 7 ryan ryan   4096 Sep 23 23:18 ./
drwxr-xr-x 3 ryan ryan   4096 Sep 23 23:17 ../
-rw-r--r-- 1 ryan ryan  18605 Sep 23 23:17 CMakeCache.txt
drwxr-xr-x 5 ryan ryan   4096 Sep 23 23:18 CMakeFiles/
-rw-r--r-- 1 ryan ryan  84124 Sep 23 23:17 Makefile
-rw-r--r-- 1 ryan ryan   1580 Sep 23 23:17 cmake_install.cmake
drwxr-xr-x 6 ryan ryan   4096 Sep 23 23:18 elf2uf2/
drwxr-xr-x 3 ryan ryan   4096 Sep 23 23:17 generated/
-rwxr-xr-x 1 ryan ryan   8760 Sep 23 23:18 multi.bin*
-rw-r--r-- 1 ryan ryan 160903 Sep 23 23:18 multi.dis
-rwxr-xr-x 1 ryan ryan  44016 Sep 23 23:18 multi.elf*
-rw-r--r-- 1 ryan ryan 188275 Sep 23 23:18 multi.elf.map
-rw-r--r-- 1 ryan ryan  24708 Sep 23 23:18 multi.hex
-rw-r--r-- 1 ryan ryan  17920 Sep 23 23:18 multi.uf2
drwxr-xr-x 6 ryan ryan   4096 Sep 23 23:17 pico-sdk/
drwxr-xr-x 3 ryan ryan   4096 Sep 23 23:18 pioasm/

/build$ cp multi.uf2 /media/user/RPI-RP2/

/build$ arm-linux-gnueabi-objdump -d -S ./multi.elf > multi.lst
/build$ cp multi.lst ../

```
