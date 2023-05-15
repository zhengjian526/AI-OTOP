#ifndef OTOP_KERNEL_SIGMOID_H
#define OTOP_KERNEL_SIGMOID_H
#include "kernel/kernel.h"
#include "common/attr.h"
namespace otop {

class SigmoidKernel : public Kernel
{
public:
    SigmoidKernel(/* args */) = default;
    ~SigmoidKernel() = default;
    void SetAttr(const SigmoidAttr& attr);
    void Run(InputList inputs, OutputList outputs, const Option& option) override;
private:
    SigmoidAttr attr_;
};




} //namespace otop


#endif // OTOP_KERNEL_SIGMOID_H