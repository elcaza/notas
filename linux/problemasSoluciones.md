# VMWare WorkStation 15
+ Error al compilar
    + https://communities.vmware.com/thread/617466
+ Error al compilar
    + script => https://github.com/elcaza/vmware-host-troubleshooting

# VMWare dont work with combination keys (alt+tab do not change the application)
+ Just start session with XOrg

# Touchpad Laptop Linux
+ https://github.com/JoseExposito/touchegg?tab=readme-ov-file
+ https://github.com/priyaranjankumar/touchegg.conf

# VirtualBox
+ No detecta un adaptador WIFI usb
    + https://archivogeek.com/3323/como-habilitar-usb-2-0-y-usb-3-0-en-virtualbox/
    + https://medium.com/@elcaza/instalando-un-adaptador-usb-wifi-en-virtualbox-41f0a8f9df5a

## Pasos 

1. Instalar extensiones de virtualbox
2. Añadir usuario al grupo vboxusers
    + Sustituye *<_username_>* por tu nombre de usuario
```bash
sudo apt install virtualbox-ext-pack
sudo usermod -aG vboxusers <_username_>
```

Reinicia el sistema, abre virtual box, y podrás ver el dispositivo USB. 


# Instalar EasyScreenCast en Linux
+ https://extensions.gnome.org/extension/690/easyscreencast/
+ https://github.com/EasyScreenCast/EasyScreenCast

## Pasos
1) Descarga el repositorio y compilar la extensión
```
git clone https://github.com/EasyScreenCast/EasyScreenCast.git
cd EasyScreenCast
sudo apt-get -y install gettext
make
make install
```

2) Cierras sesión
3) Abres sesión (Debería aparecer una notificación en la pantalla para activar la extensión) en caso de que no aparezca, solamente abrimos "Extensions" y habilitamos EasyScreenCast
4) Ahora tenemos un icono en la parte superior de nuestra pantalla con la cámara.

## Grabar con webcam
Para habilitar la grabación mediante la webcam debemos hacer: 
+ click sobre el icono de la cámara
+ Seleccionar options
+ Seleccionar webcam
+ Seleccionar un perfil para la grabación

# Otros recursos
## MATE Desktop y Centos 7
+ https://blog.programster.org/centos-7-install-mate-desktop

## GUI Sistemas Linux
+ https://sdkit.com/?p=6
+ https://www.tecmint.com/change-runlevels-targets-in-systemd/

## Redireccionamiento
+ http://persoal.citius.usc.es/tf.pena/ASR/Tema_2html/node16.html

## Burp
Instalar CA de BURP
1. Descargar el certificado desde:
    + http://burp/

## Instalar sonarqube Linux
+ https://techexpert.tips/sonarqube/sonarqube-installation-ubuntu-linux/
+ https://techexpert.tips/sonarqube/sonarqube-scanner-installation-ubuntu-linux/