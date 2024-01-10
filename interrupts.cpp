#include "interrupts.h"

void printf(char* str);

unsigned long InterruptManager::handleInterrupt(uint8_t interruptNumber, unsigned long esp)
{

    printf(" INTERRUPT");
    
    return esp;
}