#include "Miniset.h"
#include <iostream>
struct nodo {
  int n;
  nodo **next;
};
class skipList : public Miniset {
private:
  int nivelmax;
  int actLevel;
  nodo *head;
  int size;
  bool flipCoin();
  int newLevel();

public:
  skipList();
  ~skipList();
  void insert(int n);
  void remove(int n);
  bool search(int n);
};
