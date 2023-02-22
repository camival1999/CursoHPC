echo ""
echo "*******************************"
echo "Script de extracción de datos del nevado del Tolima"
echo "Desarrollado por Camilo Andres Valencia Acevedo para el curso de Intro. al HPC 2023-1"
echo "Semana 1, Clase 2"
echo "*******************************"
echo ""

#Configuración de parada por errores
set -e

#Inicio de script
echo "Eliminando directorio Tolima preexistente..."
rm -rf Tolima
echo "¡Hecho!"
echo "Creando nuevo directorio Tolima y copiando DatosTolima.dat y PlotsTolima.py..."
mkdir Tolima
cp DatosTolima.dat PlotsTolima.py ./Tolima
cd Tolima
echo "¡Hecho!"

echo "Creando archivo DatosMarzo.txt separado por tabulado..."
printf "G&R\tEQ\n" > DatosMarzo.txt
awk '$1 == "March" || $2 == "March" { print $(NF-2)"\t"$NF }' DatosTolima.dat >> DatosMarzo.txt
echo "DatosMarzo.txt Creado"

echo "Creando archivo GRF_vs_EQ.txt separado por tabulado..."
printf "G&R\tEQ\n" > GRF_vs_EQ.txt
awk 'NF == 6 || NF == 7 { print $(NF-2)"\t"$NF }' DatosTolima.dat >> GRF_vs_EQ.txt
echo "GRF_vs_EQ.txt Creado"

echo "Ejecutando PlotsTolima.py..."
python3 PlotsTolima.py
echo "¡Gráfica lista!"

echo "Eliminando copia de DatosTolima.dat..."
rm DatosTolima.dat
echo "¡Hecho!"

echo ""
echo "********  Fin del script  ********"