#ifndef __INTERRUPTS_H
#define __INTERRUPTS_H
#include "types.h"
#include "port.h"

    class InterruptManager
    {
        public:
        static unsigned long handleInterrupt(unsigned char interruptNumber, unsigned long esp);
    };

    #endif