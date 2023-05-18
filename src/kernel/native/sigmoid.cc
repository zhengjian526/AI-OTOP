#include "kernel/kernels/sigmoid.h"
#include <math.h>
namespace otop {
void SigmoidKernel::RunNative(const InputList& inputs, OutputList& outputs, const Option& option)
{
    const int64_t n_elem      = inputs[0]->GetElemNum();
    const int64_t h           = inputs[0]->GetDim(1);
    const int64_t w           = inputs[0]->GetDim(2);
    const int64_t ch          = inputs[0]->GetDim(3);

    #pragma omp parallel for num_threads(CORES_PER_SOCKET)
    for (int q = 0; q < h * w; q++)
    {
        float* ptr = outputs[0]->GetBufferPtr<float>() + q * ch;

        for (int i = 0; i < ch; i++)
        {
            float v = ptr[i];
            v = std::min(v, 88.3762626647949f);
            v = std::max(v, -88.3762626647949f);
            ptr[i] = 1.f / (1.f + expf(-v));
        }
    }
    return;
}
} //namespace otop
