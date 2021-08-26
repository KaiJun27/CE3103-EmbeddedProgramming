#obj-m := hello_lkm.o
obj-m := gpio_lkm.o

all:
	make -C /usr/src/linux-headers-`uname -r` M=`pwd` modules

clean:
	make -C /usr/src/linux-headers-`uname -r` M=`pwd` clean
