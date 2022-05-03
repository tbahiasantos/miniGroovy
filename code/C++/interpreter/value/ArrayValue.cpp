#include "ArrayValue.h"
#include <sstream>

ArrayValue::ArrayValue(std::list<Type*>* value)
    : Value(Value::ArrayType), m_value(value) {
}

ArrayValue::~ArrayValue() {
}

bool ArrayValue::eval() {
    return !m_value->empty();
}

std::string ArrayValue::str() const {
    std::stringstream ss;
    ss << "[";

    for (std::list<Type*>::const_iterator it = m_value->cbegin(),
            ed = m_value->cend(); it != ed; it++) {
        Type* value = *it;

        if (it != m_value->cbegin())
            ss << ", ";

        ss << (value ? value->str() : "null");
    }

    ss << "]";
    return ss.str();
}

bool ArrayValue::operator<(const Type& type) const {
    switch (type.type()) {
        case Type::BooleanType:
        case Type::NumberType:
        case Type::TextType:
            return false;
        case Type::ArrayType:
            return m_value < ((const ArrayValue&) type).m_value;
        default:
            return true;
    }
}

std::list<Type*>* ArrayValue::value() {
    return m_value;
}
