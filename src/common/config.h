#ifndef OTOP_COMMON_CONFIG_H
#define OTOP_COMMON_CONFIG_H
#include <string>
#include <iostream>
namespace otop {
template<typename T>
T* CheckNotNull(const char* /* file */, int /* line */,
                const char* name, T* val) {
  if (val == NULL) {
    std::cerr << name << std::endl;
    exit(-1);
  }
  return val;
}
#define CHECK_NOTNULL(A) \
    CheckNotNull(__FILE__, __LINE__, "'" #A "' must not be NULL", (A))

constexpr char     RES_DATA[]       = "./res_data/";
constexpr int32_t  CORES_PER_SOCKET = 12;


} //namespace otop
#endif // OTOP_COMMON_CONFIG_H