#  ******************************* 
#  Ejercicio de matmul NxN variable con threads
#  Desarrollado por Camilo Andres Valencia Acevedo para el curso de Intro. al HPC 2023-1 
#  Semana 10-11
#
#  IMPORTANTE: la semilla en la ejecución de los programas matmul se puede modificar, se mantiene la misma (1) para comparar de manera más adecuada múltiples ejecuciones.
#  ******************************* 

weak_scaling.pdf strong_scaling.pdf: thread_data.dat size_data.dat plot.py
	@echo "Listo para plotear"
	python3 plot.py

thread_data.dat: matmulConOptimizarThreads.out
	for thread in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16; do echo "Num. threads: " $$thread; OMP_NUM_THREADS=$$thread ./matmulConOptimizarThreads.out 4000 1 1 2>/dev/null 1>>thread_data.dat; done

size_data.dat: matmulSinOptimizar.out matmulConOptimizar.out
	for size1 in 10 50 100 200 500 1000 2000 3000 4000; do echo "Running -O0. Matrix size: " $$size1; ./matmulSinOptimizar.out $$size1 1 0 2>/dev/null 1>>size_data.dat; done
	for size2 in 10 50 100 200 500 1000 2000 3000 4000; do echo "Running -O3. Matrix size: " $$size2; ./matmulConOptimizar.out $$size2 1 0 2>/dev/null 1>>size_data.dat; done

matmulSinOptimizar.out: matmul.cpp
	g++ matmul.cpp -o matmulSinOptimizar.out -fsanitize=address,leak,undefined -O0

matmulConOptimizar.out: matmul.cpp
	g++ matmul.cpp -o matmulConOptimizar.out -fsanitize=address,leak,undefined -O3

matmulConOptimizarThreads.out: matmul.cpp
	g++ matmul.cpp -o matmulConOptimizarThreads.out -fsanitize=address,leak,undefined -O3 -fopenmp