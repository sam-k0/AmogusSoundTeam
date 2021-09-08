#include "graph.h"

graph::graph()
{

}

void graph::addNode(gnode *n)
{
    nodes.push_back(n);
}

gnode *graph::getById(int id)
{
    for(gnode* element : nodes)
    {
        if(element->getId() == id)
        {
            return element;
        }
    }
    cout << "Could not find node with ID " << id << endl;
    return nullptr;
}

bool graph::addTo(int id, gnode *toadd) // pass ID = -1 for initial node
{
    if(id == -1 && nodes.empty()) // add a initial first node
    {
        nodes.push_back(toadd);
        toadd->setId(getHighestId()+1);
        return true;
    }


    gnode* result = getById(id);
    int toaddid = getHighestId()+1;

    if(!result) // node not found in graph, cannot append to that
    {
        cout << "The node you wanted to append to with ID " <<id << " doesnt exist."<<endl;
        return false;
    }


    nodes.push_back(toadd); // Add to the graphs node list
    toadd->setId(toaddid); // Set the new added node's id

    // Connect nodes to each other: result <--> Toadd
    result->connect(toadd);
    toadd->connect(result);
    cout << "Successfully connected nodes: " << id << " and newly added: "<< toaddid << endl;
    return true;
}

int graph::getHighestId() // gets the highest id in the graph
{
    int highest = -1;
    int res = -1;

    for(gnode* element : nodes)
    {
        res = element->getId();
        if(res > highest)
        {
            highest = res;
        }
    }
    return highest;
}
