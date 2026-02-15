#include "Tokenizer.h"
#include <iostream>
using namespace std;

vector<Token> Tokenizer::tokenize(const string &html)
{
    vector<Token> tokens;
    int n = html.size();

    int i = 0;
    while (i < n)
    {
        if (html[i] == '<')
        {
            int close = html.find('>', i);
            if (close == string::npos)
                break;

            string tag = html.substr(i + 1, close - i - 1);

            if (!tag.empty() && tag[0] == '/')
            {
                tokens.push_back({TokenType::CLOSE_TAG, tag.substr(1)});
            }
            else
            {
                tokens.push_back({TokenType::OPEN_TAG, tag});
            }

            i = close + 1;
        }
        else
        {
            int nextTag = html.find('<', i);
            string text;

            if (nextTag == string::npos)
            {
                text = html.substr(i);
                i = n;
            }
            else
            {
                text = html.substr(i, nextTag - i);
                i = nextTag;
            }

            // remove useless whitespace
            bool onlySpaces = true;
            for (char c : text)
            {
                if (!isspace(c))
                {
                    onlySpaces = false;
                    break;
                }
            }

            if (!onlySpaces)
            {
                tokens.push_back({TokenType::TEXT, text});
            }
        }
    }

    return tokens;
}
