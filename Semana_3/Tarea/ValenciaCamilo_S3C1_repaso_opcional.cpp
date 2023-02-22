/*
  ******************************* 
  Script de repaso opcional de C++
  Desarrollado por Camilo Andres Valencia Acevedo para el curso de Intro. al HPC 2023-1 
  Semana 3, Clase 1 
  ******************************* 
*/

// Importamos librerías útiles
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

// Definimos variables globales
int globalInt = 2;
float globalFloat = 2.71;

// Definimos funciones auxiliares antes del main()
// Encuentra el menor valor en el arreglo, tomando en cuenta que el máximo será 900.
int minArray(int Arr[]){
    int min = 900;
    for (int i = 0; i < 300; i++){
        if (Arr[i] < min){
            min = Arr[i];
        }
    }
    return min;
}
// Imprime los valores impares hasta llegar a uno mayor que 800
void oddArray(int Arr[]){
    for (int i = 0; i < 300; i++){
        if (Arr[i] > 800){
            break;
        }
        if (Arr[i]%2==1){
            cout << Arr[i] << " ";
        }
    }
    cout << endl;
}

// Potencia entre números
float potVariables(float mivarflotante, int mivarentera){
    return pow(mivarflotante,mivarentera);
}

int main(){
    // Imprimimos las variables globales
    cout << "La primera variable posee un valor de " << globalInt << " y la segunda un valor de " << globalFloat << endl;
    float division = globalFloat/globalInt;
    cout << "El resultado de la división es " << division << endl;

    // Modificamos la semilla de la función rand() para obtener listas distintas en cada ejecución
    srand(time(NULL) );
    // Inicializamos el arreglo de 300 elementos
    int arrRand[300];
    int ranNum = 0;
    // Recorremos el arreglo vacío, generando números aleatorios entre el 0 y 900, asignandolos al arreglo 
    // e imprimiendolos para evitar recorrerlo dos veces.
    for (int i = 0; i < 300; i++){
        ranNum = (rand() % 1000)*900/999;
        arrRand[i] = ranNum;
        cout << ranNum << " ";
    }
    cout << endl;

    // Imprimimos el 5to elemento que ocupa la posición 4
    cout << "El 5to elemento es: " << arrRand[4] << endl;

    //Obtenemos la longitud
    cout << "El tamaño del arreglo es: " << sizeof(arrRand)/ sizeof(int) << endl;

    // Llamamos las funciones auxiliares definidas previamente
    cout << "El resultado de la potencia 17.5^5 es: ";
    cout << potVariables(17.5,5) << endl;
   
    cout << "El menor número es: ";
    cout << minArray(arrRand) << endl;
    
    cout << "Números impares: ";
    oddArray(arrRand);

    return 0;
}