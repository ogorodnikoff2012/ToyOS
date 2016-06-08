all: kernel floppy

kernel:
	$(MAKE) -C src

floppy:
	./update_image.sh

run:
	VirtualBox --startvm ToyOS

clean:
	$(MAKE) -C src clean
