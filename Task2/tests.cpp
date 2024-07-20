#include "gtest/gtest.h"

#include "AnyType.h"

TEST(AnyTypeTest, IntConstructor) {
    AnyType any(42);
    EXPECT_EQ(any.getType(), FundamentalType::Int);
    EXPECT_EQ(static_cast<int>(any), 42);
}

TEST(AnyTypeTest, FloatConstructor) {
    AnyType any(3.14f);
    EXPECT_EQ(any.getType(), FundamentalType::Float);
    EXPECT_FLOAT_EQ(static_cast<float>(any), 3.14f);
}

TEST(AnyTypeTest, DoubleConstructor) {
    AnyType any(2.718);
    EXPECT_EQ(any.getType(), FundamentalType::Double);
    EXPECT_DOUBLE_EQ(static_cast<double>(any), 2.718);
}

TEST(AnyTypeTest, BoolConstructor) {
    AnyType any(true);
    EXPECT_EQ(any.getType(), FundamentalType::Bool);
    EXPECT_TRUE(static_cast<bool>(any));
}

TEST(AnyTypeTest, CharConstructor) {
    AnyType any('a');
    EXPECT_EQ(any.getType(), FundamentalType::Char);
    EXPECT_EQ(static_cast<char>(any), 'a');
}

TEST(AnyTypeTest, UnsignedCharConstructor) {
    AnyType any(static_cast<unsigned char>(255));
    EXPECT_EQ(any.getType(), FundamentalType::UnsignedChar);
    EXPECT_EQ(static_cast<unsigned char>(any), 255);
}

TEST(AnyTypeTest, ShortIntConstructor) {
    AnyType any(static_cast<short int>(-12345));
    EXPECT_EQ(any.getType(), FundamentalType::ShortInt);
    EXPECT_EQ(static_cast<short int>(any), -12345);
}

TEST(AnyTypeTest, UnsignedShortIntConstructor) {
    AnyType any(static_cast<unsigned short int>(54321));
    EXPECT_EQ(any.getType(), FundamentalType::UnsignedShortInt);
    EXPECT_EQ(static_cast<unsigned short int>(any), 54321);
}

TEST(AnyTypeTest, LongIntConstructor) {
    AnyType any(static_cast<long int>(123456789L));
    EXPECT_EQ(any.getType(), FundamentalType::LongInt);
    EXPECT_EQ(static_cast<long int>(any), 123456789L);
}

TEST(AnyTypeTest, UnsignedLongIntConstructor) {
    AnyType any(static_cast<unsigned long int>(987654321UL));
    EXPECT_EQ(any.getType(), FundamentalType::UnsignedLongInt);
    EXPECT_EQ(static_cast<unsigned long int>(any), 987654321UL);
}

TEST(AnyTypeTest, LongLongIntConstructor) {
    AnyType any(static_cast<long long int>(1234567890123456789LL));
    EXPECT_EQ(any.getType(), FundamentalType::LongLongInt);
    EXPECT_EQ(static_cast<long long int>(any), 1234567890123456789LL);
}

TEST(AnyTypeTest, UnsignedLongLongIntConstructor) {
    AnyType any(static_cast<unsigned long long int>(9876543210987654321ULL));
    EXPECT_EQ(any.getType(), FundamentalType::UnsignedLongLongInt);
    EXPECT_EQ(static_cast<unsigned long long int>(any), 9876543210987654321ULL);
}

TEST(AnyTypeTest, LongDoubleConstructor) {
    AnyType any(1.234567890123456789L);
    EXPECT_EQ(any.getType(), FundamentalType::LongDouble);
    EXPECT_DOUBLE_EQ(static_cast<long double>(any), 1.234567890123456789L);
}

TEST(AnyTypeTest, WCharConstructor) {
    AnyType any(L'a');
    EXPECT_EQ(any.getType(), FundamentalType::WChar);
    EXPECT_EQ(static_cast<wchar_t>(any), L'a');
}

