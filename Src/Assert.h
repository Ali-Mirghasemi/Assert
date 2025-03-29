/**
 * @file Assert.h
 * @author Ali Mirghasemi (ali.mirghasemi1376@gmail.com)
 * @brief This library provide assert helper macros
 * @version 0.1
 * @date 2025-03-20
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef _ASSERT_H_
#define _ASSERT_H_

#ifdef __cplusplus
extern "C" {
#endif

#define ASSERT_VER_MAJOR    0
#define ASSERT_VER_MINOR    9
#define ASSERT_VER_FIX      2

#include <stdint.h>

/************************************************************************/
/*                            Configuration                             */
/************************************************************************/
/**
 * @brief if your platform support raw variables and you need it
 * you can enable this option
 */
#define ASSERT_SUPPORT_RAW                          1
/**
 * @brief if your platform support string variables and you need it
 * you can enable this option
 */
#define ASSERT_SUPPORT_STR                          1
/**
 * @brief if your platform support char variables and you need it
 * you can enable this option
 */
#define ASSERT_SUPPORT_CHAR                         1
/**
 * @brief if your platform support 8bit variables and you need it
 * you can enable this option
 */
#define ASSERT_SUPPORT_UINT8                        1
/**
 * @brief if your platform support 8bit variables and you need it
 * you can enable this option
 */
#define ASSERT_SUPPORT_INT8                         1
/**
 * @brief if your platform support 16bit variables and you need it
 * you can enable this option
 */
#define ASSERT_SUPPORT_UINT16                       1
/**
 * @brief if your platform support 16bit variables and you need it
 * you can enable this option
 */
#define ASSERT_SUPPORT_INT16                        1
/**
 * @brief if your platform support 32bit variables and you need it
 * you can enable this option
 */
#define ASSERT_SUPPORT_UINT32                       1
/**
 * @brief if your platform support 32bit variables and you need it
 * you can enable this option
 */
#define ASSERT_SUPPORT_INT32                        1
/**
 * @brief if your platform support 64bit variables and you need it
 * you can enable this option
 */
#define ASSERT_SUPPORT_UINT64                       1
/**
 * @brief if your platform support 64bit variables and you need it
 * you can enable this option
 */
#define ASSERT_SUPPORT_INT64                        1
/**
 * @brief if you need r/w double variables and your platform support
 * you can enable this option
 */
#define ASSERT_SUPPORT_FLOAT                        1
/**
 * @brief if you need r/w double variables and your platform support
 * you can enable this option
 */
#define ASSERT_SUPPORT_DOUBLE                       1
/**
 * @brief if you need r/w const char* array variables and your platform support
 * you can enable this option
 */
#define ASSERT_SUPPORT_RAW_2D                       1
/**
 * @brief if you need r/w const char* array variables and your platform support
 * you can enable this option
 */
#define ASSERT_SUPPORT_STR_LIST                     1

#ifndef ASSERT_SUPPORT_STDIO
    /**
     * @brief if you want to print assert details
     */
    #define ASSERT_SUPPORT_STDIO                    1
#endif
#ifndef ASSERT_SUPPORT_PRINT
    /**
     * @brief if you want to print assert details
     */
    #define ASSERT_SUPPORT_PRINT                    1
#endif
#ifndef ASSERT_SUPPORT_HOOK 
    /**
     * @brief Enable assert hook function for print extra details
     */
    #define ASSERT_SUPPORT_HOOK                     0
#endif
#ifndef ASSERT_END_LINE
    /**
     * @brief Set Assert End line
     */
    #define ASSERT_END_LINE                         "\r\n"
#endif
/**
 * @brief Define Assert Line type
 */
typedef uint32_t Assert_Line;
/**
 * @brief Define Assert Length type
 */
typedef uint32_t Assert_Length;
/**
 * @brief Define Assert File type
 */
typedef const char* Assert_File;
/************************************************************************/

#include "AssertMacro.h"

#if ASSERT_SUPPORT_STDIO
    #include <stdio.h>
#endif // ASSERT_SUPPORT_STDIO

#if ASSERT_SUPPORT_PRINT && !defined(ASSERT_PRINTF)
    #define ASSERT_PRINTF                              printf
#else
    #define ASSERT_PRINTF(...)
#endif
/**
 * @brief Assert Supporetd input types
 */
