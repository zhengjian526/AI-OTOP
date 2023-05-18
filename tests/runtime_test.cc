#include "common/gen_random.h"
#include "common/tensor.h"
#include "common/option.h"
#include "kernel/kernels/kernel.h"
#include "runtime/kernel_runtime.h"
#include "kernel/kernels/sigmoid.h"
#include "gtest/gtest.h"
#include "yaml-cpp/yaml.h"
using namespace otop;

const std::string CONF = "config.yaml";
TEST(OTOPTest, RandomTest) {
  YAML::Node conf = YAML::LoadFile(CONF);
  Option option;
  option.simd_mode = static_cast<Option::SimdMode>(conf["option"]["simd_mode"].as<uint32_t>());
  std::cout << "1111: " << (int32_t)option.simd_mode << std::endl;
  TensorInfo tensor_info {{1, 10, 100, 100}, DATATYPE_FLOAT32};
  uint64_t size = tensor_info.GetElemNum();
  std::vector<float> buffer0(size, 0);
  std::vector<float> buffer1(size, 0);
  Tensor input_tensor(buffer0.data(), tensor_info);
  Tensor output_tensor(buffer1.data(), tensor_info);
  InputList l1 {&input_tensor};
  InputList l2 {&output_tensor};
  GenRandTensor<float>(input_tensor.GetBufferPtr<float>(), 1, 100, input_tensor.GetElemNum());
  SigmoidAttr attr;
  SigmoidKernel sk;
  sk.SetAttr(attr);
  KernelRuntime runtime;
  runtime.SetKernel(&sk);
  runtime.Run(l1, l2, option);
  output_tensor.SaveToFile("sigmoid");
}
TEST(OTOPTest, TensorFromFileTest) {
  TensorInfo tensor_info {{1, 10, 100, 100}, DATATYPE_FLOAT32};
  std::vector<float> buffer(tensor_info.GetDataSize(), 0);
  // Tensor tensor(buffer.data(), tensor_info);
  Tensor tensor(nullptr, tensor_info);
  bool flag = tensor.FromFile("/workspace/tools/AI-OTOP/build/tests/res_data/sigmoid.bin");
  EXPECT_EQ(flag, true);
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}