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
  double array[N];
  //reserve memory
  //array = new double [N];
  // initialise array
  for (int ii = 0; ii < N; ++ii) {

	  std::cout<<"ii antes: " << ii << std::endl;
	  array[ii] = 2*(ii); // != 2*(ii++) ?
	  std::cout<<"ii despues: "<< (ii) << std::endl;
  }
  // print some values
  int idx = 2;
  std::cout << array[idx] << std::endl;
  idx = 9;
  std::cout << array[idx] << std::endl; 

  return 0;
}