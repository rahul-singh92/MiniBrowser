#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include "Token.h"
#include "DOMNode.h"
using namespace std;

class Parser
{
    public:
        DOMNode* parse(const vector<Token>& tokens);
};

#endif