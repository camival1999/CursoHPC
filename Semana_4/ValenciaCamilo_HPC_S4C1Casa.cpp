/*
  ******************************* 
  Script de repaso opcional de C++
  Desarrollado por Camilo Andres Valencia Acevedo para el curso de Intro. al HPC 2023-1 
  Semana 4, Clase 1 
  ******************************* 
*/

// Importamos librerías útiles
#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

float *dyForward(float arrT[],float h, int size){
float *dy = new float[size];

  for(int i = 0; i<size ;i++){
    dy[i] = (sin(arrT[i]+h) - sin(arrT[i]))/h;
  }
  return dy;
}

int main(){
// Definimos variables.
  float h1 = 0.01;
  float lowerLimit = -M_PI_2+h1;
  float upperLimit = M_PI_2-h1;
  int h1ArraySize = (int)((upperLimit-lowerLimit)/h1)+1;
  float *p;
  float dyForwardArray[h1ArraySize];


// Inicializamos el arreglo de datos:
  float tVector[h1ArraySize];
  for(int i = 0; i<h1ArraySize;i++){
    tVector[i] = lowerLimit+i*h1;
  }

  // Obtenemos la derivada por medio del algoritmo forward:
  p = dyForward(tVector,h1,h1ArraySize);
  for(int i = 0; i<h1ArraySize;i++){
    dyForwardArray[i] = *(p+i);
    cout << dyForwardArray[i] << endl;
  }

    return 0;
}