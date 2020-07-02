# Authentication Bypasses

Las omisiones de autenticación suceden de muchas maneras, pero generalmente aprovechan algunas fallas en la configuración o la lógica. Manipulación para lograr las condiciones adecuadas.

## Entradas ocultas

La forma más simple es confiar en una entrada oculta que se encuentra en la página web / DOM.

## Eliminar parámetros

A veces, si un atacante no conoce el valor correcto de un parámetro, puede eliminar el parámetro del envío por completo para ver qué sucede.
Navegación Forzada

## Fuerza bruta
Si un área de un sitio no está protegida adecuadamente por la configuración, se puede acceder a esa área del sitio mediante adivinanzas / fuerza bruta.

# Ejercicio 1 (2)
Este ejercicio pide que hagamos bypass del formulario para poder cambiar nuestro password. 
Si interceptamos el tráfico podremos observar esta petición:

```
secQuestion0=ttettasdf&secQuestion1=tes&jsEnabled=1&verifyMethod=SEC_QUESTIONS&userId=12309746
```

Donde tenemos:
+ secQuestion0=value
+ secQuestion1=value
+ jsEnabled=1
+ verifyMethod=SEC_QUESTIONS
+ userId=12309746

Nosotros entonces podemos inferir que `secQuestion0` es validada con una base de preguntas y `secQuestion1` es validada con otra. Sin embargo, ¿Qué pasa si cambiamos esas preguntas por alguna qué salga de rango? Es decir:
+ secQuestion2
+ secQuestion3

Incluso más. Esto lo podemos hacer de manera manual o a través del secuencer.