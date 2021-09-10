#ifndef GNODE_H
#define GNODE_H
#include <vector>
#include <iostream>

class gnode
{
private:
    int weight = 0;
    std::vector<gnode*> connections;
    int id = -1;


public:
    gnode();
    gnode(int weight);
    gnode(int weight, int id);

    // Main
    bool connect(gnode* n);
    bool checkConnected(gnode* n);


    // get set
    int getId() const;
    void setId(int value);
    int getWeight() const;
    void setWeight(int value);
    std::vector<gnode *> getConnections();
    void setConnections(std::vector<gnode *> &value);
};

#endif // GNODE_H
