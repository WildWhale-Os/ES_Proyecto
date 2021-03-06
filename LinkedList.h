#include "Miniset.h"
struct nodo {
	int n;
	nodo *siguiente;
};

class LinkedList: public Miniset {
private:
    struct nodo *head;
    int mysize;
    int totalsize;
public:
    LinkedList();
    ~LinkedList();
    void insert(int n);
    void remove(int n);
    bool search(int n);
    int getTotalSize();
};
