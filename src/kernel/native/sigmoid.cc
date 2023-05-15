#include "kernel/native/sigmoid.h"
namespace otop {
void SigmoidKernel::SetAttr(const SigmoidAttr& attr)
{
    attr_ = attr;
    return;
}
void SigmoidKernel::Run(InputList inputs, OutputList outputs, const Option& option)
{

}
} //namespace otop
