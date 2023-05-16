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

} // namespace otop