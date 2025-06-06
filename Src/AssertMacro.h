/**
 * @file AssertMacro.h
 * @author Ali Mirghasemi (ali.mirghasemi1376@gmail.com)
 * @brief This file contain helper macros for Assert.h
 * @version 0.1
 * @date 2025-03-29
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef _ASSERT_MACRO_H_
#define _ASSERT_MACRO_H_

#define __ASSERT_PRINT_FAILED_(F, L, E)         ASSERT_PRINTF("Assert Failed, " F ":" #L E)
#define __ASSERT_PRINT_FAILED(F, L, E)          __ASSERT_PRINT_FAILED_(F, L ,E)

/**
 * @brief Same as assert(...) macro but return void if `left` and `right` not equal
 */
#define __assertXReturn(FN, ...)                if (FN(__VA_ARGS__)) { return; }
/**
 * @brief Same as assert(...) macro but return Assert_Line if `left` and `right` not equal
 */
#define __assertXReturnLine(FN, ...)            { \
                                                    Assert_Result res = FN(__VA_ARGS__); \
                                                    if (res.Line) { return res.Line; } \
                                                }
/**
 * @brief Same as assert(...) macro but return Assert_Result if `left` and `right` not equal
 */
#define __assertXReturnResult(FN, ...)          { \
                                                    Assert_Result res = FN(__VA_ARGS__); \
                                                    if (res.Line) { return res; } \
                                                }

#define __ASSERT_CAT_(X, Y)                     X ##Y
#define __ASSERT_CAT(X, Y)                      __ASSERT_CAT_(X, Y)

#define __ASSERT_N_(_0, _1, _2, _3, _4, FMT, ...)   FMT
#define __ASSERT_N(...)                         __ASSERT_N_(__VA_ARGS__)
#define __ASSERT_FMT_PAT()                      Raw2D, Raw, Values, RawValues, Condition
#define __ASSERT_BUILD__(XT, FMT, ...)          assert ##XT ##FMT(__VA_ARGS__)
#define __ASSERT_BUILD_(XT, FMT, ...)           __ASSERT_BUILD__(XT, FMT, __VA_ARGS__)
#define __ASSERT_BUILD(XT, ...)                 __ASSERT_BUILD_(XT, __ASSERT_N(__VA_ARGS__, __ASSERT_FMT_PAT()), __VA_ARGS__)
#define __ASSERT(XT, ...)                       __ASSERT_BUILD(XT, __VA_ARGS__)

#if ASSERT_SUPPORT_RAW
    typedef void*               __Assert_Type_Raw;
#endif
#if ASSERT_SUPPORT_STR
    typedef const char*         __Assert_Type_Str;
#endif
#if ASSERT_SUPPORT_CHAR
    typedef char                __Assert_Type_Char;
#endif
#if ASSERT_SUPPORT_UINT8
    typedef uint8_t             __Assert_Type_UInt8;
#endif
#if ASSERT_SUPPORT_INT8
    typedef int8_t              __Assert_Type_Int8;
#endif
#if ASSERT_SUPPORT_UINT16
    typedef uint16_t            __Assert_Type_UInt16;
#endif
#if ASSERT_SUPPORT_INT16
    typedef int16_t             __Assert_Type_Int16;
#endif
#if ASSERT_SUPPORT_UINT32
    typedef uint32_t            __Assert_Type_UInt32;
#endif
#if ASSERT_SUPPORT_INT32
    typedef int32_t             __Assert_Type_Int32;
#endif
#if ASSERT_SUPPORT_UINT64
    typedef uint64_t            __Assert_Type_UInt64;
#endif
#if ASSERT_SUPPORT_INT64
    typedef int64_t             __Assert_Type_Int64;
#endif
#if ASSERT_SUPPORT_FLOAT
    typedef float               __Assert_Type_Float;
#endif
#if ASSERT_SUPPORT_DOUBLE
    typedef double              __Assert_Type_Double;
#endif
#if ASSERT_SUPPORT_RAW_LIST
    typedef void*               __Assert_Type_RawList;
#endif
#if ASSERT_SUPPORT_STR_LIST
    typedef const char*         __Assert_Type_StrList;
#endif

// Find Maximum Primary Type
#if   ASSERT_SUPPORT_UINT64
    #define __ASSERT_PRIMARY_MAX_TYPE               UInt64
#elif ASSERT_SUPPORT_INT64
    #define __ASSERT_PRIMARY_MAX_TYPE               Int64
#elif ASSERT_SUPPORT_UINT32
    #define __ASSERT_PRIMARY_MAX_TYPE               UInt32
#elif ASSERT_SUPPORT_INT32
    #define __ASSERT_PRIMARY_MAX_TYPE               Int32
#elif ASSERT_SUPPORT_UINT16
    #define __ASSERT_PRIMARY_MAX_TYPE               UInt16
#elif ASSERT_SUPPORT_INT16
    #define __ASSERT_PRIMARY_MAX_TYPE               Int16
#elif ASSERT_SUPPORT_UINT8
    #define __ASSERT_PRIMARY_MAX_TYPE               UInt8
#elif ASSERT_SUPPORT_INT8
    #define __ASSERT_PRIMARY_MAX_TYPE               Int8
#endif

#endif // _ASSERT_MACRO_H_
