#include "gnode.h"
using namespace std;
int gnode::getId() const
{
    return id;
}

void gnode::setId(int value)
{
    id = value;
}

int gnode::getWeight() const
{
    return weight;
}

void gnode::setWeight(int value)
{
    weight = value;
}

std::vector<gnode *> gnode::getConnections()
{
    return connections;
}

void gnode::setConnections( std::vector<gnode *> &value)
{
    connections = value;
}

gnode::gnode()
{

}

gnode::gnode(int w)
{
    weight = w;
    id = -1;
}

gnode::gnode(int weight, int id)
{
    this->weight = weight;
    this->id = id;
}

bool gnode::connect(gnode *n)
{
    if(checkConnected(n))
    {
        cout << "Nodes already connected."<<endl;
        return false;
    }

    connections.push_back(n);
    return true;
}

bool gnode::checkConnected(gnode *n)
{
    for(gnode* element : connections)
    {
        if(element == n)
        {
            return true;
        }
    }
    return false;
}





