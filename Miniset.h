#include <iostream>

#ifndef MINISET_H
#define MINISET_H
class Miniset{
public:
    virtual bool search(int n) = 0;
    virtual void insert(int n) = 0;
    virtual void remove(int n) = 0;
};
#endif 