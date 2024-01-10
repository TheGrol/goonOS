GPPPARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore
ASPARAMS = --32
LDPARAMS = -melf_i386

objects = loader.o globaldescriptortable.o port.o interruptstubs.o interrupts.o kernel.o

%.o: %.cpp
	gcc $(GCCPARAMS) -c -o $@ $<

%.o: %.s
	as $(ASPARAMS) -o $@ $<

goonOS.bin: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

install: goonOS.bin
	sudo cp $< /boot/goonOS.bin

goonOS.iso: goonOS.bin
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp goonOS.bin iso/boot/goonOS.bin
	echo 'set timeout=0' >> iso/boot/grub/grub.cfg
	echo 'set default=0' >> iso/boot/grub/grub.cfg
	echo '' >> iso/boot/grub/grub.cfg
	echo 'menuentry "goonOS" {' >> iso/boot/grub/grub.cfg
	echo ' multiboot /boot/goonOS.bin' >> iso/boot/grub/grub.cfg
	echo ' boot' >> iso/boot/grub/grub.cfg
	echo '}' >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=$@ iso
	rm -rf iso

run: goonOS.iso
	(killallVirtualBox && sleep 1) || true
	VirtualBoxVM --startvm "help" & 

clean:
	rm -f $(objects) goonOS.bin goonOS.iso