typedef enum {
#if ASSERT_SUPPORT_RAW
    Assert_Type_Raw,
#endif
#if ASSERT_SUPPORT_STR
    Assert_Type_Str,
#endif
#if ASSERT_SUPPORT_CHAR
    Assert_Type_Char,
#endif
#if ASSERT_SUPPORT_UINT8
    Assert_Type_UInt8,
#endif
#if ASSERT_SUPPORT_INT8
    Assert_Type_Int8,
#endif
#if ASSERT_SUPPORT_UINT16
    Assert_Type_UInt16,
#endif
#if ASSERT_SUPPORT_INT16
    Assert_Type_Int16,
#endif
#if ASSERT_SUPPORT_UINT32
    Assert_Type_UInt32,
#endif
#if ASSERT_SUPPORT_INT32
    Assert_Type_Int32,
#endif
#if ASSERT_SUPPORT_UINT64
    Assert_Type_UInt64,
#endif
#if ASSERT_SUPPORT_INT64
    Assert_Type_Int64,
#endif
#if ASSERT_SUPPORT_FLOAT
    Assert_Type_Float,
#endif
#if ASSERT_SUPPORT_DOUBLE
    Assert_Type_Double,
#endif
#if ASSERT_SUPPORT_RAW_2D
    Assert_Type_Raw2D,
#endif
#if ASSERT_SUPPORT_STR_LIST
    Assert_Type_StrList,
#endif
} Assert_Type;
/**
 * @brief Assert Supported inputs
 */
typedef union {
#if ASSERT_SUPPORT_RAW
    void*               Raw;
#endif
#if ASSERT_SUPPORT_STR
    const char*         Str;
#endif
#if ASSERT_SUPPORT_CHAR
    char                Char;
#endif
#if ASSERT_SUPPORT_UINT8
    uint8_t             UInt8;
#endif
#if ASSERT_SUPPORT_INT8
    int8_t              Int8;
#endif
#if ASSERT_SUPPORT_UINT16
    uint16_t            UInt16;
#endif
#if ASSERT_SUPPORT_INT16
    int16_t             Int16;
#endif
#if ASSERT_SUPPORT_UINT32
    uint32_t            UInt32;
#endif
#if ASSERT_SUPPORT_INT32
    int32_t             Int32;
#endif
#if ASSERT_SUPPORT_UINT64
    uint64_t            UInt64;
#endif
#if ASSERT_SUPPORT_INT64
    int64_t             Int64;
#endif
#if ASSERT_SUPPORT_FLOAT
    float               Float;
#endif
#if ASSERT_SUPPORT_DOUBLE
    double              Double;
#endif
#if ASSERT_SUPPORT_RAW_2D
    void*               Raw2D;
#endif
#if ASSERT_SUPPORT_STR_LIST
    const char*         StrList;
#endif
} Assert_Variable;
/**
 * @brief Assert Inputs
 */
typedef struct {
    Assert_Variable     Left;
    Assert_Variable     Right;
    Assert_Length       Length;
    Assert_Length       Length2;
} Assert_Inputs;
/**
 * @brief Assert Condition
 */
typedef enum {
    Assert_Condition_Equal,
    Assert_Condition_NotEqual,
} Assert_Condition;
/**
 * @brief Assert Result type
 */
typedef struct {
    Assert_File         File;
    Assert_Line         Line;
    Assert_Inputs       Inputs;
    Assert_Type         Type;
} Assert_Result;

#if ASSERT_SUPPORT_HOOK
    void Assert_hook(Assert_Result* result);
#else
    #define Assert_hook(...)
#endif

/* -------------------------------------- APIs -------------------------------------------- */
/**
 * @brief Assert two variable and print if `left` and `right` not equal
 * Input Formats:
 *  (CONDITION)                 -> Check Condition is True otherwise print FILE:LINE
 *  (LEFT, RIGHT)               -> Compare Left and Right input, Only for primitive types
 *  (TYPE, LEFT, RIGHT)         -> Compare Left and Right input
 *  (TYPE, LEFT, RIGHT, LEN)    -> Compare Left and Right input with fixed length for Raw types such as uint8_t array
 *
 * @param TYPE  Raw: compare two variable with raw values, such as uint8_t array
 *              Str: compare two strings
 *              Char: compare two characters
 *              UInt8: compare two uint8_t
 *              Int8: compare two int8_t
 *              UInt16: compare two uint16_t
 *              Int16: compare two int16_t
 *              UInt32: compare two uint32_t
 *              Int32: compare two int32_t
 *              UInt64: compare two uint64_t
 *              Int64: compare two int64_t
 *              Float: compare two float
 *              Double: compare two double
 *
 */
