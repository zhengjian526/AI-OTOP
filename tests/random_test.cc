#include "common/gen_random.h"
#include "common/tensor.h"
#include "gtest/gtest.h"

using namespace otop;


TEST(OTOPTest, RandomTest) {
  TensorInfo tensor_info {{10, 1}, DATATYPE_FLOAT32};
  std::vector<float> buffer(10, 0);
  Tensor<float> tensor(buffer.data(), tensor_info);
  GenRandTensor<float>(tensor.GetAddr(), 1, 100, tensor.GetElemNum());
  EXPECT_EQ(tensor.GetElemNum(), 10);
  EXPECT_EQ(tensor.GetDataSize(), 10 * sizeof(float));
  for(const auto& ii : buffer) {
    std::cout << ii << std::endl;
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}