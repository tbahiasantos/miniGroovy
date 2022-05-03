#include "Memory.h"

std::map<std::string, Type*> Memory::m_memory;

Type* Memory::read(std::string name) {
    return m_memory[name];
}

void Memory::write(std::string name, Type* value) {
    m_memory[name] = value;
}
