# Scp

## Descarga

```bash
scp username@example.com:/backup/file.zip /local/dir
scp -i private_key.pem username@example.com:/backup/file.zip /local/dir
```

## Subida

```bash
scp file.zip username@example.com:/remote/dir
```

## Base64
```bash
remote.example.net$ base64 <myfile
# (copy the output)

local.example.net$ base64 -d >myfile
# (copy the output)
# Ctrl+D
```