#define assert(...)                             assertEq(__VA_ARGS__)
/**
 * @brief Same as assert(...) macro but return void if `left` and `right` not equal
 */
#define assertReturn(...)                       __assertXReturn(assert, __VA_ARGS__)
/**
 * @brief Same as assert(...) macro but return Assert_Line if `left` and `right` not equal
 */
#define assertReturnLine(...)                   __assertXReturnLine(assert, __VA_ARGS__)
/**
 * @brief Same as assert(...) macro but return Assert_Result if `left` and `right` not equal
 */
#define assertReturnResult(...)                 __assertXReturnResult(assert, __VA_ARGS__)

/**
 * @brief Assert two variable and print if `left` and `right` not equal
 * Input Formats:
 *  (CONDITION)                 -> Check Condition is True otherwise print FILE:LINE
 *  (LEFT, RIGHT)               -> Compare Left and Right input, Only for primitive types
 *  (TYPE, LEFT, RIGHT)         -> Compare Left and Right input
 *  (TYPE, LEFT, RIGHT, LEN)    -> Compare Left and Right input with fixed length for Raw types such as uint8_t array
 *
 * @param TYPE  Raw: compare two variable with raw values, such as uint8_t array
 *              Str: compare two strings
 *              Char: compare two characters
 *              UInt8: compare two uint8_t
 *              Int8: compare two int8_t
 *              UInt16: compare two uint16_t
 *              Int16: compare two int16_t
 *              UInt32: compare two uint32_t
 *              Int32: compare two int32_t
 *              UInt64: compare two uint64_t
 *              Int64: compare two int64_t
 *              Float: compare two float
 *              Double: compare two double
 *
 */
#define assertEq(...)                           __ASSERT(Eq, __VA_ARGS__)
/**
 * @brief Assert given condition, if condition False print FILE:LINE
 */
#define assertEqCondition(CONDITION)            if (!(CONDITION)) { \
                                                    ASSERT_PRINTF("Assert Failed, %s:%u%s", __FILE__, __LINE__, ASSERT_END_LINE); \
                                                }
/**
 * @brief Assert Left and Right values and determine size automaticaly
 */
#define assertEqRawValues(L, R)                 Assert_Values(__ASSERT_CAT(Assert_Type_, __ASSERT_PRIMARY_MAX_TYPE) , (Assert_Inputs) { .Left = { .__ASSERT_PRIMARY_MAX_TYPE = (__ASSERT_CAT(__Assert_Type_, __ASSERT_PRIMARY_MAX_TYPE)) (L) }, .Right = { .__ASSERT_PRIMARY_MAX_TYPE = (__ASSERT_CAT(__Assert_Type_, __ASSERT_PRIMARY_MAX_TYPE)) (R) }, .Length = sizeof(R) }, Assert_Condition_Equal, __FILE__, __LINE__)
/**
 * @brief Assert two values
 */
#define assertEqValues(TYPE, L, R)              Assert_Values(Assert_Type_ ##TYPE, (Assert_Inputs) { .Left = { .TYPE = (L) }, .Right = { .TYPE = (R) }, .Length = sizeof(__Assert_Type_ ##TYPE) }, Assert_Condition_Equal, __FILE__, __LINE__)
/**
 * 
 * @brief Assert two Raw values
 */
#define assertEqRaw(TYPE, L, R, LEN)            Assert_Values(Assert_Type_ ##TYPE, (Assert_Inputs) { .Left = { .TYPE = (L) }, .Right = { .TYPE = (R) }, .Length = (LEN) }, Assert_Condition_Equal, __FILE__, __LINE__)
/**
 * @brief Assert two Raw values
 */
#define assertEqRaw2D(TYPE, L, R, LEN, LEN2)    Assert_Values(Assert_Type_ ##TYPE, (Assert_Inputs) { .Left = { .TYPE = (L) }, .Right = { .TYPE = (R) }, .Length = (LEN), .Length2 = (LEN2) }, Assert_Condition_Equal, __FILE__, __LINE__)
/**
 * @brief Same as assert(...) macro but return void if `left` and `right` not equal
 */
#define assertEqReturn(...)                     __assertXReturn(assertEq, __VA_ARGS__)
/**
 * @brief Same as assert(...) macro but return Assert_Line if `left` and `right` not equal
 */
#define assertEqReturnLine(...)                 __assertXReturnLine(assertEq, __VA_ARGS__)
/**
 * @brief Same as assert(...) macro but return Assert_Result if `left` and `right` not equal
 */
