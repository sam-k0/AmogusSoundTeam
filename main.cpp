#include <iostream>
#include "list.h"
#include "graph.h"
#include "chess.h"
using namespace std;

// This is available in all editors.
int chessmain()
{
    chess c = chess();
    c.print();
    c.damedaneDameyoDameDamoyo(4);
    c.print();
    cout<<"amogus"<<endl;
    return 0;
}

int main()
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

