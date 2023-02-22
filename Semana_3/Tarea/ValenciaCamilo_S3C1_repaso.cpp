/*
  ******************************* 
  Script de repaso de C++
  Desarrollado por Camilo Andres Valencia Acevedo para el curso de Intro. al HPC 2023-1 
  Semana 3, Clase 1 
  ******************************* 
*/

// Importamos librerías útiles
#include <iostream>
#include <ctime>
using namespace std;

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

int main(){
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

    // Llamamos las funciones auxiliares definidas previamente
    cout << endl;
    cout << "El menor número es ";
    cout << minArray(arrRand);
    
    cout << endl;
    cout << "Números impares: ";
    oddArray(arrRand);

    return 0;
}