#define assertEqReturnResult(...)               __assertXReturnResult(assertEq, __VA_ARGS__)

/**
 * @brief Assert two variable and print if `left` and `right`are equal
 * Input Formats:
 *  (CONDITION)                 -> Check Condition is True otherwise print FILE:LINE
 *  (LEFT, RIGHT)               -> Compare Left and Right input, Only for primitive types
 *  (TYPE, LEFT, RIGHT)         -> Compare Left and Right input
 *  (TYPE, LEFT, RIGHT, LEN)    -> Compare Left and Right input with fixed length for Raw types such as uint8_t array
 *
 * @param TYPE  Raw: compare two variable with raw values, such as uint8_t array
 *              Str: compare two strings
 *              Char: compare two characters
 *              UInt8: compare two uint8_t
 *              Int8: compare two int8_t
 *              UInt16: compare two uint16_t
 *              Int16: compare two int16_t
 *              UInt32: compare two uint32_t
 *              Int32: compare two int32_t
 *              UInt64: compare two uint64_t
 *              Int64: compare two int64_t
 *              Float: compare two float
 *              Double: compare two double
 *
 */
#define assertNe(...)                           __ASSERT(Ne, __VA_ARGS__)
/**
 * @brief Assert given condition, if condition False print FILE:LINE
 */
#define assertNeCondition(CONDITION)            if ((CONDITION)) { \
                                                    ASSERT_PRINTF("Assert Failed, %s:%u%s", __FILE__, __LINE__, ASSERT_END_LINE); \
                                                }
/**
 * @brief Assert Left and Right values and determine size automaticaly
 */
#define assertNeRawValues(L, R)                 Assert_Values(__ASSERT_CAT(Assert_Type_, __ASSERT_PRIMARY_MAX_TYPE) , (Assert_Inputs) { .Left = { .__ASSERT_PRIMARY_MAX_TYPE = (__ASSERT_CAT(__Assert_Type_, __ASSERT_PRIMARY_MAX_TYPE)) (L) }, .Right = { .__ASSERT_PRIMARY_MAX_TYPE = (__ASSERT_CAT(__Assert_Type_, __ASSERT_PRIMARY_MAX_TYPE)) (R) }, .Length = sizeof(R) }, Assert_Condition_NotEqual, __FILE__, __LINE__)
/**
 * @brief Assert two values
 */
#define assertNeValues(TYPE, L, R)              Assert_Values(Assert_Type_ ##TYPE, (Assert_Inputs) { .Left = { .TYPE = (L) }, .Right = { .TYPE = (R) }, .Length = sizeof(__Assert_Type_ ##TYPE) }, Assert_Condition_NotEqual, __FILE__, __LINE__)
/**
 * @brief Assert two Raw values
 */
#define assertNeRaw(TYPE, L, R, LEN)            Assert_Values(Assert_Type_ ##TYPE, (Assert_Inputs) { .Left = { .TYPE = (L) }, .Right = { .TYPE = (R) }, .Length = (LEN) }, Assert_Condition_NotEqual, __FILE__, __LINE__)
/**
 * @brief Assert two Raw values
 */
#define assertNeRaw2D(TYPE, L, R, LEN, LEN2)    Assert_Values(Assert_Type_ ##TYPE, (Assert_Inputs) { .Left = { .TYPE = (L) }, .Right = { .TYPE = (R) }, .Length = (LEN), .Length2 = (LEN2) }, Assert_Condition_NotEqual, __FILE__, __LINE__)
/**
 * @brief Same as assert(...) macro but return void if `left` and `right` not equal
 */
#define assertNeReturn(...)                     __assertXReturn(assertNe, __VA_ARGS__)
/**
 * @brief Same as assert(...) macro but return Assert_Line if `left` and `right` not equal
 */
#define assertNeReturnLine(...)                 __assertXReturnLine(assertNe, __VA_ARGS__)
/**
 * @brief Same as assert(...) macro but return Assert_Result if `left` and `right` not equal
 */
#define assertNeReturnResult(...)               __assertXReturnResult(assertNe, __VA_ARGS__)


/* ---------------------------------- Private APIs ---------------------------------------- */
Assert_Result Assert_Values(Assert_Type type, Assert_Inputs inputs, Assert_Condition condition, Assert_File file, Assert_Line line);

#ifdef __cplusplus
};
#endif

#endif // _ASSERT_H_
