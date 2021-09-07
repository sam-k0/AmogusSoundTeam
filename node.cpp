#include "node.h"


node::node()
{
    data = 0;
    prev = nullptr;
    next = nullptr;
}

node::node(int d)
{
    data = d;
    prev = nullptr;
    next = nullptr;
}

bool node::hasNext()
{
    return next;
}

bool node::hasPrev()
{
    return prev;
}

void node::clear()
{
    prev = nullptr;
    next = nullptr;
}

/// get und set
int node::getData()
{
    return data;
}

void node::setData(const int value)
{
    data = value;
}

node* node::getNext()
{
    return next;
}

node* node::getPrev()
{
    return prev;
}

void node::setPrev(node *n)
{
    prev = n;
}

void node::setNext(node *n)
{
    next = n;
}

