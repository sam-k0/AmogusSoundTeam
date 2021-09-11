#ifndef TREE_H
#define TREE_H
#include "tnode.h"
#include <iostream>
#include <cmath>

using namespace std;
template<typename T>

class tree
{
private:
    tnode<T>* root = nullptr;
public:
    tree()
    {
        root = nullptr;
    }

    tree(T X[])
    {
        root = nullptr;
        tnode<T>* owo;
        for(auto element : X)
        {
            cout << "amogus"<<endl;
            owo = new tnode<T>(element);
            add(owo);
        }
    }

    void add(tnode<T>* n)
    {

        if(!root)
        {
            root = n;
            return;
        }

        tnode<T>* curr = root;

        while(true)
        {
            if(!curr->hasLeft())
            {
                curr->setLeft(n);
                return;
            }
            else if(!curr->hasRight())
            {
                curr->setRight(n);
                return;
            }

            int lcount = curr->count(curr->getLeft());
            int ldepth = curr->depth(curr->getLeft());

            int rcount = curr->count(curr->getRight());
            int rdepth = curr->depth(curr->getRight());

            if(pow(2,ldepth)-1 == lcount) // Linker teilbaum voll
            {

                if(pow(2,rdepth)-1 == rcount && rdepth == ldepth) // Rechter tb auch voll
                {
                    curr = curr->getLeft();
                }
                else
                {
                    curr = curr->getRight();
                }

            }
            else
            {
                curr = curr->getLeft();
            }
        }


    }

    tnode<T>* getRoot()
    {
        return root;
    }

    void resetRoot()
    {
        root = nullptr;
    }

    void printtree()
    {
        if(!root)
        {
            cout << "Tree empty you sussy baka"<<endl;
            return;
        }
        root->print("");
    }

};

#endif // TREE_H
