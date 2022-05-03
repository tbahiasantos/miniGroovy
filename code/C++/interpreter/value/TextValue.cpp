#include "TextValue.h"

TextValue::TextValue(const std::string& value)
    : Value(Value::TextType), m_value(value) {
}

TextValue::~TextValue() {
}

bool TextValue::eval() {
    return !m_value.empty();
}

std::string TextValue::str() const {
    return m_value;
}

bool TextValue::operator<(const Type& type) const {
    switch (type.type()) {
        case Type::BooleanType:
        case Type::NumberType:
            return false;
        case Type::TextType:
            return m_value < ((const TextValue&) type).m_value;
        default:
            return true;
    }
}

std::string TextValue::value() {
    return m_value;
}
