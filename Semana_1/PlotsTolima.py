# Script de Python para la lectura de datos en archivos TXT proporcionados por un script
# de Bash previo (ValenciaCamilo_S1C2CASA_Bash_Ejercicio4.sh).
# Desarrollado por Camilo Andres Valencia Acevedo para el curso de Intro. al HPC 2023-1
# Semana 1, Clase 2

# Librerías necesarias
import numpy as np
import matplotlib.pyplot as plt
import os

#Verificar el directorio de trabajo del script actual
print("Directorio de trabajo del script: " + os.getcwd())

# Corrección del directorio de trabajo actual, dado que el script 
# cree que el workpath es el del archivo original y no encuentra los archivos .txt
# al cambiar de ubicación mediante copiado. 
# NOTA: Parece que esto solo sucede desde VScode, mantener comentada la línea 19 para correr
# desde Terminal
#os.chdir(os.path.dirname(__file__))

# Carga los datos de los txt ignorando la primera fila
# pues solo es el título de cada columna, se usó para entender los datos nada más
dataYears = np.loadtxt("GRF_vs_EQ.txt", skiprows=1)
dataMarch = np.loadtxt("DatosMarzo.txt", skiprows=1)

# Separa los datos en arreglos
GRFY = dataYears[:,0]
EQY = dataYears[:,1]
GRFM = dataMarch[:,0]
EQM = dataMarch[:,1]

# Plot de los datos GRF vs EQ
plt.plot(EQY, GRFY, 'ko', markersize=2)
plt.xlabel("Largest Earthquake")
plt.ylabel("Glacier & Rockfall")
plt.plot(EQM, GRFM, 'go', markersize=12)
plt.grid(True)
plt.legend(["Monthly data 2006-2012", "Every March 2006-2012"], loc='upper center', bbox_to_anchor=(0.5, 1.1),
          ncol=2, fancybox=True, shadow=True)

#Guardado de la figura en un PDF          
plt.savefig("PlotTolima.pdf", format="pdf", dpi=250)