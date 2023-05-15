#ifndef OTOP_SRC_KERNEL_KERNEL_H
#define OTOP_SRC_KERNEL_KERNEL_H
#include "common/tensor.h"
#include "common/option.h"
namespace otop {
using InputList = std::vector<Tensor>;
using OutputList = std::vector<Tensor>;
class Kernel
{
public:
    Kernel() = default;
    virtual ~Kernel() = default;
    virtual void Run(InputList inputs, OutputList outputs, const Option& option) = 0;
private:

};


} // namespace otop
#endif // OTOP_SRC_KERNEL_KERNEL_H