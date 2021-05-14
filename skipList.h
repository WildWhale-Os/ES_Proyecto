#include "Miniset.h"
#include <iostream>
struct nodo {
  int n;
  nodo **next;
};
class skipList : public Miniset {
private:
  int nivelmax;
  double probabilidad;
  nodo *head;
  int size;
  bool flipCoin();

public:
  skipList();
  ~skipList();
  void insert(int n);
  void remove(int n);
  bool search(int n);
};
