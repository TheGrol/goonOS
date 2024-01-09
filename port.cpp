#include "port.h"

Port::Port(unsigned short portnum) {
    this->portnum = portnum;
}
Port::~Port() {
}

Port8Bit::Port8Bit(unsigned short portnum):Port(portnum) {
}

Port8Bit::~Port8Bit() {
}

void Port8Bit::Write(unsigned char data) {

    __asm__ volatile("outb %0, %l" : : "a" (data), "Nd" (portnum));

}

unsigned char Port8Bit::Read() {
    unsigned char result;
    __asm__ volatile("inb %l, %0" : "=a" (result) : "Nd" (portnum));
    return result;
}

Port8BitSlow::Port8BitSlow(unsigned short portnum):Port(portnum) {
}

Port8BitSlow::~Port8BitSlow() {
}

void Port8BitSlow::Write(unsigned char data) {

    __asm__ volatile("outb %0, %l\njmp lf\nl: jmp lf\nl:" : : "a" (data), "Nd" (portnum));
}

unsigned char Port8BitSlow::Read() {
    unsigned char result;
    __asm__ volatile("inb %l, %0" : "=a" (result) : "Nd" (portnum));
    return result;
}
Port16Bit::Port16Bit(unsigned short portnum):Port(portnum) {
}

Port16Bit::~Port16Bit() {
}

void Port16Bit::Write(unsigned short data) {

    __asm__ volatile("outw %0, %l" : : "a" (data), "Nd" (portnum));

}

unsigned short Port16Bit::Read() {
    unsigned short result;
    __asm__ volatile("inw %l, %0" : "=a" (result) : "Nd" (portnum));
    return result;
}
Port32Bit::Port32Bit(unsigned short portnum):Port(portnum) {
}

Port32Bit::~Port32Bit() {
}

void Port32Bit::Write(unsigned long data) {

    __asm__ volatile("outl %0, %l" : : "a" (data), "Nd" (portnum));

}

unsigned long Port32Bit::Read() {
    unsigned long result;
    __asm__ volatile("inl %l, %0" : "=a" (result) : "Nd" (portnum));
    return result;
}