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
#if ASSERT_SUPPORT_RAW_LIST
    "RawList",
#endif
#if ASSERT_SUPPORT_RAW_LIST
    "StrList",
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
    ASSERT_PRINTF("]" ASSERT_END_LINE);
}

#endif

#define __ASSERT_PRINT_CASE(TYPE, XTYPE) \
case Assert_Type_ ##TYPE: \
    ASSERT_PRINTF("  Left:  "XTYPE ASSERT_END_LINE, inputs.Left.TYPE); \
    ASSERT_PRINTF("  Right: "XTYPE ASSERT_END_LINE, inputs.Right.TYPE); \
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
    #if ASSERT_SUPPORT_RAW_2D
        case Assert_Type_Raw2D:
            {
                Assert_Length len = inputs.Length2;
                uint8_t* left = inputs.Left.Raw2D;
                uint8_t* right = inputs.Right.Raw2D;

                while (len-- > 0) {
                    if ((res = memcmp(left, right, inputs.Length)) != 0) {
                        break;
                    }

                    left += inputs.Length;
                    right += inputs.Length;
                }
            }
            break;
    #endif
    #if ASSERT_SUPPORT_STR
        case Assert_Type_Str:
            res = strcmp(inputs.Left.Str, inputs.Right.Str);
            break;
    #endif
    #if ASSERT_SUPPORT_STR_LIST
        case Assert_Type_StrList:
            {
                Assert_Length len = inputs.Length;
                const char* left = inputs.Left.StrList;
                const char* right = inputs.Right.StrList;

                while (len-- > 0) {
                    if ((res = strcmp(left++, right++)) != 0) {
                        break;
                    }
                }
            }
            break;
    #endif
        default:
            res = memcmp(&inputs.Left, &inputs.Right, inputs.Length);
            break;
    }

    if ((res == 0) == condition) {
        ASSERT_PRINTF("Assert %s Failed, %s:%u" ASSERT_END_LINE, ASSERT_TYPES[type], file, line);
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

#if ASSERT_SUPPORT_PRINT_HEADER
static void __Assert_printHeaderSigns(uint16_t len, char pad) {
    while (len-- > 0) {
        ASSERT_PRINTF("%c", pad);
    }
}
void Assert_printHeader(const char* title, uint16_t len, char pad) {
    uint16_t halfLen = (len - strlen(title) - 2) >> 1;
    __Assert_printHeaderSigns(halfLen, pad);
    ASSERT_PRINTF(" %s ", title);
    __Assert_printHeaderSigns(halfLen, pad);
    ASSERT_PRINTF("%s", ASSERT_END_LINE);
}
#endif
