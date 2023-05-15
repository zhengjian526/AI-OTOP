#ifndef OTOP_SRC_RUNTIME_KERNEL_RUNTIME_H
#define OTOP_SRC_RUNTIME_KERNEL_RUNTIME_H
namespace otop {
class KernelRuntime
{
public:
    KernelRuntime(/* args */);
    ~KernelRuntime();
    void SetKernel();
private:
    // Kernel* kernel_;
};


} // namespace otop
#endif // OTOP_SRC_RUNTIME_KERNEL_RUNTIME_H