TEST(AnyTypeTest, Char16Constructor) {
    AnyType any(u'a');
    EXPECT_EQ(any.getType(), FundamentalType::Char16);
    EXPECT_EQ(static_cast<char16_t>(any), u'a');
}

TEST(AnyTypeTest, Char32Constructor) {
    AnyType any(U'a');
    EXPECT_EQ(any.getType(), FundamentalType::Char32);
    EXPECT_EQ(static_cast<char32_t>(any), U'a');
}

TEST(AnyTypeTest, CopyConstructor) {
    AnyType any1(42);
    AnyType any2(any1);
    EXPECT_EQ(any2.getType(), FundamentalType::Int);
    EXPECT_EQ(static_cast<int>(any2), 42);
}

TEST(AnyTypeTest, MoveConstructor) {
    AnyType any1(42);
    AnyType any2(std::move(any1));
    EXPECT_EQ(any2.getType(), FundamentalType::Int);
    EXPECT_EQ(static_cast<int>(any2), 42);
    EXPECT_EQ(any1.getType(), FundamentalType::None);
}

TEST(AnyTypeTest, AssignmentOperatorInt) {
    AnyType any;
    any = 42;
    EXPECT_EQ(any.getType(), FundamentalType::Int);
    EXPECT_EQ(static_cast<int>(any), 42);
}

TEST(AnyTypeTest, AssignmentOperatorFloat) {
    AnyType any;
    any = 3.14f;
    EXPECT_EQ(any.getType(), FundamentalType::Float);
    EXPECT_FLOAT_EQ(static_cast<float>(any), 3.14f);
}

TEST(AnyTypeTest, AssignmentOperatorDouble) {
    AnyType any;
    any = 2.718;
    EXPECT_EQ(any.getType(), FundamentalType::Double);
    EXPECT_DOUBLE_EQ(static_cast<double>(any), 2.718);
}

TEST(AnyTypeTest, AssignmentOperatorBool) {
    AnyType any;
    any = true;
    EXPECT_EQ(any.getType(), FundamentalType::Bool);
    EXPECT_TRUE(static_cast<bool>(any));
}

TEST(AnyTypeTest, AssignmentOperatorChar) {
    AnyType any;
    any = 'a';
    EXPECT_EQ(any.getType(), FundamentalType::Char);
    EXPECT_EQ(static_cast<char>(any), 'a');
}

TEST(AnyTypeTest, AssignmentOperatorUnsignedChar) {
    AnyType any;
    any = static_cast<unsigned char>(255);
    EXPECT_EQ(any.getType(), FundamentalType::UnsignedChar);
    EXPECT_EQ(static_cast<unsigned char>(any), 255);
}

TEST(AnyTypeTest, AssignmentOperatorShortInt) {
    AnyType any;
    any = static_cast<short int>(-12345);
    EXPECT_EQ(any.getType(), FundamentalType::ShortInt);
    EXPECT_EQ(static_cast<short int>(any), -12345);
}

TEST(AnyTypeTest, AssignmentOperatorUnsignedShortInt) {
    AnyType any;
    any = static_cast<unsigned short int>(54321);
    EXPECT_EQ(any.getType(), FundamentalType::UnsignedShortInt);
    EXPECT_EQ(static_cast<unsigned short int>(any), 54321);
}

TEST(AnyTypeTest, AssignmentOperatorLongInt) {
    AnyType any;
    any = static_cast<long int>(123456789L);
    EXPECT_EQ(any.getType(), FundamentalType::LongInt);
    EXPECT_EQ(static_cast<long int>(any), 123456789L);
}

TEST(AnyTypeTest, AssignmentOperatorUnsignedLongInt) {
    AnyType any;
    any = static_cast<unsigned long int>(987654321UL);
    EXPECT_EQ(any.getType(), FundamentalType::UnsignedLongInt);
    EXPECT_EQ(static_cast<unsigned long int>(any), 987654321UL);
}

