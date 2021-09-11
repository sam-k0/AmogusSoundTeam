#include <iostream>
#include "list.h"
#include "graph.h"
#include "chess.h"
#include "tree.h"
#include "heap.h"
using namespace std;

// This is available in all editors.

int main()
{
    int arr[] = {1,4,5,2};
    int arraySize = sizeof(arr)/sizeof(arr[0]);
    heap<int>* h = new heap<int>(arr, arraySize);

    h->addheap(44);

    h->printtree();
    return 0;
}



int treemain()
{
    tree<int>* t = new tree<int>();

    tnode<int>* n = new tnode<int>(2);
    t->add(n);

    n = new tnode<int>(4);
    t->add(n);

    n = new tnode<int>(5);
    t->add(n);

    n = new tnode<int>(6);
    t->add(n);

    n = new tnode<int>(7);
    t->add(n);

    n = new tnode<int>(8);
    t->add(n);

    n = new tnode<int>(9);
    t->add(n);

    n = new tnode<int>(10);
    t->add(n);

    n = new tnode<int>(11);
    t->add(n);

    n = new tnode<int>(12);
    t->add(n);

    t->printtree();


    cout << "Amogus"<<endl;
    return 0;
}

int chessmain()
{
    chess c = chess();
    c.print();
    c.damedaneDameyoDameDamoyo(4);
    c.print();
    cout<<"amogus"<<endl;
    return 0;
}

int graphmain()
{
    graph* g = new graph();

    gnode* n = new gnode(5);

    g->addTo(-1, n);

    gnode* m = new gnode(3);

    g->addTo(0, m);

    gnode* f = new gnode(4);

    g->addTo(0, f);

    g->simpleConnect(2,1);

    g->adjazenzmatrix();

    cout << "amogus" << endl;
    return 0;
}

int oldmain()
{

    list* l =  new list();
    node* n = new node(4);
    l->add(n);

    n = new node(1);
    l->add(n);



    n = new node(3);
   l->add(n);


    n = new node(5);
    l->add(n);

    n = new node(2);
    l->add(n);

   /* n = new node(3);
    l->addSorted(n);/**/


    //cout << "pos:"<< l->getPosFromNode(l->getNodePos(0)) << endl;

    l->reset();

    l->printlist(l->getFirst());

   l->quicksort(0,l->length()-1);

    l->printlist(l->getFirst());


    cout << "amogus"<<endl;
    return 0;
}

