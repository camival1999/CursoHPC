#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

//Mode 2
void array_mode2(int **arr, int N, int M) {
    auto start_time = high_resolution_clock::now();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            arr[i][j] = 0;
        }
    }
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);
    cout << "Time taken to fill 2D array: " << duration.count() << " microseconds" << endl;
}

//Mode 3
void array_mode3(int **arr, int N, int M) {
    auto start_time = high_resolution_clock::now();
    for(int j = 0; i < N; i++) {
        for(int i = 0; j < M; j++) {
            arr[i][j] = 0;
        }
    }
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);
    cout << "Time taken to fill 2D array: " << duration.count() << " microseconds" << endl;
}

// No entendi el modo 1 ni 4 :c

int main() {
    int N = 2;
    int M = 2
    
    // Inicialización y llenado
    int *arr_filas = new int[N * M];
    array_mode2(arr_filas, N, M);

    // 1D array initialization and filling (column-major)
    int *arr_col = new int[N * M];
    array_mode3(arr_col, N, M);
}