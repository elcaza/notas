# Utilerias UNIX
Las utilerias de UNIX son programas que nos permiten:
+ Obtener información
+ Procesamiento de información
+ Control y presentación de la información

## Teoría

### Filtros
Estos son un grupo de comandos que:
1. Leen una entrada
2. Realizan una transformación
3. Escriben una salida

**(No se altera el origen, únicamente el destino )**

### Metacarácteres
Son carácteres con un significado especial en UNIX
+ Metacarácteres de shell
+ Expresiones regulares

### Operaciones de entrada y salida
En UNIX todo es un archivo, por tanto las operaciones entre procesos no son más que eso *"archivos interactuando entre sí"*

Byte Stream 
+ Un archivo se presenta como una secuencia no estructurada de bytes
+ El sistema operativo únicamente ve bytes no estructurados

### Archivos del kernel
En cada proceso del kernel se mantiene una tabla de archivos abiertos:
+ Un archivo puede ser cualquier dispositivo de entrada y salida

Cada proceso en kernel tiene asociado 3 archivos abiertos por defecto:
+ STDIN => Entrada estándar => fd=0
+ STDOUT => Salida estándar => fd=1
+ STDERR => Salida de error estándar => fd=2

*(fd = File descriptor)*

### Redireccionamientos
Para interactuar entre programas/procesos se utilizan los redireccionamientos, estos pueden ser destructivos y no destructivos

| Significado | Forma | Bourne Shell | Ejemplo |
| -- | -- | -- | -- |
| stdin de archivo | ND | programa < archivo | Ejemplo |
| stdout a archivo | D | programa > archivo | `ls -l > lista_archivos` |
| Añade stdout a archivo | ND | programa >> archivo | `ls -l >> lista_archivos` |
| stderr a archivo | D | programa 2> archivo | `mkdir 2> error_mkdir_sin_argumento` |
| Añade stderr a archivo | ND | programa 2>> archivo | `mkdir 2>> error_mkdir_sin_argumento` |
| stdout y stderr a archivo | D | programa > archivo 2>&1 | `mkdir 2>> error_mkdir_sin_argumento` |
| stdin de fuente actual hasta delimitador | ND | programa << delimitador | Ejemplo |
| Añade stdout y stderr a archivo | ND | programa >> archivo 2>&1 | Ejemplo |
| stdout de programa_1 a stdin de programa_2 | - | programa_1 \| programa_2 | Ejemplo |
| stdout y stderr de programa_1 a stdin de programa_2 | - | programa_1 2>&1 \| programa_2 | Ejemplo |

### Tipos de comillas 

**'simples'**
+ Bourne shell: Desactivan el significado especial de cualquier carácter
+ C shell: Desactivan el significado especial de cualquier carácter excepto: **!**

**"dobles"**
+ Bourne shell: Desactivan el significado especial de cualquier carácter excepto: **$ `  \\**
+ C shell: Desactivan el significado especial de cualquier carácter excepto: **! $ `**

**\\**
+ \ Desactiva el significado especial del caracter a su derecha

**\`comando\`** y **$(comando)**
+ Tomará el texto como un comando, será ejecutado y la salida será sustituida por el texto original
+ Ejemplo:

```bash 
echo "Hola, yo soy `whoami`"
# Output 
# Hola, yo soy user

echo "Hola, hoy es $(date)"
# Output
# Hola, hoy es Thu Aug 13 11:47:04 PDT 2020
```


## Utilerías 
El manual de todas las utilerías lo puedes consultar con:

`man utileria`

### Collating
Estas son variables del sistema y están definidas por:
+ `LC_COLLATE=C`
+ `LANC=C`

Se pueden consultar con un
+ `echo $LC_COLLATE`
+ `echo $LANC`

Dada la configuración regional del mapa de caracteres de cada computadora es necesario establecer un "collate" adecuado para que nuestros programas se comporten de la manera pensada.

¿A qué nos referemos? 

Dependiendo de la configuración que tengamos el orden mediante un `ls` podría ser:
```

A a B b C c 

A B C a b c 
```


### Manejo de textos

#### cut
Permite cortar columnas o campos de texto de un archivo o de la salida estándar

Sintaxis básica
```bash
cut OPTION... [FILE]...

-f campos           Campos que serán cortados
-d delimitador      Separador de campos
```

Ejemplo
```bash
cat /etc/passwd | cut -d ":" -f 1,3

cut -d ":" -f 1,3 /etc/passwd
```

#### sort
Ordena el contenido de un archivo

Sintaxis básica:
```bash
sort [OPTION]... [FILE]...

-r  Ordenamiento desc-asc
-n  Ordenamiento numérico
-g  Ordenamiento general numérico
-f  Ignora diferencia entre mayúsculas y minúsculas
-u  Borra líneas duplicadas
-k  Campos a ordenar
-t  Separador de campo
```

Ejemplo:
```bash
sort /etc/passwd

cat /etc/passwd | sort
```

#### tail
Muestra la "n" última parte de un archivo. Por defecto las últims diez líneas.

Sintaxis básica:
```bash
tail [OPTION]... [FILE]...

-n 20     números de líneas a mostrar
-n +20    A partir de esa línea mostrar   
-f        No regresa el control a la shell, entrará a un ciclo en donde cada segundo se volverá a aplicar sobre el archivo. Útil para monitorear el crecimiento de un archivo.

```

Ejemplo:
```bash
# Ultimas 10 líneas
tail /etc/passwd

# Ultimas 20 líneas
tail -n 20 /etc/passwd

# A partir de la línea 20
tail -n +20 /etc/passwd
```

#### head
Muestra la "n" última parte de un archivo. Por defecto las últims diez líneas.

Sintaxis básica:
```bash

```

Ejemplo:
```bash

```

Sintaxis básica:
```bash

```

Ejemplo:
```bash

```

#### paste
Descrip

Sintaxis básica:
```bash

```

Ejemplo:
```bash

```

#### tr
Descrip

Sintaxis básica:
```bash

```

Ejemplo:
```bash

```

#### uniq
Descrip

Sintaxis básica:
```bash

```

Ejemplo:
```bash

```

### Cálculos y conteos

#### seq

Sintaxis básica:
```bash
seq [OPTION]... LAST
seq [OPTION]... FIRST LAST
seq [OPTION]... FIRST INCREMENT LAST

-f, --format=FORMAT
	use printf style floating-point FORMAT

-s, --separator=STRING
	use STRING to separate numbers (default: \n)

-w, --equal-width
	equalize width by padding with leading zeroes

```

Ejemplo:
```bash
# Crea carpetas del 1 al 10
for i in `seq 1 10`; do mkdir carpeta$i; done 

# Crea carpetas del 01 al 10
for i in `seq -w 1 10`; do echo carpeta$i; done 

# Alternativa
mkdir carpeta0{00..09} carpeta{10..99}
```
+ Referencias 
	+ https://serverfault.com/questions/397762/how-to-make-folders-00-99-with-a-single-command-in-ubuntu/397768

#### Otro

Sintaxis básica:
```bash

```

Ejemplo:
```bash

```