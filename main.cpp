#include "LinkedList.h"
#include "skipList.h"
#include <bits/stdc++.h>

using namespace std;

int main() {

  int n = 1000;
  clock_t start;
  double time;
  skipList list;
  LinkedList list1;
  ofstream insertion("insetion.csv");
  ofstream searching("find.csv");
  ofstream removing("remove.csv");
  // Primeras lineas en todos los archivos
  // insertion
  insertion << "Size,LinkedList,SkipList" << endl;
  insertion << "0,0,0" << endl;
  // find
  searching << "Size,LinkedList,SkipList" << endl;
  searching << "0,0,0" << endl;
  // remove
  removing << "Size,LinkedList,SkipList" << endl;
  removing << "0,0,0" << endl;
  // cambiando el size del grupo de datos
  for (int n = 1000; n < 10001; n += 1000) {
    // ingresa el size de grupo de datos actual;
    insertion << n;
    searching << n;
    removing << n;
    cout << n << endl;
    // creamos vectro a con numeros a ser intsertados
    vector<int> entrada;
    entrada.assign(n, 0);
    cout << "Entrada creada" << endl;
    for (int i = 0; i < n; i++) {
      entrada[i] = i;
    }
    cout << "datos ingresados a entreada" << endl;
    // desordanemos los valores del vector de entrada
    random_shuffle(entrada.begin(), entrada.end());
    // tiempo de insercion
    // Linked List
    cout << "Iniciando incersion" << endl;
    cout << "linked list" << endl;
    start = clock();
    for (int i = 0; i < n; i++) {
      list1.insert(entrada.at(i));
    }
    time = ((double)clock() - start) / CLOCKS_PER_SEC;
    insertion << "," << time;
    start = clock();
    // skip List
    cout << "skip list" << endl;
    for (int i = 0; i < n; i++) {
      list.insert(entrada.at(i));
    }
    time = ((double)clock() - start) / CLOCKS_PER_SEC;
    insertion << "," << time << endl;
    cout << "incersion terminada" << endl;
    // searching
    cout << "Inicioando busqueda" << endl;
    // Linked List
    cout << "linked list" << endl;
    start = clock();
    for (int i = 0; i < n; i++) {
      list1.search(entrada.at(i));
    }
    time = ((double)clock() - start) / CLOCKS_PER_SEC;
    searching << "," << time;
    // Skip List
    cout << "skip list" << endl;
    start = clock();
    for (int i = 0; i < n; i++) {
      list.search(entrada.at(i));
    }
    time = ((double)clock() - start) / CLOCKS_PER_SEC;
    searching << "," << time << endl;
    cout << "busqueda terminada" << endl;
    // removing
    cout << "Inicioando removing" << endl;
    // Linked List
    cout << "linked list" << endl;
    start = clock();
    for (int i = 0; i < n; i++) {
      list1.remove(entrada.at(i));
    }
    time = ((double)clock() - start) / CLOCKS_PER_SEC;
    removing << "," << time;
    // Skip List
    cout << "skip list" << endl;
    start = clock();
    for (int i = 0; i < n; i++) {
      list.remove(entrada.at(i));
    }
    time = ((double)clock() - start) / CLOCKS_PER_SEC;
    removing << "," << time << endl;
    cout << "removing terminado" << endl;
  }
  insertion.close();
  searching.close();
  removing.close();
  return 0;
}
