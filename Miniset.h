#include <bits/stdc++.h>

#ifndef MINISET_H
#define MINISET_H
class Miniset{
public:
    virtual bool search(int) = 0;
    virtual void insert(int) = 0;
    virtual void remove(int) = 0;
};
#endif 
