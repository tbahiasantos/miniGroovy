#include "SymbolTable.h"

SymbolTable::SymbolTable() {
    // SYMBOLS

    // OPERATORS

    // KEYWORDS
}

SymbolTable::~SymbolTable() {
}

bool SymbolTable::contains(std::string token) {
    return m_st.find(token) != m_st.end();
}

enum TokenType SymbolTable::find(std::string token) {
    return this->contains(token) ? m_st[token] : TKN_NAME;
}
