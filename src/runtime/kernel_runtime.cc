#include "runtime/kernel_runtime.h"

namespace otop {
void KernelRuntime::SetKernel(Kernel* kernel)
{
    kernel_ = kernel;
    return;
}

void KernelRuntime::Run(const InputList& inputs, OutputList& outputs, const Option& option)
{
    std::string simd_mode;
    if(option.simd_mode == Option::SimdMode::NATIVE) {
        simd_mode = "SimdMode::NATIVE";
    }
    else if (option.simd_mode == Option::SimdMode::SSE) {
        simd_mode = "SimdMode::SSE";
    }
    else {
        simd_mode = "SimdMode::FMA";
    }
    std::cout << "======> Run " << simd_mode << std::endl;

    auto run_begin_ts = std::chrono::system_clock::now();

    kernel_->Run(inputs, outputs, option);
    
    auto run_end_ts = std::chrono::system_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(run_end_ts - run_begin_ts);
    std::cout << "Run() costs: " << (float)diff.count() / 1000 << " ms." << std::endl;

    return;
}
} //namespace otop
