obj-m := kernel_module.o 
#above .o file will be created after the compilation of .c file

KDIR =/lib/modules/$(shell uname -r)/build #path of generic Makefile,$(shell uname -r) is to get the version of kernal, that name is a folder in the make filepath

all:
	make -C $(KDIR) M=$(shell pwd) modules

clean:
	make -C $(KDIR) M=$(shell pwd) CLEAN

