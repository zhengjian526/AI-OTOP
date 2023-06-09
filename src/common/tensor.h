#ifndef OTOP_TENSOR_H
#define OTOP_TENSOR_H
#include "types.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
namespace otop {

using Shape = std::vector<uint64_t>;
struct TensorInfo
{
    Shape shape;
    DataType data_type;
    int64_t GetElemNum() const
    {
        return std::accumulate(shape.begin(), shape.end(), 1, std::multiplies<uint64_t>());
    }
    int64_t GetDataSize() const
    {
        return GetElemNum() * GetSizeOfDataType(data_type);
    }
    void PrintInfo()
    {
        std::cout << "shape: " << "[";
        for(const auto& ii : shape){
            std::cout << ii << " " ;
        }
        std::cout << "], date type: " << GetDataTypeStr(data_type) << std::endl;
        return;
    }
};


class Tensor
{
public:
    Tensor() = default;
    ~Tensor() = default;
    Tensor(void* addr, const TensorInfo& tensor_info) : addr_(addr), tensor_info_(tensor_info)
    {

    }
    int64_t GetElemNum() const
    {
        return tensor_info_.GetElemNum();
    }
    int64_t GetDataSize() const
    {
        return tensor_info_.GetDataSize();
    }
    int64_t GetDim(int32_t idx) const
    {
        return tensor_info_.shape[idx];
    }
    template <typename T = void>
    T* GetBufferPtr() const {
        return static_cast<T*>(addr_);
    }
    void SaveToFile(std::string file_name);
    bool FromFile(std::string file_name);
private:
    TensorInfo tensor_info_;
    void* addr_;
};



} // namespace otop
#endif // OTOP_TENSOR_H