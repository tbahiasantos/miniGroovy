#ifndef MAP_VALUE_H
#define MAP_VALUE_H

#include "Value.h"
#include <map>

class MapValue : public Value<std::map<std::string, Type*>*> {
public:
    MapValue(std::map<std::string, Type*>* value);
    virtual ~MapValue();

    virtual bool eval();
    virtual std::string str() const;
    virtual bool operator<(const Type& type) const;

    virtual std::map<std::string, Type*>* value();

private:
    std::map<std::string, Type*>* m_value;

};

#endif
