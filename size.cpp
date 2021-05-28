#include "LinkedList.h"
#include "skipList.h"
#include <bits/stdc++.h>

using namespace std;

int main(){
  skipList skip;
  LinkedList linked;
  ofstream salida("size.csv");
  // Primeras lineas en todos los archivos
  // primera linea salida
  salida << "size,LinkedList,SkipList\n";
  // cambiando el size del grupo de datos
  for (int n = 1000; n < 10001; n += 1000) {
    // ingresa el size de grupo de datos actual;
    salida << n << ",";
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
    for (int i = 0; i < n; i++) {
      linked.insert(entrada.at(i));
    }
    salida << linked.getTotalSize() << ",";
    // Skip list
    for (int i = 0; i < n; i++) {
      skip.insert(entrada.at(i));
    }
    salida << skip.getTotalSize() << endl;
  }
  salida.close();
}
