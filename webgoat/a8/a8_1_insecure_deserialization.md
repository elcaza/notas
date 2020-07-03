# Insecure Deserialization

## Serlialización
Es el proceso de convertir un objeto en datos "string" para posteriormente restaurarlos
+ XML
+ json

## Deserialización
Es el proceso de convertir esos "datos" un "string" en un objeto. Mal empleado permite:
+ DOS
+ Control de acceso
+ Ejecución remota de código

## Lenguajes de programación afectados conocidos
+ PHP
+ Python
+ Ruby
+ Java
+ C
+ C++

## Datos, no Código
SOLO los datos se serializan. El código no está serializado. La deserialización crea un nuevo objeto y copia todos los datos del flujo de bytes, para obtener un objeto idéntico al objeto que se serializó.