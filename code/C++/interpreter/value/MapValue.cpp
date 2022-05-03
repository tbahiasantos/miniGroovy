#include "MapValue.h"
#include <sstream>

MapValue::MapValue(std::map<std::string, Type*>* value)
    : Value(Value::MapType), m_value(value) {
}

MapValue::~MapValue() {
}

bool MapValue::eval() {
    return !m_value->empty();
}

std::string MapValue::str() const {
    std::stringstream ss;
    ss << "[";

    if (m_value->empty()) {
        ss << ":";
    } else {
        for (std::map<std::string, Type*>::const_iterator it = m_value->cbegin(),
                ed = m_value->cend(); it != ed; it++) {
            std::string key = it->first;
            Type* value = it->second;

            if (it != m_value->cbegin())
                ss << ", ";

            ss << key;
            ss << ":";
            ss << (value ? value->str() : "null");
        }
    }

    ss << "]";
    return ss.str();
}

bool MapValue::operator<(const Type& type) const {
    switch (type.type()) {
        case Type::BooleanType:
        case Type::NumberType:
        case Type::TextType:
        case Type::ArrayType:
            return false;
        case Type::MapType:
        default:
            return m_value < ((const MapValue&) type).m_value;
    }
}

std::map<std::string, Type*>* MapValue::value() {
    return m_value;
}
