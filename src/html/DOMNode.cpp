#include "DOMNode.h"

DOMNode::DOMNode(const std::string &tag)
{
    tagName = tag;
}

DOMNode::~DOMNode()
{
    for (auto child : children)
        delete child;
}

void DOMNode::addChild(DOMNode *child)
{
    children.push_back(child);
}
