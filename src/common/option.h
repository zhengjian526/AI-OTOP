#ifndef OTOP_COMMON_OPTION_H
#define OTOP_COMMON_OPTION_H
namespace otop {
struct Option
{
    enum class SimdMode {
        NATIVE     = 0,
        SSE        = 1,
        FMA
    };
    SimdMode simd_mode = SimdMode::NATIVE;
};



} //namespace otop
#endif // OTOP_COMMON_OPTION_H