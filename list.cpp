#include "list.h"
#include <iostream>
#include "math.h"

using namespace std;

list::list()
{
    current = nullptr;
    first = nullptr;
    last = nullptr;
}
/// Utility
void list::add(node *n)
{
    if(!current && !last && !first)
    {
        current = n;
        first = n;
        last = n;
        return;
    }

    if(current == first)
    {
        current->setPrev(n);
        n->setNext(current);
        n->setPrev(nullptr);
        first = n;
        current = n;
        return;
    }

    node* cprev = current->getPrev();

    cprev->setNext(n);

    n->setPrev(cprev);
    n->setNext(current);
    current->setPrev(n);
    current = n;


}

void list::swap(node *a, node *b)
{
    int aval = a->getData();
    int bval = b->getData();

    a->setData(bval);
    b->setData(aval);

}

void list::addend(node *n)
{
    if(empty())
    {
        first = n;
        last = n;
        current = n;
        return;
    }

    last->setNext(n);
    n->setPrev(last);
    last = n;
    current = n;
}

int list::length()
{
    node* oldcurr = current;
    reset();

    int i = 0;

    if(empty())
    {
       return 0;
    }
    i = 1;
    while(adv())
    {
        i++;
    }
    current = oldcurr;
    return i;
}

bool list::empty()
{
    return !first;
}

void list::addSorted(node* n)
{
    reset();
    if(empty()) // node is first node in list
    {
        add(n);
        return;
    }

    // Catch case that n has to be first
    if(first->getData() > n->getData())
    {
        first->setPrev(n);
        n->setNext(first);
        first = n;
        return;
    }

    bool couldadv = true;
    node* currnext = nullptr;
    while(couldadv)
    {
        currnext = current->getNext();

        if(currnext == nullptr)
        {
            addend(n);
            last = n;
            return;
        }

        if(n->getData() >= current->getData() && n->getData() < currnext->getData())
        {
            current->setNext(n);
            currnext->setPrev(n);
            n->setPrev(current);
            n->setNext(currnext);
            return;
        }

        couldadv = adv();
    }

    // Fucking kill me was ist da falsch
    last->setNext(n);
    n->setPrev(last);
    last = n;
    return;

}

void list::del(node *n)
{
    if(n == first)
    {
        if(n->getNext() != nullptr)
        {
            n->getNext()->setPrev(nullptr);
            first = n->getNext();
            current = first;
            delete n;
            return;
        }
        else // it was the only node
        {
            first = nullptr;
            last = nullptr;
            current = nullptr;
            return;
        }
    }

    if(n == last)
    {
        n->getPrev()->setNext(nullptr);
        last = n->getPrev();
        current = last;
        delete n;
        return;
    }

    if(n->getPrev() != nullptr && n->getNext() != nullptr)
    {
        node* nprev = n->getPrev();
        node* nnext = n->getNext();

        nprev->setNext(nnext);
        nnext->setPrev(nprev);
        current = nnext;
        delete n;
        return;
    }
}

void list::delcurr()
{
    del(current);
}

void list::delpos(int pos)
{
    node* d = getNodePos(pos);
    if(d == nullptr)
    {
        cout << "DEL | tried to DELETE NULLPTR!"<<endl;
        return;
    }

    del(d);
}

node *list::getNodePos(int pos)
{
    if(pos < length())
    {
        reset();
        for(int i = 0; i<pos; i++)
        {
            adv();
        }
        cout << "GETNODEPOS | Returning current with data: "<<current->getData()<<endl;
        return current;

    }
    else
    {
        cout << "GETNODEPOS | OUT OF BOUNDS! Ret. nullptr" <<endl;
        return nullptr;
    }
}

node *list::remove(node* n)
{
    if(n == first)
    {
        node* ret = n;
        first = n->getNext();
        if(first)
        {
            first->setPrev(nullptr);
        }
        else
        {
            first = nullptr;
        }
        current = first;
        ret->clear();
        return ret;
    }

    if(n == last)
    {
        node* ret = n;
        last = n->getPrev();
        if(last)
        {
            last->setNext(nullptr);
        }
        else
        {
            last = nullptr;
        }
        current = last;
        ret->clear();
        return ret;
    }

    if(n->hasNext() && n->hasPrev())
    {
       node* ret = n;
       node* cprev = n->getPrev();
       node* cnext = n->getNext();

       cprev->setNext(cnext);
       cnext->setPrev(cprev);
       current = cnext;
       ret->clear();
       return ret;
    }
    cout << "REMOVE | Returned null"<<endl;
    return nullptr;
}

int list::getPosFromNode(node *n)
{
    if(n == first)
    {
        return 0;
    }
    if(n == last)
    {
        return length()-1;
    }
    int i;
    node* curr = first;
    for(i = 0; i < length()-1; i++)
    {
        if(curr == n)
        {
            return i;
        }
        curr = curr->getNext();
    }
    return i;
}

void list::mergeLists(list *add)
{
    add->reset();
    bool advd = true;
    node* toadd;
    while(advd)
    {
        toadd = add->getCurrent();
        advd = add->adv();
        addSorted(toadd);
    }
    delete add;
}

