#ifndef DOMENODE_H
#define DOMENODE_H

#include <string>
#include <vector>
using namespace std;

class DOMNode
{
    public:
        string tagName;
        string textContent;
        vector<DOMNode* > children;   // This is to create dom tree for children tags

        DOMNode(const string& tag);
        ~DOMNode();

        void addChild(DOMNode* child);

};

#endif