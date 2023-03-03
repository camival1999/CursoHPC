## Repositorio para el curso Introducción a HPC 2023-1
### Camilo Andres Valencia Acevedo
### C.C. 1016107945
### cvalenciaa@unal.edu.co

Trabajo principal de la semana: Repaso de C++ e introduccióna los *Makefile*.

En el repaso de C++ se realizaron tareas sencillas de manejo de estructuras de datos como los arreglos y operaciones básicas sobre ellos, además de operaciones lógicas, aritméticas, condicionales y creación de funciones.

**Ejecución:** Descargar `ValenciaCamilo_S3C1_repaso.cpp` o `ValenciaCamilo_S3C1_repaso_opcional.cpp`, Compilar y ejecutar mediante

> `g++ {Nombre del archivo deseado}.cpp -o {Nombre del archivo deseado}.exe`
> `./{Nombre del archivo deseado}.exe`


Respecto al Makefile se creó un script sencillo que permite tomar ciertos elementos previos (`datos.dat`,`datos1.dat`,`makedatos.py`, `makedatos1.cpp`, `plotdatos.py`, `plotdatos1.py` y `resultados.tex`) y crear un archivo pdf, de manera que se pueda actualizar aquello que sea necesario al modificar alguna parte que intervenga en la creación de este.

**Ejecución:** Descargar archivos `ValenciaCamilo_S3C1.mk` junto a los previamente mencionados para ejecutar mediante el comando

> `make -f ValenciaCamilo_S3C1`