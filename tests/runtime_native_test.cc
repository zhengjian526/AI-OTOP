#include "common/gen_random.h"
#include "common/tensor.h"
#include "common/option.h"
#include "kernel/kernel.h"
#include "runtime/kernel_runtime.h"
#include "kernel/native/sigmoid.h"
#include "gtest/gtest.h"

using namespace otop;


TEST(OTOPTest, RandomTest) {
  Option option;
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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}