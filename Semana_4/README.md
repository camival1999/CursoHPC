## Repositorio para el curso Introducción a HPC 2023-1
### Camilo Andres Valencia Acevedo
### C.C. 1016107945
### cvalenciaa@unal.edu.co

Trabajo principal de la semana: Continuación de C++ y Makefiles, aproximación numérica de la derivada.

Se buscó crear un script de C++ que implementase dos algoritmos de aproximación numérica basados en la definición formal del límite para la derivada llamados Forward y Central:

![Screenshot from 2023-03-02 22-01-21](https://user-images.githubusercontent.com/55710287/222621752-d545ddb6-6f16-4634-9120-afbe0e3a6cce.png)

Con esto se busca obtener la mejor aproximación a la derivada de la función $Sin(x)$ analizando el error procentual generado por cada una. En este caso es necesario correr directamente el archivo makefile `ValenciaCamilo_HPC_S4C1Casa.mk` pues este se encarga de revisar las dependencias necesarias para crear el informe final en PDF y realizar los pasos necesarios para compilar y ejecutar los programas. El archivo CPP posee el algoritmo mencionado y se encarga de crear los conjunto de datos requeridos, los cuales son seccionados con en el Makefile empleando `awk`. Una vez los datos son seccionados, el script de Python se encarga de tomar estos y generar una serie de gráficas para el compilador de Látex, el cual se ejecuta dos veces con el fin de evitar referencias internas no encontradas en la primera compilación. 

**Ejecución:** Descargar los scripts `ValenciaCamilo_HPC_S4C1Casa` `.mk`,`.cpp`,`.py` y  `.tex`. Navegar a la ruta de descarga y correr el comando
```
 make -f ValenciaCamilo_HPC_S4C1Casa.mk
```
