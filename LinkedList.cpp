#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
  this->head = new nodo();
  this->mysize = 0;
}

LinkedList::~LinkedList() {
  while (head != nullptr) {
    nodo *tmp = head->siguiente;
    delete head;
    head = tmp;
    mysize--;
  }
}

bool LinkedList::search(int n) {
  nodo *actual = head;
  while (actual->siguiente != nullptr && actual->siguiente->n < n) {
    actual = actual->siguiente;
  }
  if (actual->siguiente != nullptr && actual->siguiente->n == n) {
    return true;
  }
  return false;
}

void LinkedList::insert(int n) {
  nodo *aux = head;
  while (aux->siguiente != nullptr && aux->siguiente->n < n) {
    aux = aux->siguiente;
  }
  if (aux->siguiente == nullptr || aux->siguiente->n != n) {
    nodo *nuevo = new nodo();
    nuevo->n = n;
    nuevo->siguiente = aux->siguiente;
    aux->siguiente = nuevo;
    mysize++;
  }
}

void LinkedList::remove(int n) {
  nodo *actual = head;
  while (actual->siguiente != nullptr && actual->siguiente->n < n) {
    actual = actual->siguiente;
  }
  if (actual->siguiente && actual->siguiente->n == n){
    nodo *next = nullptr;
    next = actual->siguiente;
    actual->siguiente = next->siguiente;
    delete next;
    mysize--;
  }

}

int LinkedList::getTotalSize(){
  return sizeof(nodo) * mysize;
}
