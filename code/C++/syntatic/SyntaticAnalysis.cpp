#include <cstdlib>
#include <cassert>

#include "SyntaticAnalysis.h"
#include "../interpreter/command/Command.h"

SyntaticAnalysis::SyntaticAnalysis(LexicalAnalysis& lex) :
    m_lex(lex), m_current(m_lex.nextToken()) {
}

SyntaticAnalysis::~SyntaticAnalysis() {
}

Command* SyntaticAnalysis::start() {
    return 0;
}

void SyntaticAnalysis::rollback() {
    assert(!m_history.empty());

    // printf("Rollback (\"%s\", %d)\n",
    //     m_current.token.c_str(), m_current.type);
    m_queued.push(m_current);
    m_current = m_history.top();
    m_history.pop();
}

void SyntaticAnalysis::advance() {
    // printf("Advanced (\"%s\", %d)\n",
    //     m_current.token.c_str(), m_current.type);
    m_history.push(m_current);
    if (m_queued.empty()) {
        m_current = m_lex.nextToken();
    } else {
        m_current = m_queued.top();
        m_queued.pop();
    }
}

void SyntaticAnalysis::eat(enum TokenType type) {
    // printf("Expected (..., %d), found (\"%s\", %d)\n",
    //     type, m_current.token.c_str(), m_current.type);
    if (type == m_current.type) {
        m_history.push(m_current);
        if (m_queued.empty()) {
            m_current = m_lex.nextToken();
        } else {
            m_current = m_queued.top();
            m_queued.pop();
        }
    } else {
        showError();
    }
}

void SyntaticAnalysis::showError() {
    printf("%02d: ", m_lex.line());

    switch (m_current.type) {
        case TKN_INVALID_TOKEN:
            printf("Lexema inválido [%s]\n", m_current.token.c_str());
            break;
        case TKN_UNEXPECTED_EOF:
        case TKN_END_OF_FILE:
            printf("Fim de arquivo inesperado\n");
            break;
        default:
            printf("Lexema não esperado [%s]\n", m_current.token.c_str());
            break;
    }

    exit(1);
}
