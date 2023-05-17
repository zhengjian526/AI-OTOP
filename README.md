# AI-OTOP
AI operator testing and optimization platform

# 硬件配置
需要根据使用的硬件确认具体支持哪些SIMD指令集，测试使用的X86 CPU，支持SSE4.2，AVX2和FMA等。所以代码中的默认配置SSE表示128位SSE指令集, FMA表示支持混合乘加指令的FMA指令集，FMA是在原有的AVX2则在此基础上加入了以下新内容：整数SIMD指令扩展至256位，2个新FMA单元及浮点FMA指令，离散数据加载指令“gather”，新的位移和广播指令。

# tools
## format
clang-format14
