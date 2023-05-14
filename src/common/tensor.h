#ifndef OTOP_TENSOR_H
#define OTOP_TENSOR_H
#include "types.h"
#include <iostream>
#include <vector>
namespace otop {

using Shape = std::vector<uint64_t>;
struct TensorInfo
{
    Shape shape;
    DataType data_type;
};

class Tensor
{
public:
    Tensor(/* args */);
    ~Tensor();
private:
    TensorInfo tensor_info_;
    void* addr_;

};



} // namespace otop
#endif // OTOP_TENSOR_H