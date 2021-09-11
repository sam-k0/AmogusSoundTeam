#ifndef QUEUE_H
#define QUEUE_H
#include "heap.h"
#include <vector>
template<typename T>
class queue : public heap<T>
{
private:
    vector<T> list;
public:
    queue();
    bool empty()
    {
        return list.empty();
    }
    void enq(T n)
    {
        list.push_back(n);

        for(int j = 0; j < list.size(); j++)
        {
            for(int i = list.size(); i > 1; i--)
            {
                if(list.at(i) > list.at(i-1))
                {
                    T temp = list.at(i);
                    list[i] = list[i-1];
                    list[i-1] = temp;
                }
            }
        }
    }

    void deq()
    {
        list.erase(list.begin());
    }


    T front()
    {
        if(!empty())
        {
            return list.at(0);
        }
        return NULL;
    }
};

#endif // QUEUE_H
