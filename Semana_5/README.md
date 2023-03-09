## Repositorio para el curso Introducción a HPC 2023-1
### Camilo Andres Valencia Acevedo
### C.C. 1016107945
### cvalenciaa@unal.edu.co

Trabajo principal de la semana: Integración de librerías estándar en nuestro código.

En el estándar de C++ hay una serie de librerías ya incluidas, las cuales poseen ciertas funciones y algoritmos muy útiles que se encuentran totalmente optimizados para reducir al mínimo cualquier tipo de error numérico y de ejecución. En esta semana se desarrolló una serie de cortos scripts que buscan sacar provecho de estas funciones para lograr los siguientes objetivos: 

![Screenshot from 2023-03-09 17-32-01](https://user-images.githubusercontent.com/55710287/224176343-bb2c2d4d-c069-4907-b300-0b9f80bbc5d6.png)

Para ello hice uso de dos librerías estándar: `<random>` y `<algorithm>`. Estas contienen funciones y clases que permiten generar números pseudoaleatorios con distintas caracerísticas definidas como distribuciones concretas y rangos deseados, así como funciones de búsqueda en arreglos, respectivamente. Así en el archivo `.cpp` el cual contiene la lógica del ejercicio, se definen las funciones deseadas y en el main se generan los arreglos de números aleatorios pedidos, para luego mediante un archivo makefile guardar estos datos en un archivo aparte, generar dos gráficas con el script de python y finalmente compila los resultados en un pdf mediante Látex.

**Ejecución:** Descargar los scripts `ValenciaCamilo_HPC_S5C1C` `.mk`,`.cpp`,`.py` y  `.tex`. Navegar a la ruta de descarga y correr el comando
```consoles
 make -f ValenciaCamilo_HPC_S5C1C.mk
```
