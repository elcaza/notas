# Instalación de docker

Desde su sitio web oficial seguimos la guía de instalación
+ https://docs.docker.com/engine/install/ubuntu/

Una vez instalado probamos que tengamos docker con:

```
docker --version
```
+ Si no se puede visualizar probar con `sudo docker --version`

En caso de que pida privilegios de `root` para ejecutar docker se soluciona mediante:
+ https://docs.docker.com/engine/install/linux-postinstall/

```
sudo groupadd docker
sudo usermod -aG docker $USER
```
+ Reiniciar tras hacer esto

# Imagenes de docker
Al igual que en github, docker tiene imagenes que puedes usar como base en:
+ https://hub.docker.com/



