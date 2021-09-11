#ifndef TNODE_H
#define TNODE_H
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template<typename T>
class tnode
{
private:
    T data;
    tnode* left = nullptr;
    tnode* right = nullptr;

public:
    tnode(T val)
    {
        data = val;
    }

    T getData()
    {
        return data;
    }

    bool hasLeft()
    {
        return (bool)left;
    }

    bool hasRight()
    {
        return (bool)right;
    }

    void setRight(tnode* n)
    {
        right = n;
    }

    void setLeft(tnode* n)
    {
        left = n;
    }

    tnode* getRight()
    {
        return right;
    }

    tnode* getLeft()
    {
        return left;
    }

    bool hasBoth()
    {
        return (right && left);
    }

    int depth(tnode* n)
    {
        if(n == nullptr)
        {
            return 0;
        }
        else
        {
            return 1+depth(n->getLeft());
        }
    }

    int count(tnode* n)
    {
        int ld =0;
        int rd =0;

        if(n != nullptr)
        {
            ld = n->count(n->getLeft());
            rd = n->count(n->getRight());
            return 1+ld+rd;
        }
        else
        {
            return 0;
        }


    }



    void print(string indent)
    {
        if(right)
        {
            right->print(indent + "--");
        }

        cout <<indent<< data << endl;

        if(left)
        {
            left->print(indent + "--");
        }

    }

    vector<tnode<T>*> addVec()
    {
        vector<tnode<T>*> vec;
        vector<tnode<T>*> rightvec;
        if(!left && !right)
        {
            vec.push_back(this);
            return vec;
        }
        if(left)
        {
            vec = left->addVec();
        }
        if(right)
        {
            rightvec = right->addVec();
        }
        rightvec.push_back(this);
        // merge
        vec.insert(vec.end(), rightvec.begin(), rightvec.end());
        return vec;


    }
};

template<typename T>
bool operator>=(tnode<T> a, tnode<T> b)
{
    return a.getData()>=b.getData();
}

template<typename T>
bool operator==(tnode<T> a, tnode<T> b)
{
    return a.getData()==b.getData();
}

template<typename T>
bool operator<=(tnode<T> a, tnode<T> b)
{
    return a.getData()<=b.getData();
}

template<typename T>
bool operator>(tnode<T> a, tnode<T> b)
{
    return a.getData()>b.getData();
}

template<typename T>
bool operator<(tnode<T> a, tnode<T> b)
{
    return a.getData()<b.getData();
}

#endif // TNODE_H

/*   oooo Amogus
 *   o  o
 *   oooo
 *   o  o
 *  oo  oo
 */
