#ifndef GRAPH_H
#define GRAPH_H
#include "gnode.h"
using namespace std;
class graph
{
private:
    vector<gnode*> nodes;



public:
    graph();
    void addNode(gnode* n);
    gnode* getById(int id);
    bool addTo(int id, gnode* toadd);
    int getHighestId();
    bool gnodeExists(int sid);
    bool gnodeExists(gnode* gn);
};



#endif // GRAPH_H
