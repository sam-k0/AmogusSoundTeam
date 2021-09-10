#include "graph.h"

graph::graph()
{

}

void graph::addNodeSingle(gnode *n)
{
    nodes.push_back(n);
    n->setId(getHighestId()+1);
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

bool graph::addTo(int id, gnode *toadd)
{
    if(nodes.empty()) // add a initial first node
    {
        nodes.push_back(toadd);
        toadd->setId(getHighestId()+1);
        return true;
    }


    gnode* result = getById(id);
    int toaddid = 0;

    if(!result) // node not found in graph, cannot append to that
    {
        cout << "The node you wanted to append to with ID " <<id << " doesnt exist."<<endl;
        return false;
    }

    if(!gnodeExists(toadd)) // Dont double add stuff to graph
    {
        toaddid = getHighestId()+1;
        // Does not exist in graph
        nodes.push_back(toadd); // Add to the graphs node list
        toadd->setId(toaddid); // Set the new added node's id

    }
    else
    {
        toaddid = toadd->getId();
    }

    // Connect nodes to each other: result <--> Toadd
    result->connect(toadd);
    toadd->connect(result);
    cout << "Successfully connected nodes: " << id << " and connected: "<< toaddid << endl;
    return true;
}

bool graph::simpleConnect(int id1, int id2)
{
    gnode* result = getById(id1);
    gnode* toadd = getById(id2);

    if(result && toadd)
    {
        result->connect(toadd);
        toadd->connect(result);
        return true;
    }
    return false;
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

bool graph::gnodeExists(int sid)
{
    int res = -1;
    for(gnode* element : nodes)
    {
        res = element->getId();
        if(res == sid)
        {
            return true;
        }
    }
    return false;
}

bool graph::gnodeExists(gnode* gn)
{

    for(gnode* element : nodes)
    {
        if(element == gn)
        {
            return true;
        }
    }
    return false;
}

void graph::adjazenzmatrix()
{
    cout << " |";
    for(gnode* owo : nodes)
    {
        cout<<owo->getId();
    }
    cout << endl;

    for(gnode* graphnode : nodes)
    {
        cout << graphnode->getId()<< "|";
        for(gnode* inode : nodes)
        {
            if(graphnode->checkConnected(inode))
            {
                cout << "X";
            }
            else
            {
                cout << "O";
            }
        }
        cout << endl;
    }

}

