#include "Parser.h"
#include <stack>
#include <iostream>
using namespace std;

DOMNode* Parser::parse(const vector<Token>& tokens)
{
    DOMNode* root = new DOMNode("document");
    stack<DOMNode*> stack;
    stack.push(root);

    for (const auto& token : tokens)
    {
        if (token.type == TokenType::OPEN_TAG)
        {
            DOMNode* node = new DOMNode(token.value);
            stack.top()->addChild(node);
            stack.push(node);
        }
        else if (token.type == TokenType::TEXT)
        {
            stack.top()->textContent += token.value;
        }
        else if (token.type == TokenType::CLOSE_TAG)
        {
            if (stack.size() > 1)
                stack.pop();
        }
    }

    return root;
}
