# Instalación de docker

Desde su sitio web oficial seguimos la guía de instalación
+ https://docs.docker.com/engine/install/ubuntu/
+ Corroborar para qué sistema operativo se instala

Una vez instalado probamos que tengamos docker con:

```
docker --version
```
+ Si no se puede visualizar probar con `sudo docker --version`

Pasos de post instalación
+ https://docs.docker.com/engine/install/linux-postinstall/


# Conceptos importaes

## Imágenes
+ Plantillas utilizadas para crear contenedores; comando _build_
+ Están compuestas por capas de otras imágenes
+ Se almacenan en un registro docker 

## Contenedor
+ Si una imagen la relacionamos a una clase, entonces una instancia sería un contenedor
+ Los contenedores solamente almacenan los binarios y dependencias que se necesitan para la ejeución.

## Registro
+ Lugar donde se almacenan las imagenes
    + Puede ser público o privado (DockerHub o Propio)
    + El registro contiene repositorios donde vive cada imágen

# Imagenes de docker
Al igual que en github, docker tiene imagenes que puedes usar como base en:
+ https://hub.docker.com/


# Creación de contenedores
1. Primero se busca localmente la imágen
2. Si no se tiene se busca en línea

Corroborar qué imagenes se tienen en nuestra computadora
~~~ bash
docker images
~~~

## Hello word en docker

**Repositorio**
+ https://hub.docker.com/_/hello-world

~~~bash
# Descarga la imagen
docker pull hello-world

~~~

## Comandos básicos

~~~ bash
# Corroborar qué imagenes se tienen en nuestra computadora
docker images

# Descarga la imagen
docker pull hello-world

# Correr imagen
docker run hello-world

# Entrar al contenedor en modo interactivo
docker run -it ubuntu

# Entrar al contenedor y ejecutar un comando
sudo docker run ubuntu echo "hello world!"

# Ver que contenedores se ejecutan en bacgroud
docker ps


~~~
+ docker run crea nuevos contenedores, no hay persistencia. Tal cual una instancia de una clase.


# Tipos de contendores

## Primer plano
+ Salen por salida estándar

## Segundo plano
+ Inician en modo detached y salen cuando el proceso raiz utilizado para ejecutar el contenedor sale