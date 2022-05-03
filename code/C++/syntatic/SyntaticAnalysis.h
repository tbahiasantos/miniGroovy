#ifndef SYNTATIC_ANALYSIS_H
#define SYNTATIC_ANALYSIS_H

#include <map>
#include <stack>

#include "../lexical/LexicalAnalysis.h"

class Command;

class SyntaticAnalysis {
public:
    explicit SyntaticAnalysis(LexicalAnalysis& lex);
    virtual ~SyntaticAnalysis();

    Command* start();

private:
    LexicalAnalysis& m_lex;
    Lexeme m_current;
    std::stack<struct Lexeme> m_history;
    std::stack<struct Lexeme> m_queued;

    void rollback();
    void advance();
    void eat(enum TokenType type);
    void showError();

};

#endif
