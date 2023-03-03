## Repositorio para el curso Introducción a HPC 2023-1
### Camilo Andres Valencia Acevedo
### C.C. 1016107945
### cvalenciaa@unal.edu.co

Trabajo principal de la semana: script ***instalacionExpress.sh*** que permite automatizar la tarea de instalar una serie de programas que requiero en Ubuntu y normalmente debo instalar manualmente cada uno varias veces en diferentes equipos con **Ubuntu 20.04**.


**Ejecución:** Descargar el script mencionado y navegar a la ubicación de descarga. Correr mediante el comando:
> `./instalacionExpress.sh` 

Anteriormente se corría con el comando `sudo ./instalacionExpress.sh`  evitando que el bash pida autenticarse nuevamente de forma aleatoria en alguinas ocasiones, sin embargo por algún motivo esto causa que al editar el bashrc, se modifique el .bashrc del usuario root y por lo tanto no se guarden los cambios.

La lista de programas que instala y tareas realizadas es:
- ROS Noetic instalación completa
- Visual Studio Code
- Kitty y configura como terminal predeterminado
- Catkin
- Git
- CopyQ
- Tree
- Locate
- Xclip
- Configuración de alternativas de Python
- Modificación de Aliases en el archivo ~./bashrc
- Creación de llave SSH para conectar git con Github