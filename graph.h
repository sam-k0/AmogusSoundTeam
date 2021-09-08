#ifndef GRAPH_H
#define GRAPH_H
#include "gnode.h"
using namespace std;
class graph
{
private:
    vector<gnode*> nodes;

    void addNode(gnode* n);
    gnode* getById(int id);
    bool addTo(int id, gnode* toadd);
    int getHighestId();

public:
    graph();
};



#endif // GRAPH_H
