# Script de Python para graficar los datos de la ejecución matmul
# Correr directamente desde el MakeFile para completar las instancias requeridas. (makefile).
# Desarrollado por Camilo Andres Valencia Acevedo para el curso de Intro. al HPC 2023-1
# Semana 10

# Librerías necesarias
import numpy as np
import matplotlib.pyplot as plt

#strong_scaling (Aquí Strong scaling es el aumento del tamaño de las matrices, realmente es el aumento de threads, error de encunciado)
dataSize = np.loadtxt('size_data.dat')

# Separa los datos en arreglos y divide entre el tiempo base definido a continuación
sizes = dataSize[:9,0]
# Tiempo N=10 sin optimizar Eigen
tiempoBase = dataSize[0,1]

# Eigen sin optimizar (-O0)
averageSinOptimizarEigen = dataSize[:9,1]/tiempoBase
deviationSinOptimizarEigen = dataSize[:9,2]/tiempoBase

# Eigen con optimizar (-O3)
averageConOptimizarEigen = dataSize[9:,1]/tiempoBase
deviationConOptimizarEigen = dataSize[9:,2]/tiempoBase

# Simple sin optimizar (-O0)
averageSinOptimizarSimple = dataSize[:9,3]/tiempoBase
deviationSinOptimizarSimple = dataSize[:9,4]/tiempoBase

# Simple con optimizar (-O3)
averageConOptimizarSimple = dataSize[9:,3]/tiempoBase
deviationConOptimizarSimple = dataSize[9:,4]/tiempoBase


# Graficas de ambos datos
plt.errorbar(sizes,averageSinOptimizarEigen,deviationSinOptimizarEigen,capsize=5,linewidth=1,Color='r',marker='o',ecolor='r',markersize=5)
plt.errorbar(sizes,averageConOptimizarEigen,deviationConOptimizarEigen,capsize=5,linewidth=1,Color='b',marker='o',ecolor='b',markersize=5)
plt.errorbar(sizes,averageSinOptimizarSimple,deviationSinOptimizarSimple,capsize=5,linewidth=1,Color='g',marker='o',ecolor='g',markersize=5)
plt.errorbar(sizes,averageConOptimizarSimple,deviationConOptimizarSimple,capsize=5,linewidth=1,Color='k',marker='o',ecolor='k',markersize=5)
plt.legend(["Eigen -O0","Eigen -O3","Simple -O0","Simple -O3"])
plt.grid()
plt.xlabel('Size Matrix N')
plt.ylabel('Time (s)/time(Eigen N=10 -O0)')
plt.title('Execution time of matrix multiplication vs size N.\n W/o optimization N=10, t='+str(tiempoBase)+'s')        
plt.savefig("strong_scaling.pdf", format="pdf", dpi=250)
plt.close()

#weak_scaling (Aquí Weak scaling es el aumento de hilos, realmente es el aumento del tamaño de matrices, error de encunciado)
dataThread = np.loadtxt('thread_data.dat')

# Separa los datos en arreglos y divide entre el tiempo base definido a continuación, solo Eigen -O3
sizes = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
# Tiempo Thread=1 Eigen
tiempoBase = dataThread[0,1]

# Eigen con optimizar (-O3)
averageThreads = dataThread[:,1]/tiempoBase
deviationThreads = dataThread[:,2]/tiempoBase

# Graficas de ambos datos
plt.errorbar(sizes,averageThreads,deviationThreads,capsize=5,linewidth=2,Color='r',marker='o',ecolor='r',markersize=5)
plt.legend(["Time of execution / 1 Thread execution time Eigen -O3"])
plt.grid()
plt.xlabel('# of Threads')
plt.ylabel('Time (s)/time(Thread=1)')
plt.title('Execution time of matrix multiplication vs # of Threads.\n Base time unit Eigen Threads=1, t='+str(tiempoBase)+'s')        
plt.savefig("weak_scaling.pdf", format="pdf", dpi=250)
plt.close()