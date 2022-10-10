#!/bin/bash
mkdir -p iso/boot/grub
cat <<EOF > iso/boot/grub/grub.cfg
menuentry "QOS" {
	multiboot /boot/vmcl
}
EOF
cp bin/vmcl boot
grub-mkrescue -o bin/qos.iso iso