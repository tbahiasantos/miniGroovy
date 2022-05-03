#include "BooleanValue.h"

BooleanValue::BooleanValue(bool value)
        : Value(Value::BooleanType), m_value(value) {
}

BooleanValue::~BooleanValue() {
}

bool BooleanValue::eval() {
    return m_value;
}

std::string BooleanValue::str() const {
    return m_value ? "true" : "false";
}

bool BooleanValue::operator<(const Type& type) const {
    switch (type.type()) {
        case Type::BooleanType:
            return m_value < ((const BooleanValue&) type).m_value;
        default:
            return true;
    }
}

bool BooleanValue::value() {
    return m_value;
}
