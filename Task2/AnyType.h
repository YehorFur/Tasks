#include <stdexcept>
#include <cstring>

enum class FundamentalType {
    None,
    Int,
    Float,
    Double,
    Bool,
    Char,
    UnsignedChar,
    ShortInt,
    UnsignedShortInt,
    LongInt,
    UnsignedLongInt,
    LongLongInt,
    UnsignedLongLongInt,
    LongDouble,
    WChar,
    Char16,
    Char32
};

class BadCastException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Bad cast exception";
    }
};

class AnyType {
public:
    AnyType(int i);
    AnyType(float f);
    AnyType(double d);
    AnyType(bool b);
    AnyType(char c);
    AnyType(unsigned char uc);
    AnyType(short int si);
    AnyType(unsigned short int usi);
    AnyType(long int li);
    AnyType(unsigned long int uli);
    AnyType(long long int lli);
    AnyType(unsigned long long int ulli);
    AnyType(long double ld);
    AnyType(wchar_t wc);
    AnyType(char16_t c16);
    AnyType(char32_t c32);

    AnyType(const AnyType& other);

    AnyType(AnyType&& other) noexcept;

    ~AnyType();

    AnyType() noexcept : type(FundamentalType::None) { clear(); }
    
    AnyType& operator=(const AnyType &);
    AnyType& operator=(AnyType&&) noexcept;
    AnyType& operator=(int i);
    AnyType& operator=(float f);
    AnyType& operator=(double d);
    AnyType& operator=(bool b);
    AnyType& operator=(char c);
    AnyType& operator=(unsigned char uc);
    AnyType& operator=(short int si);
    AnyType& operator=(unsigned short int usi);
    AnyType& operator=(long int li);
    AnyType& operator=(unsigned long int uli);
    AnyType& operator=(long long int lli);
    AnyType& operator=(unsigned long long int ulli);
    AnyType& operator=(long double ld);
    AnyType& operator=(wchar_t wc);
    AnyType& operator=(char16_t c16);
    AnyType& operator=(char32_t c32);

    operator int() const;
    operator float() const;
    operator double() const;
    operator bool() const;
    operator char() const;
    operator unsigned char() const;
    operator short int() const;
    operator unsigned short int() const;
    operator long int() const;
    operator unsigned long int() const;
    operator long long int() const;
    operator unsigned long long int() const;
    operator long double() const;
    operator wchar_t() const;
    operator char16_t() const;
    operator char32_t() const;

    FundamentalType getType() const;

    void clear();

private:
    FundamentalType type;
    char value[16];

    void setValue(int i);
    void setValue(float f);
    void setValue(double d);
    void setValue(bool b);
    void setValue(char c);
    void setValue(unsigned char uc);
    void setValue(short int si);
    void setValue(unsigned short int usi);
    void setValue(long int li);
    void setValue(unsigned long int uli);
    void setValue(long long int lli);
    void setValue(unsigned long long int ulli);
    void setValue(long double ld);
    void setValue(wchar_t wc);
    void setValue(char16_t c16);
    void setValue(char32_t c32);

    void copyValue(const AnyType& other);
    void moveValue(AnyType&& other) noexcept;
};