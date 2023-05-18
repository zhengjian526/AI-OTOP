#include "config.h"
#include "tensor.h"
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
namespace otop {
inline void DumpData(std::string path, void* addr, int size){
    std::ofstream fout(path.c_str(),std::ios_base::out | std::ios_base::binary);
    fout.write((char*)(addr),size);
    fout.close();
    return;
}
void Tensor::SaveToFile(std::string file_name)
{
    if(access(RES_DATA, F_OK) == -1){
        mkdir(RES_DATA,0755);
    }
    std::string path = RES_DATA + file_name + ".bin";
    std::cout << path << std::endl;
    DumpData(path, addr_, GetDataSize());
    return;
}
bool Tensor::FromFile(std::string file_name)
{
    CHECK_NOTNULL(addr_);
    std::ifstream fin(file_name.c_str(), std::ios_base::in | std::ios_base::binary);
    if (fin.is_open() && !fin.eof()) {
        if(fin.read((char*)addr_, GetDataSize())) {
            std::cout << file_name << " read successfully\n";
        }
        fin.close();
        return true;
    }
    else {
        std::cout << file_name << " read failed\n";
        return false;
    }
    return false;
}

} // namespace otop