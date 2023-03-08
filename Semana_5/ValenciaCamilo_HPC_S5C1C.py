# Script de Python para la lectura de datos en archivos .dat con datos aleatorios
# Correr directamente desde el MakeFile para completar las instancias requeridas. (ValenciaCamilo_HPC_S5C1C.mk).
# Desarrollado por Camilo Andres Valencia Acevedo para el curso de Intro. al HPC 2023-1
# Semana 5, Clase 1

# Librerías necesarias
import numpy as np
import matplotlib.pyplot as plt

# Carga los datos del .dat ignorando la primera fila que es solo un placeholder para awk.
data = np.loadtxt('datosLimpios.dat', skiprows=1)

# Separa los datos en arreglos,
dataInt = data[0,:]
dataFloat = data[1,:]

# Histogramas de ambos conjuntos de datos
plt.hist(dataInt)
plt.xlabel('Valor')
plt.ylabel('Frecuencia')
plt.title('1000 Enteros aleatorios')        
plt.savefig("histogramaInt.pdf", format="pdf", dpi=250)
plt.close()

plt.hist(dataFloat)
plt.xlabel('Valor')
plt.ylabel('Frecuencia')
plt.title('1000 Flotantes aleatorios')
plt.savefig("histogramaFloat.pdf", format="pdf", dpi=250)
plt.close()