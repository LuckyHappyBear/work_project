obj-m:=globalmem.o
KERNELDIR:=/lib/modules/$(shell uname -r)/build
default:
	make -C $(KERNELDIR) M=$(shell pwd) modules
install:
	insmod globalmem.ko
uninstall:
	rmmod globalmem.ko
clean:
	make -C $(KERNELDIR) M=$(shell pwd) clean
