# Opciones de crunch

Uso General
```
crunch <min> <max> -o <outputFile> -f <rutaNombreDeCharset> <mapaDeCaracteresElegidos> -t <patronVariable@@@> -c <intPalabrasEnQueSeCortan>
crunch <1> <1> -o <outputFile> -p <palabra1> <palabra2> <palabra3>
```

```
crunch <min> <max>
crunch 2 2
	// Retorna las combinaciones posibles entre a-z
```

```
crunch <min> <max> -f <charsetName.lst> <charsetName>
crunch 2 2 -f charlist.lst numeric
	// Retorna las combinaciones posibles en el charset seleccionado
```

```
crunch <min> <max> <caracteresElegidos>
crunch 2 2 0123asdfASDF
	// Retorna las combinaciones posibles entre los caracteres
```

```
crunch <min> <max> -t asdf@@@@
crunch 2 2 -t asdf@@@@
	// Retorna las combinaciones con un patrón especifico
```


crunch <min> <max> -f <charsetName.lst> <charsetName> -t asdf@@@@
crunch 3 3 -f charset.lts numeric -t a@@

crunch 5 5 -t @,%^
	@  insertara minusculas
	,    insertara mayusculas
	%  insertara numeros
	^   insertara simbolos

crunch <x> <x> -p <Palabra1> <Palabra2> <Palabra3>
crunch 1 1 -p Palabra1 String2 Tres

crunch -o <outputFile.txt>

crunch 1 1 -o <RUTA/START> -c 100
	// Corta en diccionarios de 100 lineas

