obj-m := hello.o

KDIR ?= $(CURDIR)/kernel
OUT  ?= $(CURDIR)/out
ARCH ?= arm64

all:
	$(MAKE) -C $(KDIR) O=$(OUT) M=$(CURDIR) \
		ARCH=$(ARCH) CC=clang LD=ld.lld LLVM=1 modules

clean:
	$(MAKE) -C $(KDIR) O=$(OUT) M=$(CURDIR) clean
