# Hacer peticiones con curl

```bash
curl -X POST -H "Content-Type:application/json" --data '{"identifier":"user","password":"password"}' 127.0.0.1:1337/auth/local
```
Para filtrar un atributo del json
+ | jq -r '.id_token'

```bash
curl -X POST -H "Content-Type:application/json" --data '{"identifier":"user","password":"password"}' 127.0.0.1:1337/auth/local | jq -r '.id_token'
```

## Decodificar con:
https://jwt.io/

***************************************************

# Creackear hashes

## hashcat

La sintaxis de la herramienta es la siguiente:
```bash
# Using a Wordlist:  
hashcat -a0 -m 16500 text.hash [dict]

# Pure Brute force attack:  
hashcat -a3 -m 16500 text.hash ?d?d?d?d

# Brute force to 4 digits password
hashcat -a3 -m 16500 text.hash ?d?d?d?d
```

***************************************************

# Crear usuarios

```bash
curl -X POST -H "Content-Type:application/json" --data '{"username":"user","password":"password","email":"test@test.com","role":"1", "provider":"x"}' 127.0.0.1:1337/auth/local
```