#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>
#include "Token.h"
using namespace std;

class Tokenizer
{
    public:
        vector<Token> tokenize(const string& html);
};


#endif