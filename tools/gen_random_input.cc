#include "common/gen_random.h"
#include "common/tensor.h"
#include "common/option.h"
#include "kernel/kernel.h"
#include "runtime/kernel_runtime.h"
#include "kernel/native/sigmoid.h"
#include "yaml-cpp/yaml.h"
#include <string.h>

using namespace otop;
const std::string CONF = "config.yaml";
int main(int argc, char **argv) {
  if ((argc == 2 && strcmp(argv[1], "--help") == 0) || argc >= 3 || argc < 2){
      printf("usage: %s file_name \n", argv[0]);
      return 0;
  }
  std::string file_name = argv[1];
  YAML::Node conf = YAML::LoadFile(CONF);
  Option option;
  Shape shape = conf["tensor"]["shape"].as<Shape>();
  TensorInfo tensor_info {shape, conf["tensor"]["data_type"].as<uint32_t>()};
  uint64_t size = tensor_info.GetElemNum();
  std::vector<float> buffer0(size, 0);
  Tensor input_tensor(buffer0.data(), tensor_info);
  GenRandTensor<float>(input_tensor.GetBufferPtr<float>(), 1, 100, input_tensor.GetElemNum());
  input_tensor.SaveToFile(file_name);
  return 0;
}