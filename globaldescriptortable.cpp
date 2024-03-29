#include "globaldescriptortable.h"

GlobalDescriptorTable::GlobalDescriptorTable()
: nullSegmentSelector(0,0,0),
unusedSegmentSelector(0,0,0),
codeSegmentSelector(0, 64*1024*1024, 0x9A),
dataSegmentSelector(0, 64*1024*1024, 0x92) {

    unsigned long i[2];
    i[0] = (unsigned long)this;
    i[1] = sizeof(GlobalDescriptorTable) << 16;

    asm volatile("lgdt (%0)" : :"p" (((unsigned char *)i) + 2));
}

GlobalDescriptorTable::~GlobalDescriptorTable() {

}

unsigned short GlobalDescriptorTable::DataSegmentSelector() {
    return (unsigned char*)&dataSegmentSelector - (unsigned char*)this;
}
unsigned short GlobalDescriptorTable::CodeSegmentSelector() {
    return (unsigned char*)&codeSegmentSelector - (unsigned char*)this;
}

GlobalDescriptorTable::SegmentDescriptor::SegmentDescriptor(unsigned long base, unsigned long limit, unsigned char flags) {
    unsigned char* target = (unsigned char*)this;
    if (limit <= 65536) target[6] = 0x40;
    else {
        limit = ((limit & 0xFFF) != 0xFFF) ? limit = (limit >> 12)-1 : limit = limit >> 12;
        target[6] = 0xC0;
    }
    target[0] = limit & 0xFF;
    target[1] = (limit >> 8) & 0xFF;
    target[6] |= (limit >> 16) & 0xF;

    target[2] = base & 0xFF;
    target[3] = (base >> 8) & 0xFF;
    target[4] = (base >> 16) & 0xFF;
    target[7] = (base >> 24) & 0xFF;

    target[5] = flags;
}

unsigned long GlobalDescriptorTable::SegmentDescriptor::Base() {
    unsigned char* target = (unsigned char*)this;
    unsigned long result = target[7];
    result = (result << 8) + target[4];
    result = (result << 8) + target[3];
    result = (result << 8) + target[2];

    return result;
}

unsigned long GlobalDescriptorTable::SegmentDescriptor::Limit() {
    unsigned char* target = (unsigned char*)this;
    unsigned long result = target[6] & 0xF;
    result = (result << 8) + target[1];
    result = (result << 8) + target[0];
    if ((target[6] & 0xC0) == 0xC0)    result = (result << 12) | 0xFFF;

    return result;
}