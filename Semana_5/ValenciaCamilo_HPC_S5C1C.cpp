/*
  ******************************* 
  Algoritmos de familiarización con la librería estándar C++
  Desarrollado por Camilo Andres Valencia Acevedo para el curso de Intro. al HPC 2023-1 
  Semana 5, Clase 1 
  ******************************* 
*/

// Importamos librerías útiles
#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>

using namespace std;

// Funciones que se encargan de buscar la existencia de un valor que cumpla
// el requisito de menor que 7, mayor que 9 e imprimir el mayor a 3. Usando 
// overloading por los tipos de arreglos distintos y la librería estándar 
// "algorithm" para la búsqueda.
bool menorQue7(int* arr, int size) {
  return all_of(arr, arr + size, [](int i){ return i < 7; });
}

bool menorQue7(float* arr, int size) {
  return all_of(arr, arr + size, [](float i){ return i < 7; });
}

bool unoMayorQue9(int* arr, int size) {
  return any_of(arr, arr + size, [](int i){ return i > 9; });
}

bool unoMayorQue9(float* arr, int size) {
  return any_of(arr, arr + size, [](float i){ return i > 9; });
}

void primerMayorQue3(int* arr, int size) {
  for (int i = 0; i < size; ++i) {
      if (arr[i] > 3) {
            cout << "Primer elemento mayor a 3 en el arreglo de enteros: " << arr[i] <<  endl;
          break;
      }
  }
}

void primerMayorQue3(float* arr, int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 3) {
             cout << "Primer elemento mayor a 3 en el arreglo de flotantes: "<< arr[i] <<  endl;
            break;
        }
    }
}

int main() {
//Definimos los arreglos a llenar
  int arrInt[50];
  int arrInt1000[1000];
  float arrFloat[50];
  float arrFloat1000[1000];

// Generamos 50 rand Int entre 0 y 10 con distribución uniforme
  random_device rd;
  mt19937 gen(rd()); // para generar números pseudoaleatorios
  uniform_int_distribution<> dis_int(0, 10);
  cout << "Enteros aleatorios entre 0 y 10 con distribución uniforme: " <<  endl;
  for (int i = 0; i < 50; ++i) {
        arrInt[i] = dis_int(gen);
        cout <<  arrInt[i] << " ";
  }
  cout <<  endl;

// Generamos 50 flotantes aleatorios con distribución Gaussiana
  normal_distribution<float> dis_float(-10, 17);
  cout << "Random floating numbers with Gaussian distribution:" <<  endl;
  for (int i = 0; i < 50; ++i) {
        arrFloat[i] = dis_float(gen);
        cout <<  arrFloat[i] << " ";
  }
    cout <<  endl;

// Llamamos las funciones de comparación menores que 7, mayores que 9 y el primer elemento mayor a 3.
  if (menorQue7(arrInt, 50)) {
    cout << "Todos los valores son menores que 7 en el arreglo de enteros!" <<  endl;
  }
  if (menorQue7(arrFloat, 50)) {
    cout << "Todos los valores son menores que 7 en el arreglo de flotantes!" <<  endl;
  }

  if (unoMayorQue9(arrInt, 50)) {
    cout << "Al menos un valor es mayor que 9 en el arreglo de enteros!" <<  endl;
  }
  if (unoMayorQue9(arrFloat, 50)) {
    cout << "Al menos un valor es mayor que 9 en el arreglo de flotantes!" <<  endl;
  }

  primerMayorQue3(arrInt, 50);
  primerMayorQue3(arrFloat, 50);

//Llenamos los areglos de 1000 datos e imprimimos para guardar luego
cout << "comienzo" << endl;
  for (int i = 0; i < 1000; ++i) {
        arrInt1000[i] = dis_int(gen);
        cout <<  arrInt1000[i] << "\t";
  }
  cout <<  endl;
  for (int i = 0; i < 1000; ++i) {
        arrFloat1000[i] = dis_float(gen);
        cout <<  arrFloat1000[i] << "\t";
  }
  return 0;
}