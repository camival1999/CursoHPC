## Repositorio para el curso Introducción a HPC 2023-1
### Camilo Valencia
### C.C. 1016107945

#### **Descripción**
En este repositorio se guarda el trabajo del curso mostrando como parte del trabajo de la semana 1 la creación de un repositorio remoto como se puede apreciar por los logs, así como un script de la semana 2 (***instalacionExpress.sh***) que permite automatizar la tarea de instalar una serie de programas que requiero en Ubuntu y normalmente debo instalar manualmente cada uno varias veces en diferentes equipos con **Ubuntu 20.04**.

<br>
NOTA: Navegar a la ubicación del script y correr mediante el comando:

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