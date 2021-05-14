#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() {
  this->head = nullptr;
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
  while(actual->n < n && actual){
    actual = actual->siguiente;
  }
  if(actual && actual->n == n){
    return true;
  }
  return false;
}

void LinkedList::insert(int n) {
  if (!head) {
    head->n = n;
    head->siguiente = nullptr;
    mysize++;
  } else if (!search(n)) {
    nodo *aux = head;
    while (aux->siguiente->n < n) {
      aux = aux->siguiente;
    }
    nodo *nuevo = new nodo();
    nuevo->n = n;
    nuevo->siguiente = aux->siguiente;
    aux->siguiente = nuevo;
    mysize++;
  }
}

void LinkedList::remove(int n) {
  nodo *actual = head;
  if (head->n == n) head = actual->siguiente;
  else {
    actual = head->siguiente;
    nodo *prev = nullptr;
    while (actual && actual->n != n) {
      prev = actual;
      actual = prev->siguiente;
    }
    if (actual->siguiente)
      prev->siguiente = actual->siguiente; // elemento en medio de la lista
    else
      prev->siguiente = nullptr; // ultimo elemento de la lista
  }
  delete actual;
  mysize--;
}