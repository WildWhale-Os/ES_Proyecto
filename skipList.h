#include "Miniset.h"
struct skipNodo {
  int n;
  skipNodo **next;
};
class skipList : public Miniset {
private:
  int nivelmax;
  int actLevel;
  skipNodo *head;
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
