#include "common/generate_random.h"
#include "common/tensor.h"
#include "gtest/gtest.h"

using namespace otop;

// class OTOPTest : public testing::Test {};

TEST(OTOPTest, RandomTest) {}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}