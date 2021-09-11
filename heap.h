#ifndef HEAP_H
#define HEAP_H
#include "tree.h"
#include <vector>
template<typename T>
class heap : public tree<T>
{
private:
    tnode<T>* root = nullptr;
public:
    heap(){
        root = nullptr;
    }

    heap(T X[], int n)
    {
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n-1; j++)
            {
                if(X[j] > X[j+1])
                {
                    T temp = X[j];
                    X[j] = X[j+1];
                    X[j+1] = temp;
                }

            }
        }

        tnode<T>* a;
        for(int i = 0; i < n; i++)
        {
            a = new tnode<T>(X[i]);
            this->add(a);
        }        
    }

    void restructure()
    {
        vector<tnode<T>*> collected;
        tnode<T>* r= this->getRoot();
        if(r)
        {
            collected = this->getRoot()->addVec();
        }

        for(int i = 0; i<(int)collected.size(); i++)
        {
            for(int j = 0; j<(int)collected.size()-1; j++)
            {
                if(collected[j]->getData() > collected[j+1]->getData())
                {
                    tnode<T> *temp = collected[j];
                    collected[j] = collected[j+1];
                    collected[j+1] = temp;
                }
            }
        }

        this->resetRoot();
        for(tnode<T>* element : collected)
        {
            element->setLeft(nullptr);
            element->setRight(nullptr);
            this->add(element);
        }
    }

    void addheap(T input)
    {
        tnode<T>* added = new tnode<T>(input);
        this->add(added);
        restructure();
    }
};


#endif // HEAP_H
