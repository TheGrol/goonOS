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
    asm volatile("outb %0, %1" : : "a" (data), "Nd" (portnum));
}

unsigned char Port8Bit::Read() {
    unsigned char result;
    asm volatile("inb %1, %0" : "=a" (result) : "Nd" (portnum));
    return result;
}

Port16Bit::Port16Bit(unsigned short portnum):Port(portnum) {
}

Port16Bit::~Port16Bit() {
}

void Port16Bit::Write(unsigned short data) {
    asm volatile("outw %0, %1" : : "a" (data), "Nd" (portnum));
}

unsigned short Port16Bit::Read() {
    unsigned short result;
    asm volatile("inw %1, %0" : "=a" (result) : "Nd" (portnum));
    return result;
}
Port32Bit::Port32Bit(unsigned short portnum):Port(portnum) {
}

Port32Bit::~Port32Bit() {
}

void Port32Bit::Write(unsigned long data) {
    asm volatile("outl %0, %1" : : "a" (data), "Nd" (portnum));
}

unsigned long Port32Bit::Read() {
    unsigned long result;
    asm volatile("inl %1, %0" : "=a" (result) : "Nd" (portnum));
    return result;
}