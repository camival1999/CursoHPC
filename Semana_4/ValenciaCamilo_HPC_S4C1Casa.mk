#  ******************************* 
#  Visualización de error porcentual numérico
#  Desarrollado por Camilo Andres Valencia Acevedo para el curso de Intro. al HPC 2023-1 
#  Semana 4, Clase 1 
#  ******************************* 

# Syntaxis:
# Target:Condition
# 	 Action if condition is newer than target

resultados.pdf : resultados.tex err_derF.pdf err_derC.pdf err_der_h.pdf
	pdflatex resultados.tex

err_derF.pdf :  ValenciaCamilo_HPC_S4C1Casa.py datosForward.dat datosCentral.dat datosH.dat
	python3 ValenciaCamilo_HPC_S4C1Casa.py

err_derC.pdf : ValenciaCamilo_HPC_S4C1Casa.py datosForward.dat datosCentral.dat datosH.dat
	python3 ValenciaCamilo_HPC_S4C1Casa.py

err_der_h.pdf : ValenciaCamilo_HPC_S4C1Casa.py datosForward.dat datosCentral.dat datosH.dat
	python3 ValenciaCamilo_HPC_S4C1Casa.py


datosForward.dat : datos.dat
	awk '{print $$1"\t"$$3"\t"$$5"\t"$$4}' datos.dat >> datosForward.dat

datosCentral.dat : datos.dat
	awk '{print $$2"\t"$$3"\t"$$6"\t"$$4}' datos.dat >> datosCentral.dat

datosH.dat : datos.dat
	awk 'NF!=6 {print $$7"\t"$$8}' datos.dat >> datosH.dat


datos.dat : ValenciaCamilo_HPC_S4C1Casa.exe
	./ValenciaCamilo_HPC_S4C1Casa.exe > datos.dat

ValenciaCamilo_HPC_S4C1Casa.exe : ValenciaCamilo_HPC_S4C1Casa.cpp
	g++ ValenciaCamilo_HPC_S4C1Casa.cpp -o ValenciaCamilo_HPC_S4C1Casa.exe

# Ejecutar con "make -f ./ValenciaCamilo_S4C1Casa.mk"