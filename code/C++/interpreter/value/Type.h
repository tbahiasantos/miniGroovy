#ifndef TYPE_H
#define TYPE_H

#include <string>

class Type {
    public:
        enum ValueType {
            BooleanType,
            NumberType,
            TextType,
            ArrayType,
            MapType
        };

        Type(Type::ValueType type) : m_type(type) {}
        virtual ~Type() {}

        Type::ValueType type() const { return m_type; }

        virtual bool eval() = 0;
        virtual std::string str() const = 0;
        virtual bool operator<(const Type& type) const = 0;

    private:
        Type::ValueType m_type;

};

namespace std  {
    template<>
    struct less<Type*> {
        bool operator()(const Type* lhs, const Type* rhs) const {
            return *lhs < *rhs;
        }
    };
}

#endif
