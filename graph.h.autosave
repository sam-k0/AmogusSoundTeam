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
    void addNodeSingle(gnode* n);
    gnode* getById(int id);
    bool addTo(int id, gnode* toadd);
    bool simpleConnect(int id1, int id2);
    int getHighestId();
    bool gnodeExists(int sid);
    bool gnodeExists(gnode* gn);
    void adjazenzmatrix();
    void dijkstra(int start, int dest);
    bool vectorContains(vector<gnode*> vec, gnode* n);
};



#endif // GRAPH_H
