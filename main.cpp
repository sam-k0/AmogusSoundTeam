#include <iostream>
#include "list.h"
#include "graph.h"
using namespace std;




int main()
{
    graph* g = new graph();

    gnode* n = new gnode(5,-1);

    g->addTo(-1, n);

    cout << g->gnodeExists(n)<<endl;

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

