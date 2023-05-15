#ifndef OTOP_SRC_COMMON_MATH_H
#define OTOP_SRC_COMMON_MATH_H
#include <algorithm>
#include <type_traits>
#include <stdint.h>
namespace otop {

template <typename T>
inline T max(const T a, const T b)
{
    static_assert(std::is_fundamental<T>::value, "only allow fundamental type");
    return a > b ? a : b;
}

template <typename T>
inline T min(const T a, const T b)
{
    static_assert(std::is_fundamental<T>::value, "only allow fundamental type");
    return a < b ? a : b;
}

template <typename T>
inline T abs(const T x)
{
    static_assert(std::is_arithmetic<T>::value, "only allow arithmetic type");
    return x > 0 ? x : (-x);
}

template <typename T0, typename T1>
inline T0 div_up(const T0 a, const T1 b)
{
    static_assert(std::is_integral<T0>::value && std::is_integral<T1>::value, "only allow integral type");
    const T0 tb = static_cast<T0>(b);
    return (a + tb - static_cast<T0>(1)) / tb;
}

template <typename T0, typename T1>
inline T0 round(const T0 a, const T1 b)
{
    static_assert(std::is_integral<T0>::value && std::is_integral<T1>::value, "only allow integral type");
    const T0 tb = static_cast<T0>(b);
    return a / tb * tb;
}

template <typename T0, typename T1>
inline T0 round_up(const T0 a, const T1 b)
{
    static_assert(std::is_integral<T0>::value && std::is_integral<T1>::value, "only allow integral type");
    const T0 tb = static_cast<T0>(b);
    return (a + tb - static_cast<T0>(1)) / tb * tb;
}

template <typename T0, typename T1>
inline T0 mod_up(const T0 a, const T1 m)
{
    static_assert(std::is_integral<T0>::value && std::is_integral<T1>::value, "only allow integral type");
    const T0 tm = static_cast<T0>(m);
    return (a % tm == 0 && a != 0) ? tm : a % tm;
}

template <typename DataType, typename IndexType>
inline void argsort(const DataType *src, IndexType *indices, const int64_t length, const bool dec = true)
{
    for (int64_t i = 0; i < length; ++i)
        indices[i] = static_cast<IndexType>(i);
    if (dec) {
        std::stable_sort(indices, indices + length,
            [&src](const IndexType &ind0, const IndexType &ind1) { return src[ind0] > src[ind1]; });
    } else {
        std::stable_sort(indices, indices + length,
            [&src](const IndexType &ind0, const IndexType &ind1) { return src[ind0] < src[ind1]; });
    }
}

} //namespace otop


#endif // OTOP_SRC_COMMON_MATH_H