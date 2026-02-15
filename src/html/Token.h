#ifndef TOKEN_H
#define TOKEN_H

#include <string>
using namespace std;

enum class TokenType
{
    OPEN_TAG,
    CLOSE_TAG,
    TEXT
};

struct Token
{
    TokenType type;
    string value;
};


#endif