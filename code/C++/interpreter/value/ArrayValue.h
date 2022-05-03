#ifndef ARRAY_VALUE_H
#define ARRAY_VALUE_H

#include "Value.h"
#include <list>

class ArrayValue : public Value<std::list<Type*>*> {
public:
    ArrayValue(std::list<Type*>* value);
    virtual ~ArrayValue();

    virtual bool eval();
    virtual std::string str() const;
    virtual bool operator<(const Type& type) const;

    virtual std::list<Type*>* value();

private:
    std::list<Type*>* m_value;

};

#endif
