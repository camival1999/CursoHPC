#  ******************************* 
#  Visualización de números aleatorios
#  Desarrollado por Camilo Andres Valencia Acevedo para el curso de Intro. al HPC 2023-1 
#  Semana 5, Clase 1 
#  ******************************* 

# Syntaxis:
# Target:Condition
# 	 Action if condition is newer than target

resultados.pdf : ValenciaCamilo_HPC_S5C1C.tex histogramaInt.pdf histogramaFloat.pdf datosLimpios.dat
	pdflatex ValenciaCamilo_HPC_S5C1C.tex
	echo "Compilando otra vez para evitar errores de Cross-Referencing..."
	pdflatex ValenciaCamilo_HPC_S5C1C.tex
	latexmk -c

histogramaInt.pdf :  ValenciaCamilo_HPC_S5C1C.py datosLimpios.dat
	python3 ValenciaCamilo_HPC_S5C1C.py

histogramaFloat.pdf : ValenciaCamilo_HPC_S5C1C.py datosLimpios.dat
	python3 ValenciaCamilo_HPC_S5C1C.py

datosLimpios.dat : datos.dat
	awk '/^comienzo/ { arranque = 1 } arranque { print }' datos.dat >> datosLimpios.dat

datos.dat : ValenciaCamilo_HPC_S5C1C.exe
	./ValenciaCamilo_HPC_S5C1C.exe > datos.dat

ValenciaCamilo_HPC_S5C1C.exe : ValenciaCamilo_HPC_S5C1C.cpp
	g++ ValenciaCamilo_HPC_S5C1C.cpp -o ValenciaCamilo_HPC_S5C1C.exe

# Ejecutar con "make -f ./ValenciaCamilo_HPC_S5C1C.mk"