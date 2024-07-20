#include "AnyType.h"

AnyType::AnyType(int i) : type(FundamentalType::Int) { setValue(i); }
AnyType::AnyType(float f) : type(FundamentalType::Float) { setValue(f); }
AnyType::AnyType(double d) : type(FundamentalType::Double) { setValue(d); }
AnyType::AnyType(bool b) : type(FundamentalType::Bool) { setValue(b); }
AnyType::AnyType(char c) : type(FundamentalType::Char) { setValue(c); }
AnyType::AnyType(unsigned char uc) : type(FundamentalType::UnsignedChar) { setValue(uc); }
AnyType::AnyType(short int si) : type(FundamentalType::ShortInt) { setValue(si); }
AnyType::AnyType(unsigned short int usi) : type(FundamentalType::UnsignedShortInt) { setValue(usi); }
AnyType::AnyType(long int li) : type(FundamentalType::LongInt) { setValue(li); }
AnyType::AnyType(unsigned long int uli) : type(FundamentalType::UnsignedLongInt) { setValue(uli); }
AnyType::AnyType(long long int lli) : type(FundamentalType::LongLongInt) { setValue(lli); }
AnyType::AnyType(unsigned long long int ulli) : type(FundamentalType::UnsignedLongLongInt) { setValue(ulli); }
AnyType::AnyType(long double ld) : type(FundamentalType::LongDouble) { setValue(ld); }
AnyType::AnyType(wchar_t wc) : type(FundamentalType::WChar) { setValue(wc); }
AnyType::AnyType(char16_t c16) : type(FundamentalType::Char16) { setValue(c16); }
AnyType::AnyType(char32_t c32) : type(FundamentalType::Char32) { setValue(c32); }

AnyType::AnyType(const AnyType& other) : type(other.type) {
    copyValue(other);
}

AnyType::AnyType(AnyType&& other) noexcept : type(other.type) {
    moveValue(std::move(other));
}

AnyType::~AnyType() {
    clear();
}

AnyType& AnyType::operator=(int i) { type = FundamentalType::Int; setValue(i); return *this; }
AnyType& AnyType::operator=(float f) { type = FundamentalType::Float; setValue(f); return *this; }
AnyType& AnyType::operator=(double d) { type = FundamentalType::Double; setValue(d); return *this; }
AnyType& AnyType::operator=(bool b) { type = FundamentalType::Bool; setValue(b); return *this; }
AnyType& AnyType::operator=(char c) { type = FundamentalType::Char; setValue(c); return *this; }
AnyType& AnyType::operator=(unsigned char uc) { type = FundamentalType::UnsignedChar; setValue(uc); return *this; }
AnyType& AnyType::operator=(short int si) { type = FundamentalType::ShortInt; setValue(si); return *this; }
AnyType& AnyType::operator=(unsigned short int usi) { type = FundamentalType::UnsignedShortInt; setValue(usi); return *this; }
AnyType& AnyType::operator=(long int li) { type = FundamentalType::LongInt; setValue(li); return *this; }
AnyType& AnyType::operator=(unsigned long int uli) { type = FundamentalType::UnsignedLongInt; setValue(uli); return *this; }
AnyType& AnyType::operator=(long long int lli) { type = FundamentalType::LongLongInt; setValue(lli); return *this; }
AnyType& AnyType::operator=(unsigned long long int ulli) { type = FundamentalType::UnsignedLongLongInt; setValue(ulli); return *this; }
AnyType& AnyType::operator=(long double ld) { type = FundamentalType::LongDouble; setValue(ld); return *this; }
AnyType& AnyType::operator=(wchar_t wc) { type = FundamentalType::WChar; setValue(wc); return *this; }
AnyType& AnyType::operator=(char16_t c16) { type = FundamentalType::Char16; setValue(c16); return *this; }
AnyType& AnyType::operator=(char32_t c32) { type = FundamentalType::Char32; setValue(c32); return *this; }

AnyType& AnyType::operator=(const AnyType& other) {
    if (this != &other) {
        clear();
        type = other.type;
        copyValue(other);
    }
    return *this;
}

AnyType& AnyType::operator=(AnyType&& other) noexcept {
    if (this != &other) {
        clear();
        type = other.type;
        moveValue(std::move(other));
    }
    return *this;
}

AnyType::operator int() const {
    if (type != FundamentalType::Int) throw BadCastException();
    return *reinterpret_cast<const int*>(value);
}

