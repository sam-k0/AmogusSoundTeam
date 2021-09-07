#ifndef NODE_H
#define NODE_H


class node
{
private:
    int data;
    node* prev;
    node* next;

public:
    node();
    node(int d);

    void setPrev(node* n);
    void setNext(node* n);
    void setData(const int value);

    node* getNext();
    node* getPrev();
    int getData();

    // QOL
    bool hasNext();
    bool hasPrev();
    void clear();
};

#endif // NODE_H
