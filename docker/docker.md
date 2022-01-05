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

## Hello word en docker

**Repositorio**
+ https://hub.docker.com/_/hello-world

~~~bash
# Descarga la imagen
docker pull hello-world

# Ejecuta Hello world
docker run hello-world
~~~

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

## Imagenes de docker
Al igual que en github, docker tiene imagenes que puedes usar como base en:
+ https://hub.docker.com/


## Creación de contenedores
1. Primero se busca localmente la imágen
2. Si no se tiene se busca en línea

Corroborar qué imagenes se tienen en nuestra computadora
~~~ bash
docker images
~~~

# Comandos básicos

~~~bash
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

# Ver que contenedores se ejecutan en background
docker ps
# sudo docker run ubuntu sleep 3

# Ver todos los que contenedores se han ejecutado
docker ps -a

# Ejecutar contenedor y borrar
docker run --rm ubuntu

# Ejecutar un contenedor y añadir un nombre
docker run --name hello_ubuntu ubuntu 

# Detener un contenedor
docker ps
docker stop id_name_contenedor 

# Listar información a bajo nivel de una imagen
sudo docker run -d ubuntu sleep 60
sudo docker inspect id_image

# Checar logs de una imagen
docker logs id_image

# Ver imagenes que conforman una capa de docker
docker history ubuntu

# Abrir un contenedor que se ha cerrado
    # Obtenemos el ID
docker ps -a
    # Inicializamos la imagen
docker start -i <name/id>
    # If the container wasn't started with an interactive shell to connect to, you need to do this to run a shell:
docker exec -it <name/id> /bin/sh

# Entrar a un contenedor que está corriendo
docker ps
docker exec -it id_docker /bin/bash

# Hacer commit de una imagen de docker
docker ps -a
# Obtenemos id
docker commit id_image user/image:1.0
# user/image    1.0       6f5e2d0470ef   9 seconds ago   243MB

# Hacer login en cuenta de Docker
    # Tener el nombre correcto de la imagen
    # username/image
# Ver imagenes que tienes
docker images
# Cambiar tag
docker tag id_image username/image:1.0
# Hacer login en docker
docker login --username=user
# Enviar imagen a Dockerhub
docker push username/image:1.0



docker commit ID_contenedor
~~~
+ docker run crea nuevos contenedores, no hay persistencia. Tal cual una instancia de una clase.


# Tipos de contendores

## Primer plano
+ Salen por salida estándar

## Segundo plano
+ Inician en modo detached y salen cuando el proceso raiz utilizado para ejecutar el contenedor sale

# Formas de construir una imagen
## Hacer commit de los cambios en el contenedor

~~~bash
# Iniciamos una imagen de debian
sudo docker run -it --name debian-git debian

# Dentro del docker descargamos git
apt update
apt install git 
git --version
exit

# Docker Commit
~~~

## Escribir un Dockerfile
Parecido a Makefile
~~~bash
touch Dockerfile
~~~

**Contenido Dockerfile**
+ Cada ``RUN`` añade una nueva capa a la imagen
~~~Dockerfile
FROM debian
RUN apt-get update
RUN apt intall -y git
RUN apt intall -y curl
~~~

**Contenido Dockerfile**
+ Cada ``RUN`` añade una nueva capa a la imagen, concatenando comandos
~~~Dockerfile
FROM debian
RUN apt-get update && apt-get install -y \
    curl \
    git 
~~~

**Intrucción CMD**
+ CMD especifica un comando que se va a ejecutar cuando el contenedor inicia
~~~Dockerfile
FROM ubuntu
RUN apt-get update && apt-get install -y \
    curl \
    git 
CMD ["echo", "todo listo"]
~~~

**Instrucción COPY**
+ COPY copia archivos o directorios del contexto de compilación al sistema de archivos del contenedor
~~~Dockerfile
FROM ubuntu
RUN apt-get update && apt-get install -y \
    curl 

COPY files /src/files
~~~


**docker build (contexto de compilación)**
~~~bash
docker build -t user/image .
docker build -t user/image /path/to/file
~~~


**Instrucción ADD**
Investigar


**Instrucción USER**
Selecciona con que usuario va a correr la aplicación
~~~Dockerfile
FROM python:3.7
RUN pip install Flask==0.11.1
RUN useradd -ms /bin/bash admin
USER admin
WORKDIR /app
COPY app /app
CMD ["python", "app.py"]
~~~

**Instrucción WORKDIR**
Selecciona el directorio de trabajo que vamos a utilizar
~~~Dockerfile
FROM python:3.7
RUN pip install Flask==0.11.1
RUN useradd -ms /bin/bash admin
USER admin
WORKDIR /app
COPY app /app
CMD ["python", "app.py"]
~~~

# Docker cache
El cache de Docker es usado para no ejecutar los comandos una vez que estos ya se han ejecutado.

Podria causar problemas en instrucciones como:
~~~Dockerfile
# Config inicial
FROM debian
RUN apt-get update
RUN apt-get install -y git

# Config nueva
# cache
FROM debian
# cache
RUN apt-get update
# Estariamos instalando sin antes haber hecho un update, podría descargarse un paquete viejo
RUN apt-get install -y curl git vim

# Posible solución
FROM debian
RUN apt-get update && apt-get install -y \
    curl \
    git \
    vim
~~~

Para invalidar el uso del cache se puede usar:
~~~bash
docker build -t user/image:1.0 . --no-cache=true
~~~

Ejecución
~~~bash
sudo docker run -it user/image:1.0
~~~