AnyType::operator float() const {
    if (type != FundamentalType::Float) throw BadCastException();
    return *reinterpret_cast<const float*>(value);
}

AnyType::operator double() const {
    if (type != FundamentalType::Double) throw BadCastException();
    return *reinterpret_cast<const double*>(value);
}

AnyType::operator bool() const {
    if (type != FundamentalType::Bool) throw BadCastException();
    return *reinterpret_cast<const bool*>(value);
}

AnyType::operator char() const {
    if (type != FundamentalType::Char) throw BadCastException();
    return *reinterpret_cast<const char*>(value);
}

AnyType::operator unsigned char() const {
    if (type != FundamentalType::UnsignedChar) throw BadCastException();
    return *reinterpret_cast<const unsigned char*>(value);
}

AnyType::operator short int() const {
    if (type != FundamentalType::ShortInt) throw BadCastException();
    return *reinterpret_cast<const short int*>(value);
}

AnyType::operator unsigned short int() const {
    if (type != FundamentalType::UnsignedShortInt) throw BadCastException();
    return *reinterpret_cast<const unsigned short int*>(value);
}

AnyType::operator long int() const {
    if (type != FundamentalType::LongInt) throw BadCastException();
    return *reinterpret_cast<const long int*>(value);
}

AnyType::operator unsigned long int() const {
    if (type != FundamentalType::UnsignedLongInt) throw BadCastException();
    return *reinterpret_cast<const unsigned long int*>(value);
}

AnyType::operator long long int() const {
    if (type != FundamentalType::LongLongInt) throw BadCastException();
    return *reinterpret_cast<const long long int*>(value);
}

AnyType::operator unsigned long long int() const {
    if (type != FundamentalType::UnsignedLongLongInt) throw BadCastException();
    return *reinterpret_cast<const unsigned long long int*>(value);
}

AnyType::operator long double() const {
    if (type != FundamentalType::LongDouble) throw BadCastException();
    return *reinterpret_cast<const long double*>(value);
}

AnyType::operator wchar_t() const {
    if (type != FundamentalType::WChar) throw BadCastException();
    return *reinterpret_cast<const wchar_t*>(value);
}

AnyType::operator char16_t() const {
    if (type != FundamentalType::Char16) throw BadCastException();
    return *reinterpret_cast<const char16_t*>(value);
}

AnyType::operator char32_t() const {
    if (type != FundamentalType::Char32) throw BadCastException();
    return *reinterpret_cast<const char32_t*>(value);
}

FundamentalType AnyType::getType() const {
    return type;
}

void AnyType::clear() {
    std::memset(value, 0, sizeof(value));
    std::memset(&type, 0, sizeof(type));
}

void AnyType::setValue(int i) {
    new (value) int(i);
}

void AnyType::setValue(float f) {
    new (value) float(f);
}

void AnyType::setValue(double d) {
    new (value) double(d);
}

void AnyType::setValue(bool b) {
    new (value) bool(b);
}

void AnyType::setValue(char c) {
    new (value) char(c);
}

void AnyType::setValue(unsigned char uc) {
    new (value) unsigned char(uc);
}

void AnyType::setValue(short int si) {
    new (value) short int(si);
}

void AnyType::setValue(unsigned short int usi) {
    new (value) unsigned short int(usi);
}

void AnyType::setValue(long int li) {
    new (value) long int(li);
}

void AnyType::setValue(unsigned long int uli) {
    new (value) unsigned long int(uli);
}

void AnyType::setValue(long long int lli) {
    new (value) long long int(lli);
}

void AnyType::setValue(unsigned long long int ulli) {
    new (value) unsigned long long int(ulli);
}

void AnyType::setValue(long double ld) {
    new (value) long double(ld);
}

void AnyType::setValue(wchar_t wc) {
    new (value) wchar_t(wc);
}

void AnyType::setValue(char16_t c16) {
    new (value) char16_t(c16);
}

void AnyType::setValue(char32_t c32) {
    new (value) char32_t(c32);
}

void AnyType::copyValue(const AnyType& other) {
    clear();
    std::memcpy(value, other.value, sizeof(value));
    std::memcpy(&type, &other.type, sizeof(type));
}

void AnyType::moveValue(AnyType&& other) noexcept {
    clear();
    std::memcpy(value, other.value, sizeof(value));
    std::memcpy(&type, &other.type, sizeof(type));
    other.clear();
}