list *list::splitLists()
{
    list* newlist = new list();

    int thislen = length();
    int middle = thislen / 2;

    if(thislen <= 1)
    {
        cout << "SPLIT | Cannot split list with length <= 1"<<endl;
        return newlist;
    }

    node* n ;
    for(int i = middle; i < thislen; i++)
    {
        node* inpos = getNodePos(i);
        n = new node(inpos->getData());
        newlist->addSorted(n);
    }

    for(int i = middle; i < thislen-1; i++)
    {
        this->delpos(i);
    }
    delpos(length()-1);
    return newlist;

}

list* list::mergesort()
{
    list* split;
    if(length() > 1)
    {
        split = splitLists();

        split->mergesort();
        mergesort();
    }
    else
    {
        return this;
    }
    mergeLists(split);
    return this;
}

void list::selectionsort()
{
    if(empty())
    {
        cout << "SELECTION | Cannot sort empty list."<<endl;
        return;
    }

    reset();
    list* temp = new list();
    node* candidate = first;
    int len = length();
    bool advd = true;

    for(int i = 0; i < len -1; i++)
    {

        reset();
        candidate = current;
        advd = true;
        while(advd)
        {
            if(candidate->getData() < current->getData())
            {
                candidate = current;
            }
            advd = adv();
        }
        node* owo = remove(candidate);
        owo->clear();
        temp->add(owo);
    }
    // get the last node over
    candidate = first;
    remove(candidate);
    candidate->clear();
    temp->add(candidate);

    first = temp->getFirst();
    last = temp->getLast();
    current = temp->getFirst();

    delete temp;
}

void list::quicksort(int left, int right)
{


    int teiler = ((right-left)/2)+left;
    cout <<endl<< "Berechne pivot: "<<"("<<right<<"-"<<left<<")/2 = "<<teiler<<endl<<endl;

    node* pivot = getNodePos(teiler);
    node* l = getNodePos(left);
    node* r = getNodePos(right);

    cout << "pivot:"<< pivot->getData()<<endl;


    while(getPosFromNode(l) < getPosFromNode(r))
    {
        while(l->getData() < pivot->getData())
        {
            l = l->getNext();
        }

        while(r->getData() > pivot->getData())
        {
            r = r->getPrev();
        }

        cout << "L: "<<l->getData() << " | R: "<<r->getData()<<endl;

        if(getPosFromNode(l) < getPosFromNode(r))
        {

            int lval = l->getData();
            int rval = r->getData();

            l->setData(rval);
            r->setData(lval);

            if(pivot == l)
            {
                pivot = r;
            }
            else
            if(pivot == r)
            {
                pivot = l;
            }

            cout << "SWAP | " << "L: Pos: "<<getPosFromNode(l) << " Data: "<<l->getData() <<endl
                 << "---- |R: Pos: "<<getPosFromNode(r)<<" Data: "<<r->getData()<<endl;

        }
    }
    int pivpos = getPosFromNode(pivot);
    cout << "PIVOT: Pos: "<<pivpos<<" Data: "<<pivot->getData()<<endl;
    cout << "LEFT: "<<left << " RIGHT: "<<right <<endl;
    printlist(first);

    // weitergeben:

    if(pivpos-1 > left)
    {

        cout << "Passing to LEFT: "<<left << " - " << pivpos-1 <<endl;
        quicksort(left,pivpos-1);
    }
    if(pivpos+1 < right)
    {

        cout << "Passing to RIGHT: "<<pivpos+1 << " - " << right <<endl;
        quicksort(pivpos+1,right);
    }
}


void list::printlist(node *start)
{
    if(empty())
    {
        cout << "PRINT | List empty. "<<endl;
        return;
    }
    cout << "Printing list: "<<endl;
    node* oldcurr = current;
    current = start;

    int cnt = 0;

    if(current == oldcurr)
    {
        cout << cnt << "| data: "<< current->getData() << " <"<< endl;

    }
    else
    {
        cout << cnt << "| data: "<< current->getData() << endl;
    }

    while(adv())
    {
        cnt ++;
        if(current == oldcurr)
        {
            cout << cnt << "| data: "<< current->getData() <<" <"<< endl;
        }
        else
        {
            cout << cnt << "| data: "<< current->getData() << endl;
        }
    }
    current = oldcurr;
}

bool list::adv()
{
    if(current->hasNext())
    {
        current = current->getNext();
        return true;
    }
    return false;
}

bool list::ret()
{
    if(current->hasPrev())
    {
        current = current->getPrev();
        return true;
    }
    return false;
}

void list::reset()
{
    current = first;
}


/// get set

node *list::getFirst() const
{
    return first;
}

void list::setFirst(node *value)
{
    first = value;
}

node *list::getLast() const
{
    return last;
}

void list::setLast(node *value)
{
    last = value;
}

node *list::getCurrent() const
{
    return current;
}

void list::setCurrent(node *value)
{
    current = value;
}
