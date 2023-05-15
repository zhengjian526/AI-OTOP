#ifndef OTOP_SRC_RUNTIME_KERNEL_RUNTIME_H
#define OTOP_SRC_RUNTIME_KERNEL_RUNTIME_H
#include "kernel/kernel.h"
#include <chrono>
namespace otop {
class KernelRuntime
{
public:
    KernelRuntime() = default;
    ~KernelRuntime() = default;
    void SetKernel(Kernel* kernel);
    void Run(const InputList& inputs, OutputList& outputs, const Option& option);
private:
    Kernel* kernel_;
};


} // namespace otop
#endif // OTOP_SRC_RUNTIME_KERNEL_RUNTIME_H