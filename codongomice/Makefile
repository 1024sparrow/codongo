obj-m += virmouse.o

KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD  := $(shell pwd)
INCLUDE := -isystem /lib/modules/`uname -r`/build/include

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
clean:
	@rm -fr *.ko *.o
