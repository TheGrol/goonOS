#include "interrupts.h"

void printf(char* str);

unsigned long InterruptManager::handleInterrupt(unsigned char interruptNumber, unsigned long esp)
{

    printf(" INTERRUPT");
    
    return esp;
}