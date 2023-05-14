#ifndef OTOP_TENSOR_H
#define OTOP_TENSOR_H
#include <random>
#include <vector>
namespace otop {
template <typename T>
void GenRandTensor(T *buffer, const float &min, const float &max,
                   uint32_t elements_num) {
  std::default_random_engine eng;
  std::uniform_real_distribution<T> dis(min, max);
  for (uint32_t i = 0; i < elements_num; ++i) {
    buffer[i] = dis(eng);
  }
  return;
}
} // namespace otop
#endif // OTOP_TENSOR_H