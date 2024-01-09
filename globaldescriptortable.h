#ifndef __GDT_H
#define __GDT_H

#include "types.h"

class GlobalDescriptorTable {
    public:
        class SegmentDescriptor {
            private:
                unsigned short limit_lo;
                unsigned short base_lo;
                unsigned char base_hi;
                unsigned char type;
                unsigned char flags_limit_hi;
                unsigned char base_vhi;
            public:
                SegmentDescriptor(unsigned long base, unsigned long limit, unsigned char type);
                unsigned long Base();
                unsigned long Limit();
        } __attribute__((packed));

    SegmentDescriptor nullSegmentSelector;
    SegmentDescriptor unusedSegmentSelector;
    SegmentDescriptor codeSegmentSelector;
    SegmentDescriptor dataSegmentSelector;
        
public:
    GlobalDescriptorTable();
    ~GlobalDescriptorTable();

    unsigned short CodeSegmentSelector();
    unsigned short DataSegmentSelector();
};

#endif