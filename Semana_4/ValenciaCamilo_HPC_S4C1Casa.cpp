/*
  ******************************* 
  Script de repaso opcional de C++
  Desarrollado por Camilo Andres Valencia Acevedo para el curso de Intro. al HPC 2023-1 
  Semana 4, Clase 1 
  ******************************* 
*/

// Importamos librerías útiles
#include <iostream>
//#include <ctime>
#include <cmath>
//#include <vector>

using namespace std;

double *dyForward(double arrT[],double h, int size){
  double *dy = new double[size];
  for(int i = 0; i<size ;i++){
    dy[i] = (sin(arrT[i]+h) - sin(arrT[i]))/h;
  }
  return dy;
}

double *dyCentral(double arrT[],double h, int size){
  double *dy = new double[size];
  for(int i = 0; i<size ;i++){
    dy[i] = (sin(arrT[i]+(h/2)) - sin(arrT[i]-(h/2)))/h;
  }
  return dy;
}

double *dyAnalytic(double arrT[],double h, int size){
  double *dy = new double[size];
  for(int i = 0; i<size ;i++){
    dy[i] = cos(arrT[i]);
  }
  return dy;
}

int main(){
// Definimos variables para el cálculo de los intervalos.
  double h1 = 0.01;
  double lowerLimit = -M_PI_2+h1;
  double upperLimit = M_PI_2-h1;
  int h1ArraySize = (int)((upperLimit-lowerLimit)/h1)+1;

// Definimos unos pointers para extraer arreglos de funciones
  double *pAnalytic;
  double *pForward;
  double *pCentral;
  double *pH;

// Definimos constantes para obtener el error al variar H.
  double piTercios[1] =  {M_PI/3};
  double h2 = 1;
  int iteraciones = 150;

// Definimos los arreglos para las funciones y errores a obtener
  double tVector[h1ArraySize];
  double dyAnalyticArray[h1ArraySize];
  double dyForwardArray[h1ArraySize];
  double dyCentralArray[h1ArraySize];
  double forwardError[h1ArraySize];
  double centralError[h1ArraySize];
  double hVector[iteraciones];
  double variacionH[iteraciones];

// Inicializamos los vectores o arreglos para el eje T o H:
  for(int i = 0; i<h1ArraySize;i++){
    tVector[i] = lowerLimit+i*h1;
  }

  hVector[0] = h2;
  for(int i = 1; i<iteraciones;i++){
    hVector[i] = hVector[i-1]/1.05;
  }

// Obtenemos las derivadas y el error en cada método:
  pAnalytic = dyAnalytic(tVector,h1,h1ArraySize);
  pForward = dyForward(tVector,h1,h1ArraySize);
  pCentral = dyCentral(tVector,h1,h1ArraySize);

  for(int i = 0; i<h1ArraySize;i++){
    dyAnalyticArray[i] = *(pAnalytic+i);
    dyForwardArray[i] = *(pForward+i);
    dyCentralArray[i] = *(pCentral+i);
    forwardError[i] = (dyForwardArray[i]-dyAnalyticArray[i])/dyAnalyticArray[i];
    centralError[i] = (dyCentralArray[i]-dyAnalyticArray[i])/dyAnalyticArray[i];
  }



// Obtenemos el error al variar el valor de H
for(int i = 0; i<iteraciones; i++){
  //cout << "H: " << h2;
  pH = dyCentral(piTercios,hVector[i],1);
  variacionH[i] = *(pH);
  //cout << " aprox: " << variacionH[i] << endl;
}

  
// Imprimimos los resultados
  cout << "Forward" << "\t" << "Central" << "\t" << "Analytic" << "\t" << "vectorT" << "\t" << "ForwardError" << "\t" << "CentralError" << "\t" << "varH" << "\t" << "H" <<endl;
  for(int i = 0; i<h1ArraySize;i++){
    cout << dyForwardArray[i] << "\t";
    cout << dyCentralArray[i] << "\t";
    cout << dyAnalyticArray[i] << "\t";
    cout << tVector[i] << "\t";
    cout << forwardError[i] << "\t";
    cout << centralError[i] << "\t";
    if (i<iteraciones){
       cout << variacionH[i] << "\t" << hVector[i] << endl;}
    else{cout << endl;}
  }

    return 0;
}