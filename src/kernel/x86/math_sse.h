#include <nmmintrin.h>
namespace otop {
static inline __m128 _sse_sigmoid_ps(const __m128 var)
{
    __m128 value = var;
    value = _mm_max_ps(_mm_set1_ps(-18.0f), value);
    value = _mm_min_ps(_mm_set1_ps(18.0f), value);

    __m128 value_squared = _mm_mul_ps(value, value);

    __m128 p;
    p = _mm_mul_ps(value_squared, _mm_set1_ps(4.37031012579801e-11f));
    p = _mm_add_ps(p, _mm_set1_ps(1.15627324459942e-07f));
    p = _mm_mul_ps(p, value_squared);
    p = _mm_add_ps(p, _mm_set1_ps(6.08574864600143e-05f));
    p = _mm_mul_ps(p, value_squared);
    p = _mm_add_ps(p, _mm_set1_ps(8.51377133304701e-03f));
    p = _mm_mul_ps(p, value_squared);
    p = _mm_add_ps(p, _mm_set1_ps(2.48287947061529e-01f));
    p = _mm_mul_ps(p, value);

    __m128 q;
    q = _mm_mul_ps(value_squared, _mm_set1_ps(6.10247389755681e-13f));
    q = _mm_add_ps(q, _mm_set1_ps(5.76102136993427e-09f));
    q = _mm_mul_ps(q, value_squared);
    q = _mm_add_ps(q, _mm_set1_ps(6.29106785017040e-06f));
    q = _mm_mul_ps(q, value_squared);
    q = _mm_add_ps(q, _mm_set1_ps(1.70198817374094e-03f));
    q = _mm_mul_ps(q, value_squared);
    q = _mm_add_ps(q, _mm_set1_ps(1.16817656904453e-01f));
    q = _mm_mul_ps(q, value_squared);
    q = _mm_add_ps(q, _mm_set1_ps(9.93151921023180e-01f));

    __m128 dst = _mm_add_ps(_mm_div_ps(p, q), _mm_set1_ps(0.5f));
    return dst;
}
} //namespace otop

