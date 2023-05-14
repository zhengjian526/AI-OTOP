#ifndef OTOP_TYPES_H
#define OTOP_TYPES_H
#include <iostream>
namespace otop {
enum {
    DATATYPE_UNKNOWN = 0,
    DATATYPE_UINT8 = 1,
    DATATYPE_UINT16 = 2,
    DATATYPE_UINT32 = 3,
    DATATYPE_UINT64 = 4,
    DATATYPE_FLOAT16 = 5,
    DATATYPE_FLOAT32 = 6,
    DATATYPE_FLOAT64 = 7,
    DATATYPE_BFLOAT16 = 8,
    DATATYPE_INT4B = 9,
    DATATYPE_INT8 = 10,
    DATATYPE_INT16 = 11,
    DATATYPE_INT32 = 12,
    DATATYPE_INT64 = 13,
    DATATYPE_BOOL = 14,
    DATATYPE_COMPLEX64 = 15,
    DATATYPE_COMPLEX128 = 16,
    DATATYPE_MAX,
};
using DataType = uint32_t;


static inline const char* GetDataTypeStr(DataType dt) {
    static const char* data_type_str[] = {
        "UNKNOWN", "UINT8", "UINT16", "UINT32", "UINT64", "FLOAT16", "FLOAT32",   "FLOAT64",    "BFLOAT16",
        "INT4B",   "INT8",  "INT16",  "INT32",  "INT64",  "BOOL",    "COMPLEX64", "COMPLEX128",
    };
    if (dt >= DATATYPE_MAX) {
        return data_type_str[0];
    }
    return data_type_str[dt];
}

static inline uint32_t GetSizeOfDataType(DataType dt) {
    static const uint32_t data_type_size[] = {
        0, // unknown
        1, // uint8_t
        2, // uint16_t
        4, // uint32_t
        8, // uint64_t
        2, // float16_t
        4, // float32
        8, // float64
        2, // BFLOAT16
        1, // INT4B
        1, // int8_t
        2, // int16_t
        4, // int32_t
        8, // int64_t
        1, // bool
        8, // COMPLEX64
        16, // COMPLEX128
    };
    return data_type_size[dt];
}

enum {
    DATAFORMAT_UNKNOWN = 0,
    DATAFORMAT_NDARRAY = 1,
    DATAFORMAT_NHWC8 = 2,
    DATAFORMAT_NHWC16 = 3,
    DATAFORMAT_N2CX = 4,
    DATAFORMAT_N4CX = 5,
    DATAFORMAT_N8CX = 6,
    DATAFORMAT_N16CX = 7,
    DATAFORMAT_N32CX = 8,
    DATAFORMAT_NHWC = 9,
    DATAFORMAT_MAX,
};

} // namespace otop
#endif // OTOP_TYPES_H