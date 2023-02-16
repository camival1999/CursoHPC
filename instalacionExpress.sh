clear
echo ""
echo "*******************************"
echo "Script para automatizar la instalación de diversos programas al reinstalar Ubuntu 20.04"
echo "Desarrollado por Camilo Andres Valencia Acevedo para el curso de Intro. al HPC 2023-1"
echo "Semana 2, Clase 1"
echo "*******************************"
echo ""

echo "Lista de programas:"
echo " - ROS noetic full install"
echo " - VScode"
echo " - Kitty"
echo " - Catkin"
echo " - Git"
echo " - CopyQ"
echo " - Tree"
echo " - Locate"
echo " - Alternativas de Python"
echo " - Modificación aliases Bashrc"
echo " - Xclip"
echo " - Instalación de NodeJS y Node Red"
echo " - Creación llave SSH para Github"

echo "Se requiere privilegios de administrador"
echo " "
sudo echo "Hecho!"

# Instalación de ROS
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
sudo apt -y install curl
curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
sudo apt update
sudo apt -y install ros-noetic-desktop-full
echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc
source ~/.bashrc
sudo apt -y install python3-rosdep python3-rosinstall python3-rosinstall-generator python3-wstool build-essential
sudo apt -y install python3-rosdep
sudo rosdep init
rosdep update

# Instalación de VScode
sudo snap -y install --classic code

# Instalación de kitty 
curl -L https://sw.kovidgoyal.net/kitty/installer.sh | sh /dev/stdin

# Instalación de Catkin
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu `lsb_release -sc` main" > /etc/apt/sources.list.d/ros-latest.list'
wget http://packages.ros.org/ros.key -O - | sudo apt-key add -
sudo apt-get update
sudo apt-get -y install python3-catkin-tools

# Instalación de Git
sudo apt update
sudo apt -y install git
git --version

# Instalación de CopyQ
sudo add-apt-repository ppa:hluk/copyq
sudo apt update
sudo apt -y install copyq

# Instalación de Tree
sudo apt -y install tree

# Instalación de Locate 
sudo apt -y install locate

# Alternativas de Python
sudo update-alternatives --install /usr/bin/python python /usr/bin/python2.7 1
sudo update-alternatives --install /usr/bin/python python /usr/bin/python3.8 2

# Modificación de Bashrc
echo " ">> ~/.bashrc
echo "# Custom Aliases" >> ~/.bashrc
echo "# BASH" >> ~/.bashrc
echo "alias eb=\"gedit ~/.bashrc\"" >> ~/.bashrc
echo "alias sb=\"source ~/.bashrc\"" >> ~/.bashrc
echo " " >> ~/.bashrc
echo "# System"  >> ~/.bashrc
echo "alias update=\"sudo apt update\"" >> ~/.bashrc
echo "alias shutoff=\"(sleep 5 && shutdown now) &\"" >> ~/.bashrc
echo " " >> ~/.bashrc
echo "force_color_prompt=yes" >> ~/.bashrc

#Instalación Xclip para manejar el clipboard en el terminal
sudo apt -y install xclip

# Instalación de NodeJS y Node Red
curl -sL https://rpm.nodesource.com/setup_14.x | sudo bash --
sudo yum install -y nodejs
node -v
npm -v
sudo npm install -g --unsafe-perm node-red
npm install -g --unsafe-perm node-red-admin

#Llave ssh Github
ssh-keygen -f ~/.ssh/id_rsa -t ed25519 -C "cvalenciaa@unal.edu.co" -N ''
cat ~/.ssh/id_rsa.pub | xclip

echo "Llave SSH copiada al portapapeles, no olvides pegarla en https://github.com/settings/keys !"
echo "Fin del programa!"
