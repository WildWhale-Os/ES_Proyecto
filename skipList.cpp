#include "skipList.h"
#include <new>
skipList::skipList() {
  nivelmax = 4;
  probabilidad = 0.5;
  head = nullptr;
  size = 0;
  srand(time(nullptr));
}
skipList::~skipList() {
  /*while(size > 0){
      nodo *actual = head;
      nodo *pen = nullptr;
      while(!actual->next){
          pen = actual;
          actual = pen->next;
      }
      pen->next = nullptr;
      delete actual;
      size--;
  }*/
}
bool skipList::flipCoin() {
  int ran = rand() % 100;
  if (ran % 2 == 0)
    return true;
  return false;
}
void skipList::insert(int n) {
  nodo *actual = head;
  nodo *path[nivelmax];
  int nivel = nivelmax;
  while (nivel >= 0) {
    while (actual->next[nivel] != nullptr && actual->next[nivel]->n < n) {
       actual = actual->next[nivel];
    }

    path[nivel] = actual;
    nivel--;
  }
}
void skipList::remove(int n) {}

bool skipList::search(int n) {}