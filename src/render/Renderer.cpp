#include "Renderer.h"
#include <iostream>
using namespace std;

void printNode(DOMNode* node, int depth)
{
    for (int i = 0; i < depth; i++)
        cout << "  ";

    cout << "<" << node->tagName << "> ";

    if (!node->textContent.empty())
        cout << node->textContent;

    cout << endl;

    for (auto child : node->children)
        printNode(child, depth + 1);
}

void Renderer::render(DOMNode* root)
{
    cout << "=== Rendering DOM Tree ===" << endl;
    printNode(root, 0);
}
