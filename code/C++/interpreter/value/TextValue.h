#ifndef TEXT_VALUE_H
#define TEXT_VALUE_H

#include "Value.h"
#include <string>

class TextValue : public Value<std::string> {
public:
    TextValue(const std::string& value);
    virtual ~TextValue();

    virtual bool eval();
    virtual std::string str() const;
    virtual bool operator<(const Type& type) const;

    virtual std::string value();

private:
    std::string m_value;

};

#endif
