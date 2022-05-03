#ifndef BOOLEAN_VALUE_H
#define BOOLEAN_VALUE_H

#include "Value.h"

class BooleanValue : public Value<bool> {
public:
    BooleanValue(bool value);
    virtual ~BooleanValue();

    virtual bool eval();
    virtual std::string str() const;
    virtual bool operator<(const Type& type) const;

    virtual bool value();

private:
    bool m_value;

};

#endif
