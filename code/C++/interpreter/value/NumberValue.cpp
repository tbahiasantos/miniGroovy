#include "NumberValue.h"
#include <sstream>

NumberValue::NumberValue(int value)
    : Value(Value::NumberType), m_value(value) {
}

NumberValue::~NumberValue() {
}

bool NumberValue::eval() {
    return m_value != 0;
}

std::string NumberValue::str() const {
    std::stringstream ss;
    ss << m_value;
    return ss.str();
}

bool NumberValue::operator<(const Type& type) const {
    switch (type.type()) {
        case Type::BooleanType:
            return false;
        case Type::NumberType:
            return m_value < ((const NumberValue&) type).m_value;
        default:
            return true;
    }
}

int NumberValue::value() {
    return m_value;
}
