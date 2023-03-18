/*
  ******************************* 
  Debugging C++
  Correcciones por Camilo Andres Valencia Acevedo para el curso de Intro. al HPC 2023-1 
  Semana 6, Clase 2 
  ******************************* 
*/

#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
  // declare variables
  const int N = 10;
  double * array  = nullptr;
  //reserve memory
  array = new double [N];
  // initialise array
  for (int ii = 0; ii < N; ++ii) {
    // Se realiza el llenado del arreglo solo en las posiciones impares.
    // Al realizar la operacion ++i durante la asignación, se incrementa 
    // el contador antes de realizar la asignacion, con lo cual al comenzar
    // el ciclo ii=0, pero rápidamente pasa a 1 durante la asignación, 
    // dejando el primer elemento del arreglo "vacío" o con el valor que sea
    // que exista en memoria en ese momento, algo al azar:
    // índice:    0      1      2      3      4       5      6       7      8       9
    // array:  [vacio]  [2]  [vacio]  [6]  [vacio]  [10]  [vacio]  [14]  [vacio]  [18]

    //std::cout<<"ii antes: " << ii << std::endl;
	  array[ii] = 2*(++ii);
	  //std::cout<<"ii despues: "<< (ii) << std::endl;
  }
  // print some values
  int idx = 0; // Memoria "vacía"
  std::cout << "Posición " << idx << ": " <<array[idx] << std::endl;
  idx = 1; // Debería ser 2
  std::cout << "Posición " << idx << ": " <<array[idx] << std::endl;
  idx = 2; // Memoria "vacía"
  std::cout << "Posición " << idx << ": " <<array[idx] << std::endl;
  idx = 6; // Memoria "vacía"
  std::cout << "Posición " << idx << ": " <<array[idx] << std::endl;
  idx = 7; // Debería ser 14
  std::cout << "Posición " << idx << ": " <<array[idx] << std::endl;
  idx = N-1; //Para evitar buscar en un índice fuera del arreglo, debería ser 18
  std::cout << "Posición " << idx << ": " <<array[idx] << std::endl;

  //Corrección memory leak
  delete [] array;
  return 0;
}