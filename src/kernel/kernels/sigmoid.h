#ifndef OTOP_KERNEL_SIGMOID_H
#define OTOP_KERNEL_SIGMOID_H
#include "kernel/kernels/kernel.h"
#include "common/attr.h"
#include "common/config.h"
namespace otop {

class SigmoidKernel : public Kernel
{
public:
    SigmoidKernel(/* args */) = default;
    ~SigmoidKernel() = default;
    void SetAttr(const SigmoidAttr& attr);
private:
    void RunNative(const InputList& inputs, OutputList& outputs, const Option& option);
    void RunSSE(const InputList& inputs, OutputList& outputs, const Option& option);
    void RunFMA(const InputList& inputs, OutputList& outputs, const Option& option);
private:
    SigmoidAttr attr_;
};




} //namespace otop


#endif // OTOP_KERNEL_SIGMOID_H