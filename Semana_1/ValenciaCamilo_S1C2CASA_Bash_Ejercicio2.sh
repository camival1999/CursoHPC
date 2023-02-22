echo ""
echo "*******************************"
echo "Script de comandos básicos de Terminal"
echo "Desarrollado por Camilo Andres Valencia Acevedo para el curso de Intro. al HPC 2023-1"
echo "Semana 1, Clase 2"
echo "*******************************"
echo ""

#Configuración de parada por errores
set -e

#Inicio de script
echo "  - Eliminando directorios HPC preexistentes:"
rm -rf HPC_CamiloValencia 
rm -rf HPC_CamiloValencia2
echo "¡Hecho!"

echo "  - Creando directorio HPC_CamiloValencia e ingreso"
mkdir HPC_CamiloValencia
cd HPC_CamiloValencia

echo "  - Directorio actual :"
pwd
echo "  - Creación de loquesea.txt :"
touch loquesea.txt
ls
echo "   - Copiar loquesea.txt y llamar loquesea2.txt :"
cp loquesea.txt loquesea2.txt
ls
echo "  - Renombrar 2 a loquesea3.txt :"
mv loquesea2.txt loquesea3.txt
ls
echo "  - Eliminar a loquesea3.txt :"
rm loquesea3.txt
ls
echo "  - Salida del nuevo directorio :"
cd ..
pwd
ls
echo "  - Copiar el directorio entero, renombar y eliminar el original :"
cp -r HPC_CamiloValencia HPC_CamiloValencia2
rm -r HPC_CamiloValencia
ls

echo ""
echo "********  Fin del script  ********"
