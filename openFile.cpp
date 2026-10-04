#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdint>

void openROM(){
    std::string filename = "octojam1title.ch8";
    // std::cout<<"Enter ROM name:"<<std::endl;
    // std::cin>>filename;

    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if(!file.is_open()){
        std::cerr<<"File is not opened:"<< filename << std::endl;
    }

    std::streamsize size = file.tellg();
    std::cout<<size<<std::endl;

    // возвращаем указатель в начало файла для чтения
    file.seekg(0, std::ios::beg);

    std::vector<uint8_t> buffer(size);

    if (file.read(reinterpret_cast<char*>(buffer.data()), size)) {
        std::cout<< "Bytes readed:" << size << std::endl;
    } else {
        std::cerr << "Error happened while trying to read the file!" << std::endl;
    }
}