TEST(AnyTypeTest, AssignmentOperatorLongLongInt) {
    AnyType any;
    any = static_cast<long long int>(1234567890123456789LL);
    EXPECT_EQ(any.getType(), FundamentalType::LongLongInt);
    EXPECT_EQ(static_cast<long long int>(any), 1234567890123456789LL);
}

TEST(AnyTypeTest, AssignmentOperatorUnsignedLongLongInt) {
    AnyType any;
    any = static_cast<unsigned long long int>(9876543210987654321ULL);
    EXPECT_EQ(any.getType(), FundamentalType::UnsignedLongLongInt);
    EXPECT_EQ(static_cast<unsigned long long int>(any), 9876543210987654321ULL);
}

TEST(AnyTypeTest, AssignmentOperatorLongDouble) {
    AnyType any;
    any = 1.234567890123456789L;
    EXPECT_EQ(any.getType(), FundamentalType::LongDouble);
    EXPECT_DOUBLE_EQ(static_cast<long double>(any), 1.234567890123456789L);
}

TEST(AnyTypeTest, AssignmentOperatorWChar) {
    AnyType any;
    any = L'a';
    EXPECT_EQ(any.getType(), FundamentalType::WChar);
    EXPECT_EQ(static_cast<wchar_t>(any), L'a');
}

TEST(AnyTypeTest, AssignmentOperatorChar16) {
    AnyType any;
    any = u'a';
    EXPECT_EQ(any.getType(), FundamentalType::Char16);
    EXPECT_EQ(static_cast<char16_t>(any), u'a');
}

TEST(AnyTypeTest, AssignmentOperatorChar32) {
    AnyType any;
    any = U'a';
    EXPECT_EQ(any.getType(), FundamentalType::Char32);
    EXPECT_EQ(static_cast<char32_t>(any), U'a');
}

TEST(AnyTypeTest, CopyAssignmentOperator) {
    AnyType any1(42);
    AnyType any2;
    any2 = any1;
    EXPECT_EQ(any2.getType(), FundamentalType::Int);
    EXPECT_EQ(static_cast<int>(any2), 42);
}

TEST(AnyTypeTest, MoveAssignmentOperator) {
    AnyType any1(42);
    AnyType any2;
    any2 = std::move(any1);
    EXPECT_EQ(any2.getType(), FundamentalType::Int);
    EXPECT_EQ(static_cast<int>(any2), 42);
    EXPECT_EQ(any1.getType(), FundamentalType::None); 
}

TEST(AnyTypeTest, Destructor) {
    AnyType* any = new AnyType(42);
    delete any;
}

TEST(AnyTypeTest, TypeConversionInt) {
    AnyType any(42);
    EXPECT_NO_THROW(static_cast<int>(any));
    EXPECT_THROW(static_cast<double>(any), BadCastException);
}

TEST(AnyTypeTest, TypeConversionFloat) {
    AnyType any(3.14f);
    EXPECT_NO_THROW(static_cast<float>(any));
    EXPECT_THROW(static_cast<int>(any), BadCastException);
}

TEST(AnyTypeTest, BadCast) {
    AnyType any(42);
    EXPECT_THROW(static_cast<double>(any), BadCastException);
}

TEST(AnyTypeTest, GetType) {
    AnyType any(42);
    EXPECT_EQ(any.getType(), FundamentalType::Int);
    any = 3.14f;
    EXPECT_EQ(any.getType(), FundamentalType::Float);
}

TEST(AnyTypeTest, ConversionOperatorInt) {
    AnyType any(42);
    int value = any;
    EXPECT_EQ(value, 42);
}

TEST(AnyTypeTest, ConversionOperatorFloat) {
    AnyType any(3.14f);
    float value = any;
    EXPECT_FLOAT_EQ(value, 3.14f);
}

TEST(AnyTypeTest, ConversionOperatorDouble) {
    AnyType any(2.718);
    double value = any;
    EXPECT_DOUBLE_EQ(value, 2.718);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}