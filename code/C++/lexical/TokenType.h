#ifndef TOKENTYPE_H
#define TOKENTYPE_H

enum TokenType {
    // SPECIALS
    TKN_UNEXPECTED_EOF = -2,
    TKN_INVALID_TOKEN = -1,
    TKN_END_OF_FILE = 0,

    // SYMBOLS

    // OPERATORS

    // KEYWORDS

    // OTHERS
    TKN_NAME,          // identifier
    TKN_NUMBER,        // integer
    TKN_TEXT           // string

};

#endif
