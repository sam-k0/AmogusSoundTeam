#ifndef LIST_H
#define LIST_H
#include "node.h"

class list
{
private:
    node* first;
    node* last;
    node* current;

public:
    list();

    node *getFirst() const;
    void setFirst(node *value);

    node *getLast() const;
    void setLast(node *value);

    node *getCurrent() const;
    void setCurrent(node *value);

    void add(node* n);
    void swap(node* a, node* b);
    void addend(node* n);
    int length();
    bool empty();
    void addSorted(node* n);
    void del(node* n);
    void delcurr();
    void delpos(int pos);
    node* getNodePos(int pos);
    node* remove(node* n);

    int getPosFromNode(node* n);

    void mergeLists(list* add);
    list* splitLists();
    list* mergesort();

    void selectionsort();

    void quicksort(int left, int right);

    void printlist(node* start);

    bool adv();
    bool ret();
    void reset();
};

#endif // LIST_H
