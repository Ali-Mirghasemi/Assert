#include "Assert.h"

int main()
{
    assert(0 == 0);
    assertEq(10 == 10);
    assertNe(12 != 12);

    assert(120, 120);
    assertEq(120, 120);
    assertNe(120, -120);

#if ASSERT_SUPPORT_RAW
    uint8_t left[5] = "ABCDE";
    uint8_t right[5] = "ABCDE";
    uint8_t right2[5] = "ABCDe";

    assert(Raw, left, right, sizeof(left));
    assertEq(Raw, left, right, sizeof(left));
    assertNe(Raw, left, right2, sizeof(left));
#endif

#if ASSERT_SUPPORT_STR
    assert(Str, "Test", "Test");
    assertEq(Str, "Test", "Test");
    assertNe(Str, "Test", "TEST");
#endif

#if ASSERT_SUPPORT_CHAR
    assert(Char, 'X', 'X');
    assertEq(Char, 'X', 'X');
    assertNe(Char, 'x', 'X');
#endif

#if ASSERT_SUPPORT_UINT8
    assert(UInt8, 125, 125);
    assertEq(UInt8, 125, 125);
    assertNe(UInt8, 125, 120);
#endif

#if ASSERT_SUPPORT_INT8
    assert(Int8, 125, 125);
    assertEq(Int8, 125, 125);
    assertNe(Int8, 125, -120);
#endif

#if ASSERT_SUPPORT_UINT16
    assert(UInt16, 1250, 1250);
    assertEq(UInt16, 1250, 1250);
    assertNe(UInt16, 1250, 1200);
#endif

#if ASSERT_SUPPORT_INT16
    assert(Int16, 1250, 1250);
    assertEq(Int16, 1250, 1250);
    assertNe(Int16, 1250, -1200);
#endif

#if ASSERT_SUPPORT_UINT32
    assert(UInt32, 125000, 125000);
    assertEq(UInt32, 125000, 125000);
    assertNe(UInt32, 125000, 120000);
#endif

#if ASSERT_SUPPORT_INT32
    assert(Int32, 125000, 125000);
    assertEq(Int32, 125000, 125000);
    assertNe(Int32, 125000, -120000);
#endif

#if ASSERT_SUPPORT_UINT64
    assert(UInt64, 12500000, 12500000);
    assertEq(UInt64, 12500000, 12500000);
    assertNe(UInt64, 12500000, 12000000);
#endif

#if ASSERT_SUPPORT_INT64
    assert(Int64, 12500000, 12500000);
    assertEq(Int64, 12500000, 12500000);
    assertNe(Int64, 12500000, -12000000);
#endif

#if ASSERT_SUPPORT_FLOAT
    assert(Float, 2.5f, 2.5f);
    assertEq(Float, 2.5f, 2.5f);
    assertNe(Float, 2.5f, -2.5f);
#endif

#if ASSERT_SUPPORT_DOUBLE
    assert(Float, 2.5, 2.5);
    assertEq(Float, 2.5, 2.5);
    assertNe(Float, 2.5, -2.5);
#endif
}

#if ASSERT_SUPPORT_HOOK
void Assert_hook(Assert_Result* result) {
    ASSERT_PRINTF("Assert Hook");
}
#endif
