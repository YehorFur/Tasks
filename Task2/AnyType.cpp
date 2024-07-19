#include <iostream>
#include <typeinfo>
#include <typeindex>
#include <exception>
#include <stdexcept>
#include <memory>

class BadCastException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Bad cast exception";
    }
};

class AnyType {
public:
    AnyType() : content(nullptr), typeIndex(std::type_index(typeid(void))) {}

    template<typename T>
    AnyType(T value) : content(new Derived<T>(value)), typeIndex(std::type_index(typeid(T))) {}

    AnyType(const AnyType& other) : content(other.content ? other.content->clone() : nullptr), typeIndex(other.typeIndex) {}

    AnyType(AnyType&& other) noexcept : content(std::move(other.content)), typeIndex(other.typeIndex) {
        other.typeIndex = std::type_index(typeid(void));
    }

    ~AnyType() = default;

    AnyType& operator=(const AnyType& other) {
        if (this != &other) {
            content.reset(other.content ? other.content->clone() : nullptr);
            typeIndex = other.typeIndex;
        }
        return *this;
    }

    AnyType& operator=(AnyType&& other) noexcept {
        if (this != &other) {
            content = std::move(other.content);
            typeIndex = other.typeIndex;
            other.typeIndex = std::type_index(typeid(void));
        }
        return *this;
    }

    template<typename T>
    AnyType& operator=(T value) {
        content.reset(new Derived<T>(value));
        typeIndex = std::type_index(typeid(T));
        return *this;
    }


    void destroy() {
        content.reset();
        typeIndex = std::type_index(typeid(void));
    }

    void swap(AnyType& other) noexcept {
        std::swap(content, other.content);
        std::swap(typeIndex, other.typeIndex);
    }

    std::type_index getType() const noexcept {
        return typeIndex;
    }

    template<typename T>
    T to() const {
        if (typeIndex != std::type_index(typeid(T))) {
            throw BadCastException();
        }
        return static_cast<Derived<T>*>(content.get())->value;
    }

private:
    struct Base {
        virtual ~Base() = default;
        virtual Base* clone() const = 0;
    };

    template<typename T>
    struct Derived : Base {
        Derived(T value) : value(value) {}
        Base* clone() const override { return new Derived(value); }
        T value;
    };

    std::unique_ptr<Base> content;
    std::type_index typeIndex;
};

int main() {
    AnyType anyType = 1;

    anyType = true;

    anyType = 1.7;

    anyType = std::string("Hello");

    try {
        std::cout << anyType.to<std::string>() << std::endl;
    } catch (const BadCastException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << anyType.to<int>() << std::endl;
    } catch (const BadCastException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
