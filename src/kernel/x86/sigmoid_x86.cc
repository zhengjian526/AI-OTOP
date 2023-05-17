#include "kernel/kernels/sigmoid.h"
#include "common/math.h"
#include <math.h>
#include "math_sse.h"
#include "math_fma.h"

namespace otop {
void SigmoidKernel::SetAttr(const SigmoidAttr& attr)
{
    attr_ = attr;
    return;
}
void SigmoidKernel::RunSSE(const InputList& inputs, OutputList& outputs, const Option& option)
{
    const int64_t n_elem      = inputs[0]->GetElemNum();
    const int64_t unroll_n    = 16;
    const int64_t unroll_body = round(n_elem, unroll_n);
    float* x = inputs[0]->GetBufferPtr<float>();
    float* y = outputs[0]->GetBufferPtr<float>();
    #pragma omp parallel for num_threads(4)
    for (int64_t i = 0; i < unroll_body; i += unroll_n) {
        __m128 src0 = _mm_loadu_ps(x + i + 0);
        __m128 src1 = _mm_loadu_ps(x + i + 4);
        __m128 src2 = _mm_loadu_ps(x + i + 8);
        __m128 src3 = _mm_loadu_ps(x + i + 12);
        _mm_storeu_ps(y + i + 0, _sse_sigmoid_ps(src0));
        _mm_storeu_ps(y + i + 4, _sse_sigmoid_ps(src1));
        _mm_storeu_ps(y + i + 8, _sse_sigmoid_ps(src2));
        _mm_storeu_ps(y + i + 12, _sse_sigmoid_ps(src3));
    }
    for (int64_t i = unroll_body; i < n_elem; ++i) {
        y[i] = 1.0f / (expf(-x[i]) + 1.0f);
    }
    return;
}
void SigmoidKernel::RunFMA(const InputList& inputs, OutputList& outputs, const Option& option)
{
    const int64_t n_elem      = inputs[0]->GetElemNum();
    const int64_t unroll_n    = 32;
    const int64_t unroll_body = round(n_elem, unroll_n);
    float* x = inputs[0]->GetBufferPtr<float>();
    float* y = outputs[0]->GetBufferPtr<float>();

    #pragma omp parallel for num_threads(4)
    for (int64_t i = 0; i < unroll_body; i += unroll_n) {
        __m256 src0, src1, src2, src3;
        src0 = _mm256_loadu_ps(x + i + 0);
        src1 = _mm256_loadu_ps(x + i + 8);
        src2 = _mm256_loadu_ps(x + i + 16);
        src3 = _mm256_loadu_ps(x + i + 24);
        _mm256_storeu_ps(y + i + 0, _fma_sigmoid_ps(src0));
        _mm256_storeu_ps(y + i + 8, _fma_sigmoid_ps(src1));
        _mm256_storeu_ps(y + i + 16, _fma_sigmoid_ps(src2));
        _mm256_storeu_ps(y + i + 24, _fma_sigmoid_ps(src3));
    }
    for (int64_t i = unroll_body; i < n_elem; ++i) {
        y[i] = 1.0f / (expf(-x[i]) + 1.0f);
    }
    return;
}
} //namespace otop