# Enlace entre contenedores
Es utilizado para crear microservicios
Docker crea un túnel seguro entre contenedores para que estos no expongan puertos externamente
~~~bash
# Se crea un contenedor especificando un nombre
docker run -d --name redis redis:3.2.0
# Comprobar que esté corriendo bajo el nombre correcto
docker ps
# Construye la app en que se encuentre la app
docker build -t dockerapp:1.0 .
# Ejecuta el contenedor
docker run -d -p 5000:5000 --link nombre_contenedor dockerapp:2.0
~~~

**¿Por qué funciona esto?**
~~~bash
cat /etc/hosts
# IP id_contendor nombre_contenedor
~~~

# Docker Compose
Sirve para desplegar diversas imagenes de Docker de manera automatizada

Archivo
- docker-compose.yml

~~~bash
# Levanta la aplicacion
docker-compose up

# Genera los logs
docker-compose logs

# Genera los logs -f
docker-compose logs

# Consulta logs para imagen en especifico
docker-compose logs docker_image

# Verifica estado de los contenedores creados por docker
docker-compose ps

# Finalizar ejecución
docker-compose stop 

# Reinicia
docker-compose up
# Inicia
docker-compose start
# Borra
docker-compose rm

# Para reconstruir las imagenes
docker-compose build

~~~

## Redes con Docker Compose
Ejemplo
`docker-compose.yml`
~~~yml
version: '3'
services:
  dockerapp:
    build: .
    ports:
      - "5000:5000"
    depends_on:
      - redis
    networks:
      - my_net
  redis:
    image: redis:3.2.0
    networks:
      - my_net

networks:
  my_net:
    driver: bridge
~~~
Correrlo
~~~
docker-compose up -d
~~~

# Redes en Docker

## Inspeccionar tipo de redes
~~~bash
docker network ls
# 0b38e00cff30   bridge    bridge    local
# 713b2164fa61   host      host      local
# f0a5ab3ecf2a   none      null      local
~~~

**Inspeccionar red**
~~~bash
docker network inspect bridge
~~~

## Red none

**Crear contenedor red none**
~~~bash
docker run -d --net none ubuntu sleep 60
~~~

## Red Bridge
Parecido a red NAT

**Crear contenedor red Bridge**
~~~bash
docker run -d --name nombre ubuntu sleep 60
~~~
+ se omite el `--net` porque se asigna esta red por defecto

## Crear/Borrar tu propia red

**Crear una nueva red**
~~~bash
# Creamos la red
docker network create --driver bridge mi_nueva_bridge
# Inspeccionamos las redes
docker network ls
# Inspeccionamos la que queremos
docker network inpect mi_nueva_bridge
# Asociación
docker run -d --net mi_nueva_bridge ubuntu sleep 60
~~~

## Gestión de redes

**Añadir una nueva red a un contenedor existente**
~~~bash
# Conectar a red existente
docker network connect bridge contenedor_nombre
# Desconectar
docker network disconnect bridge contenedor_nombre
# Corroborar (ping o ifconfig)
docker exec -it contenedor_nombre ifconfig
~~~

## Red Host 
Parecida a bridge de vmware
+ En teoría no es necesario, porque para eso existe la opción -p (?)
+ No está aislado

~~~bash
# Crear contenedor abierto
docker run -d --name contenedor_abierto --net host busybox sleep 100
~~~

## Red Overlay  
Soporta múltiples maquinas host
Requiere condiciones preexistentes
+ Docker engine en modo Swarm


# Almacenamiento de datos
~~~bash
# Crear un nuevo volumen
docker volume create ejemplo
# Eliminar volumen
docker volume rm ejemplo

# Ver volumenes creados
docker volume ls

# docker volume inspect ejemplo
docker volume inspect ejemplo

# Asignar un volumen a una imagen
docker run -p 8000:8000 -v ejemplo:/app -d --name name user/imagen:1.0
~~~


# Ejemplos

## Ejemplo Apache Tomcat
+ https://hub.docker.com/_/tomcat
~~~bash
docker run -it --rm tomcat:9.0
docker run -it --rm -p 8888:8080 tomcat:9.0
~~~

## Crea tu propio "hola mundo" con Dockerfile

**Crea un dockerfile**
~~~bash
vim Dockerfile
~~~

**Contenido del Dockerfile**
~~~Dockerfile
FROM debian
RUN apt-get update && apt-get install -y \
    vim
CMD ["echo", "Hola, hola :)"]
~~~
+ Usamos `apt-get` porque `apt` muestra la siguiente advertencia
    + WARNING: apt does not have a stable CLI interface. Use with caution in scripts.

## Servidor web en Flask

**Estructura del directorio**
~~~bash
-rw-r--r-- 1 user user  143 Jan  4 17:37 Dockerfile
-rwxr-xr-x 1 user user   51 Jan  4 14:54 edit.sh
drwxr-xr-x 2 user user 4096 Jan  4 14:49 files
drwxr-xr-x 2 user user 4096 Jan  4 17:37 flask
    -rw-r--r-- 1 user user 171 Jan  4 17:37 app.py
~~~

**Dockerfile**
~~~Dockerfile
FROM python:3.7
RUN pip install Flask==0.11.1
RUN useradd -ms /bin/bash admin
USER admin
WORKDIR /app
COPY flask /app
CMD ["python", "app.py"]
~~~

**Servidor de python**
~~~python
from flask import Flask
app = Flask(__name__)

@app.route('/')
def index():
    return 'Web App with Python Flask!'

app.run(host='0.0.0.0', port=8888)
~~~

**Build docker**
~~~bash
docker build -t elcaza/flask_hello:1.0 .
~~~

~~~bash
# Obtenemos nuestra ip
ip a
# 192.168.100.48

# Inicializamos nuestro contenedor
docker run -d -p 9999:8888 id_docker
# OUTPUT
# user@debian11:~/Documents/Docker$ curl http://192.168.100.48:9999
# Web App with Python Flask!
~~~
