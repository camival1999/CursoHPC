/*
En función del tamaño:
N = 10,50,100,200,500,1000,2000,3000,4000.
Matmul:Manual for loops y con eigen (2 implementaciones)
Sin optimizar (-O0) y con máx optimización (-O3)
Graficar para cada tamaño el tiempo con cada algoritmo y cada optimización (4 datos por tamaño)
Para referencia, dividir todos los tiempos entre el tiempo de Eigen -O0 N=10 y poner ese tiempo en el título.

en función de los threads:
N=4000.
Variar el número de threads entre 1 y 16 o el máximo.
usar -O3
Graficar tiempo vs threads
dividir los tiempos por el de eigen sin optimizar 1 thread e incluir este tiempo en el titulo.

NOTA: Hacer promedio y desviación, Min 5 iteraciones por cada dato en ambos casos

g++ matmul.cpp -o matmul.out -fsanitize=address,leak,undefined
./matmul.out 100 1 2>/dev/null 1>size_data.dat

*/

#include <eigen3/Eigen/Dense>
#include <chrono>
#include <iostream>
#include <vector>
#include <cstdlib>

double multiply_eigen(int size);
double multiply_simple(int size);
void fill(std::vector<double> & mat);

int main (int argc, char ** argv){
    bool repetitionsDefined = false;
    if (argc < 3 || argc > 4) {
        std::cerr << "Error. Usage: \n" << argv[0] << " M S R\n";
        std::cerr << "M: Matrix size\n";
        std::cerr << "S: Random generator seed\n";
        std::cerr << "R: (optional) Number of iterations. Default = 5\n";
        return 1;
    }

    const int M = std::stoi(argv[1]); // Matrix size
    const int S = std::stoi(argv[2]); // Seed
    int reps = 5;

    if(argc == 4){ 
        reps = std::stoi(argv[3]);
    }
    
    double eigenTime = 0.0;
    double simpleTime = 0.0;
    double eigenTimeSq = 0.0;
    double simpleTimeSq = 0.0;

    for(int i = 0; i < reps; i++){
        double auxEigen = multiply_eigen(M);
        double auxSimple = multiply_simple(M);

        eigenTime += auxEigen;
        eigenTimeSq += (auxEigen*auxEigen);
        simpleTime += auxSimple;
        simpleTimeSq += (auxSimple*auxSimple);
    }

    double averageEigen = eigenTime/reps;
    double averageSimple = simpleTime/reps;

    double stdEigen = std::sqrt((eigenTimeSq - ((eigenTime*eigenTime)/reps))/reps);
    double stdSimple = std::sqrt((simpleTimeSq - ((simpleTime*simpleTime)/reps))/reps);

    std::cout.precision(15);
    //std::cout.setf(std::ios::scientific);
    std::cout << M << "\t" << averageEigen << "\t" << stdEigen << "\t" << averageSimple << "\t" << stdSimple << "\n";
    //std::cout << M << "\t" << eigenTime << "\t" << averageEigen << "\t" << eigenTimeSq << "\t" << eigenTime*eigenTime << "\n";


    return 0;
}



double multiply_eigen(int size){
    // set the random number generator seed  CAMBIAR?
    srand(1); 

    // create matrices
    Eigen::MatrixXd A = Eigen::MatrixXd::Random(size, size);
    Eigen::MatrixXd B = Eigen::MatrixXd::Random(size, size);

    //Start measuring Wall time with chrono
    auto start = std::chrono::steady_clock::now();

    // Multiply
    auto C{A*B}; 
    double tmp = C(0, 0); // use the matrix to make eigen compute it

    //Stop Chrono timer
    auto end = std::chrono::steady_clock::now();

    std::clog << tmp << std::endl; // use the matrix to make eigen compute it, output to stde or 2> dev/null

    //Calculate elapsed time
    std::chrono::duration<double> elapsed_seconds = end-start;
    double total_time = elapsed_seconds.count();
    return total_time;
}

void fill(std::vector<double> & mat) {
    for(auto & val : mat) { // runs through all values, by reference
        val = -1.0 + 2.0*drand48();  // assign a random number between -1 and 1, drand48 \in [0, 1)
    }
}

double multiply_simple(int size){
    srand48(1); // seed for the random number generator used

    // model the matrices as 1d arrays
    std::vector<double> A(size*size), B(size*size), C(size*size);
    fill(A); fill(B);

    // Perform the needed op
    auto start = std::chrono::steady_clock::now();
    for(int ii = 0; ii < size; ++ii) {
        for(int jj = 0; jj < size; ++jj) {
        for(int kk = 0; kk < size; ++kk) {
            C[ii*size + jj] += A[ii*size + kk]*B[kk*size + jj];
        }
        }
    }
    double tmp = C[0]; // use the matrix
    auto end = std::chrono::steady_clock::now();

    std::clog << tmp << std::endl; // use the matrix

    std::chrono::duration<double> elapsed_seconds = end-start;
    double total_time = elapsed_seconds.count();
    return total_time;
}