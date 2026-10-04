#include <cstdint>
#include <iostream>
#include "openFile.h"
// 4kb оперативки
uint8_t memory[4096] = {0};

void copyBufferToMemory(){
    // проверка, помещается ли rom в оставшуюся память
    if (buffer.size() > (4096-0x200)){
        std::cerr << "ROM is too big!" << std::endl;
    } else {
        std::copy(buffer.begin(), buffer.end(), memory+0x200)
    }
}