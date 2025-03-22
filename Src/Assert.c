#include "Assert.h"

static const char* ASSERT_TYPES[] = {
#if ASSERT_SUPPORT_RAW
    "Raw",
#endif
#if ASSERT_SUPPORT_STR
    "Str",
#endif
#if ASSERT_SUPPORT_CHAR
    "Char",
#endif
#if ASSERT_SUPPORT_UINT8
    "UInt8",
#endif
#if ASSERT_SUPPORT_INT8
    "Int8",
#endif
#if ASSERT_SUPPORT_UINT16
    "UInt16",
#endif
#if ASSERT_SUPPORT_INT16
    "Int16",
#endif
#if ASSERT_SUPPORT_UINT32
    "UInt32",
#endif
#if ASSERT_SUPPORT_INT32
    "Int32",
#endif
#if ASSERT_SUPPORT_UINT64
    "UInt64",
#endif
#if ASSERT_SUPPORT_INT64
    "Int64",
#endif
#if ASSERT_SUPPORT_FLOAT
    "Float",
#endif
#if ASSERT_SUPPORT_DOUBLE
    "Double",
#endif
};

/* --------------------------------- Implement Assert Functions ------------------------------------ */
#if ASSERT_SUPPORT_RAW
#include <string.h>

static void __Assert_printRaw(uint8_t* arr, Assert_Length len) {
    ASSERT_PRINTF("[");
    while (len-- > 0) {
        ASSERT_PRINTF("%02X, ", *arr++);
    }
    ASSERT_PRINTF("]%s", ASSERT_END_LINE);
}

#endif

#define __ASSERT_PRINT_CASE(TYPE, XTYPE) \
case Assert_Type_ ##TYPE: \
    ASSERT_PRINTF("  Left:  "XTYPE"%s", inputs.Left.TYPE, ASSERT_END_LINE); \
    ASSERT_PRINTF("  Right: "XTYPE"%s", inputs.Right.TYPE, ASSERT_END_LINE); \
    break

Assert_Result Assert_Values(Assert_Type type, Assert_Inputs inputs, Assert_Condition condition, Assert_File file, Assert_Line line) {
    Assert_Result result = {0};
    int res;
    // Compare Left and Right
    switch (type) {
    #if ASSERT_SUPPORT_RAW
        case Assert_Type_Raw:
            res = memcmp(inputs.Left.Raw, inputs.Right.Raw, inputs.Length);
            break;
    #endif
    #if ASSERT_SUPPORT_STR
        case Assert_Type_Str:
            res = strcmp(inputs.Left.Str, inputs.Right.Str);
            break;
    #endif
        default:
            res = memcmp(&inputs.Left, &inputs.Right, inputs.Length);
            break;
    }

    if ((res == 0) == condition) {
        ASSERT_PRINTF("Assert %s Failed, %s:%u%s", ASSERT_TYPES[type] ,file, line, ASSERT_END_LINE);
        switch (type) {
        #if ASSERT_SUPPORT_RAW
            case Assert_Type_Raw:
                ASSERT_PRINTF("  Left:  ");
                __Assert_printRaw(inputs.Left.Raw, inputs.Length);
                ASSERT_PRINTF("  Right: ");
                __Assert_printRaw(inputs.Right.Raw, inputs.Length);
                break;
        #endif
        #if ASSERT_SUPPORT_STR
            __ASSERT_PRINT_CASE(Str,    "%s");
        #endif
        #if ASSERT_SUPPORT_CHAR
            __ASSERT_PRINT_CASE(Char,   "%c");
        #endif
        #if ASSERT_SUPPORT_UINT8
            __ASSERT_PRINT_CASE(UInt8,  "%u");
        #endif
        #if ASSERT_SUPPORT_INT8
            __ASSERT_PRINT_CASE(Int8,   "%d");
        #endif
        #if ASSERT_SUPPORT_UINT16
            __ASSERT_PRINT_CASE(UInt16, "%u");
        #endif
        #if ASSERT_SUPPORT_INT16
            __ASSERT_PRINT_CASE(Int16,  "%d");
        #endif
        #if ASSERT_SUPPORT_UINT32
            __ASSERT_PRINT_CASE(UInt32, "%u");
        #endif
        #if ASSERT_SUPPORT_INT32
            __ASSERT_PRINT_CASE(Int32,  "%d");
        #endif
        #if ASSERT_SUPPORT_UINT64
            __ASSERT_PRINT_CASE(UInt64, "%llu");
        #endif
        #if ASSERT_SUPPORT_INT64
            __ASSERT_PRINT_CASE(Int64,  "%lld");
        #endif
        #if ASSERT_SUPPORT_FLOAT
            __ASSERT_PRINT_CASE(Float,  "%g");
        #endif
        #if ASSERT_SUPPORT_DOUBLE
            __ASSERT_PRINT_CASE(Double, "%g");
        #endif
            default:

                break;
        }
        
        result.File = file;
        result.Line = line;
        result.Inputs = inputs;
        result.Type = type;
        Assert_hook(&result);
    }
    return result;
}
