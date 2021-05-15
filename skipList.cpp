#include "skipList.h"
#include <new>
skipList::skipList() {
  nivelmax = 4;
  actLevel = 0;
  head = new nodo();
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

int skipList::newLevel(){
  int level = 0;
  while(flipCoin() && level <= nivelmax) level++;
  return level;
}

void skipList::insert(int n) {
  nodo *actual = head;
  nodo *path[nivelmax+1];
  int nivel = actLevel;
  while (nivel >= 0) {
    while (actual->next[nivel] != nullptr && actual->next[nivel]->n < n) {
      actual = actual->next[nivel];
    }
    path[nivel] = actual;
    nivel--;
  }
  // volvemos actual el primer valor en el nivel 0
  actual = actual->next[0];
  if(actual == nullptr || actual->n != n){
    int nlevel = newLevel();    
    if(actLevel < nlevel){
      for (int i = actLevel +1; i <= nlevel; i++) path[i] = head;
      actLevel = nlevel;
    }

    nodo * rookie = new nodo();
    rookie->n=n;
    rookie->next=new nodo*[nivelmax+1];

    for(int i = 0; i <= nlevel; i++){
      rookie->next[i] = path[i]->next[i];
      path[i]->next[i] = rookie;
    }
    
  }
}
void skipList::remove(int n) {
  nodo *actual = head; // partimos recorriendo desde la cabeza
  nodo *path[nivelmax+1]; // hacemos un arreglo de puntores para ir guardando en donde cambiamos de nivel
  for (int i = actLevel; i <= 0; i--) {
    // desde el nivel mas alto vamos viendo hasta donde podemos llegar en cada nivel antes de llegar al elemeto en el nivel 0 
    while(actual->next[i] != nullptr && actual->next[i]->n < n)
      actual= actual->next[i];
    path[i] =actual; // incluimos el nodo actual en el path
  }
  actual = actual->next[0];
  if (actual != nullptr && actual->n ==n) {
    for (int i = 0; i < actLevel +1; i++) {
      if(path[i]->next[i]!= actual)break;
      path[i]->next[i] = actual->next[i];
    }
    delete actual;
  }
  while(actLevel > 0 && head->next[actLevel] == 0)
    actLevel--;
}

bool skipList::search(int n) {
  bool where =false;
  nodo *actual=head;
  int nivel = actLevel;
  while(nivel>=0){
    while(actual->next[nivel]!=nullptr and actual->next[nivel]->n <= n){
      actual=actual->next[nivel];
    }
    if(actual->n==n){
      where=true;
      break;
    }
    nivel--;
  }
  return where;
}