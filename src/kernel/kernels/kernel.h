#ifndef OTOP_SRC_KERNEL_KERNEL_H
#define OTOP_SRC_KERNEL_KERNEL_H
#include "common/tensor.h"
#include "common/option.h"
namespace otop {
using InputList = std::vector<Tensor*>;
using OutputList = std::vector<Tensor*>;
class Kernel
{
public:
    Kernel() = default;
    virtual ~Kernel() = default;
    void Run(const InputList& inputs, OutputList& outputs, const Option& option)
    {
        if(option.simd_mode == Option::SimdMode::SSE) {
            RunSSE(inputs, outputs, option);
        }
        else if(option.simd_mode == Option::SimdMode::FMA) {
            RunFMA(inputs, outputs, option);
        }
        else { 
            RunNative(inputs, outputs, option);
        }
        return;
    }
private:
    virtual void RunNative(const InputList& inputs, OutputList& outputs, const Option& option) = 0;
    virtual void RunSSE(const InputList& inputs, OutputList& outputs, const Option& option) = 0;
    virtual void RunFMA(const InputList& inputs, OutputList& outputs, const Option& option) = 0;
};


} // namespace otop
#endif // OTOP_SRC_KERNEL_KERNEL_H