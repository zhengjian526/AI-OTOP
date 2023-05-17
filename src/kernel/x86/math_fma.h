
#include <immintrin.h>
namespace otop {
static inline __m256 _fma_sigmoid_ps(const __m256 var)
{
    __m256 value = var;
    value = _mm256_max_ps(_mm256_set1_ps(-18.0f), value);
    value = _mm256_min_ps(_mm256_set1_ps(18.0f), value);

    __m256 value_squared = _mm256_mul_ps(value, value);

    __m256 p;
    p = _mm256_fmadd_ps(value_squared, _mm256_set1_ps(4.37031012579801e-11f), _mm256_set1_ps(1.15627324459942e-07f));
    p = _mm256_fmadd_ps(p, value_squared, _mm256_set1_ps(6.08574864600143e-05f));
    p = _mm256_fmadd_ps(p, value_squared, _mm256_set1_ps(8.51377133304701e-03f));
    p = _mm256_fmadd_ps(p, value_squared, _mm256_set1_ps(2.48287947061529e-01f));
    p = _mm256_mul_ps(p, value);

    __m256 q;
    q = _mm256_fmadd_ps(value_squared, _mm256_set1_ps(6.10247389755681e-13f), _mm256_set1_ps(5.76102136993427e-09f));
    q = _mm256_fmadd_ps(q, value_squared, _mm256_set1_ps(6.29106785017040e-06f));
    q = _mm256_fmadd_ps(q, value_squared, _mm256_set1_ps(1.70198817374094e-03f));
    q = _mm256_fmadd_ps(q, value_squared, _mm256_set1_ps(1.16817656904453e-01f));
    q = _mm256_fmadd_ps(q, value_squared, _mm256_set1_ps(9.93151921023180e-01f));

    __m256 dst = _mm256_add_ps(_mm256_div_ps(p, q), _mm256_set1_ps(0.5f));
    return dst;
}
} // namespace otop