/*
Tareas que se deben hacer:
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

Compilación básica y ejecución:
g++ matmul.cpp -o matmul.out -fsanitize=address,leak,undefined
./matmul.out $size $seed 0 2>/dev/null 1>size_data.dat

#  ******************************* 
#  Ejercicio de matmul NxN variable con y sin multithreading
#  Desarrollado por Camilo Andres Valencia Acevedo para el curso de Intro. al HPC 2023-1 
#  Semana 10-11
#  ******************************* 
*/

// Include necessary libraries.
#include <eigen3/Eigen/Dense>
#include <chrono>
#include <iostream>
#include <vector>
#include <cstdlib>

//Declare used functions, written at the end of the code provided by professor Oquendo
double multiply_eigen(int size);
double multiply_simple(int size);
void fill(std::vector<double> & mat);


//Main execution loop by Camilo Valencia
int main (int argc, char ** argv){
    //Checking the number of execution arguments in console, error if they are incorrect.
    if (argc < 4 || argc > 5) {
        std::cerr << "Error. Usage: \n" << argv[0] << " M S T R\n";
        std::cerr << "M: Matrix size\n";
        std::cerr << "S: Random generator seed\n";
        std::cerr << "T: Is it a multithreaded run? 0 (No), 1(yes)\n";
        std::cerr << "R: (optional) Number of iterations for averages. Default = 5\n";
        return 1;
    }

    //Saving provided arguments, checking if number of iterarions was defined and set if needed.
    const int M = std::stoi(argv[1]); // Matrix size
    const int S = std::stoi(argv[2]); // Seed
    const int T = std::stoi(argv[3]); // Multithreaded? 1(yes) 0(no)
    int reps = 5;
    if(argc == 5){ 
        reps = std::stoi(argv[4]); // Num of iterations for averages?
    }
    
    //Variable declaration
    double eigenTime = 0.0;
    double simpleTime = 0.0;
    double eigenTimeSq = 0.0;
    double simpleTimeSq = 0.0;

    //Random seed generators set up, one for Eigen and the other for the manual simple algorithm
    srand(S);
    srand48(S);

    //Execute Matrices multiplication algorithm 5 times or as many as were defined by the optional argument
    for(int i = 0; i < reps; i++){
        double auxEigen = multiply_eigen(M);
        eigenTime += auxEigen;
        eigenTimeSq += (auxEigen*auxEigen);
        //If we are using multiple threads (T=1), we only want to run the eigen algorithm, otherwise run the simple algorithm too.
        if(T==0){
        double auxSimple = multiply_simple(M);
        simpleTime += auxSimple;
        simpleTimeSq += (auxSimple*auxSimple);
        }
    }

    //Averages and std deviation calculations
    double averageEigen = eigenTime/reps;
    double averageSimple = simpleTime/reps;

    double stdEigen = std::sqrt((eigenTimeSq - ((eigenTime*eigenTime)/reps))/reps); //Note: professor Oquendo's formula was incorrect, this is the correct summatory of the difference of squares
    double stdSimple = std::sqrt((simpleTimeSq - ((simpleTime*simpleTime)/reps))/reps);

    // Set print precision for low time values and print the desired values as needed based on the T parameter. 
    std::cout.precision(15);
    if(T==0){
        std::cout << M << "\t" << averageEigen << "\t" << stdEigen << "\t" << averageSimple << "\t" << stdSimple << "\n";
    }else{
        std::cout << M << "\t" << averageEigen << "\t" << stdEigen << "\n";  
    }
    return 0;
}


// Prof. Oquendo's functions, only change is the seed was taken into the main function.
double multiply_eigen(int size){
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

    std::clog << tmp << std::endl; // use the matrix to make eigen compute it, output to stde or 2> /dev/null

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