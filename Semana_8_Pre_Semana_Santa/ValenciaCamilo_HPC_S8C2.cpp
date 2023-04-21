/*
  ******************************* 
  Uso de Chronos para profiling de tiempo
  Desarrollado por Camilo Andres Valencia Acevedo para el curso de Intro. al HPC 2023-1 
  Semana 8, Clase 2, avances 
  ******************************* 
*/


// Importamos librerías útiles
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;


// Definimos las funciones encargadas de realizar los llenados según los criterios
// de las diapositivas y ayuda de https://www.geeksforgeeks.org/emulating-a-2-d-array-using-1-d-array/

void array_mode1(int **arr, int N, int M) {
    auto start_time = high_resolution_clock::now();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            arr[i][j] = 0;
        }
    }
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);
    cout << "Modo 1: " << duration.count() << " microsegundos" << endl;
}

void array_mode2(int *arr, int N, int M) {
    auto start_time = high_resolution_clock::now();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            arr[i * M + j] = 0;
        }
    }
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);
    cout << "Modo 2: " << duration.count() << " microsegundos" << endl;
}

void array_mode3(int *arr, int N, int M) {
    auto start_time = high_resolution_clock::now();
    for(int j = 0; j < M; j++) {
        for(int i = 0; i < N; i++) {
            arr[j * N + i] = 0;
        }
    }
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);
    cout << "Modo 3: " << duration.count() << " microsegundos" << endl;
}

void array_mode4(vector<vector<int>> &vec, int N, int M) {
    auto start_time = high_resolution_clock::now();
    vec.resize(M, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            vec[j][i] = 0;
        }
    }
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);
    cout << "Modo 4: " << duration.count() << " microsegundos" << endl;
}

// Definimos los valores de N y M y llamamos las funciones creadas.
int main() {
    int N = 2000;
    int M = 2000;

    int **arrMode1 = new int*[N];
    for(int i = 0; i < N; i++) {
        arrMode1[i] = new int[M];
    }
    array_mode1(arrMode1, N, M);

    int *arrMode2 = new int[N * M];
    array_mode2(arrMode2, N, M);

    int *arrMode3 = new int[N * M];
    array_mode3(arrMode3, N, M);

    vector<vector<int>> vecMode4;
    array_mode4(vecMode4, N, M);

    return 0;
}

// Queda pendiente las gráficas e iteracion de N y M
