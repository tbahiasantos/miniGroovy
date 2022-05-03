#ifndef NUMBER_VALUE_H
#define NUMBER_VALUE_H

#include "Value.h"

class NumberValue : public Value<int> {
public:
    NumberValue(int value);
    virtual ~NumberValue();

    virtual bool eval();
    virtual std::string str() const;
    virtual bool operator<(const Type& type) const;

    virtual int value();

private:
    int m_value;

};

#endif
