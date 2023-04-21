#  ******************************* 
#  Ejercicio de matmul NxN variable con threads
#  Desarrollado por Camilo Andres Valencia Acevedo para el curso de Intro. al HPC 2023-1 
#  Semana 10
#  ******************************* 

#strong_scaling.pdf: size_data.dat
#	reset
#	set terminal qt 1 noraise enhanced
#	set xlabel "Matrix size (N)"
#	set ylabel "Time (ms)"
#	set title "Execution time of matrix multiplication with size N"
#	plot 'size_data.dat' using 1:2 with lines title 'Size', \
#	'size_data.dat' using 1:3 with lines dashtype 2 linecolor 7 \
#	title 'Time'
#	set terminal pdfcairo enhanced color notransparent
#	set output 'vanderpol_pdfcairo.pdf'
#	replot
#	unset output
#	unset terminal

#weak_scaling.pdf: threads_data.dat

fig: thread_data.dat size_data.dat
	@echo "Listo para plotear"
	@rm *.out

thread_data.dat: matmulConOptimizarThreads.out
	for thread in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16; do echo "Num. threads: " $$thread; OMP_NUM_THREADS=$$thread ./matmulConOptimizarThreads.out 1000 1 1 2>/dev/null 1>>thread_data.dat; done

size_data.dat: matmulSinOptimizar.out matmulConOptimizar.out
	for size1 in 10 50 100 200 500 1000; do echo "Running -O0. Matrix size: " $$size1; ./matmulSinOptimizar.out $$size1 1 0 2>/dev/null 1>>size_data.dat; done
	for size2 in 10 50 100 200 500 1000; do echo "Running -O3. Matrix size: " $$size2; ./matmulConOptimizar.out $$size2 1 0 2>/dev/null 1>>size_data.dat; done

matmulSinOptimizar.out: matmul.cpp
	g++ matmul.cpp -o matmulSinOptimizar.out -fsanitize=address,leak,undefined -O0

matmulConOptimizar.out: matmul.cpp
	g++ matmul.cpp -o matmulConOptimizar.out -fsanitize=address,leak,undefined -O3

matmulConOptimizarThreads.out: matmul.cpp
	g++ matmul.cpp -o matmulConOptimizarThreads.out -fsanitize=address,leak,undefined -O3 -fopenmp