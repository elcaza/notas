# Descargar archivos desde una terminal en Windows

## CMD

```cmd
set url=https://d.winrar.es/d/101z1604783853/wS8eHLkeU3JIJ6EkflJo2g/winrar-x64-591.exe
set file=winrar-x64-591.exe
certutil -urlcache -split -f %url% %file%
echo Done!
```
* Te manda una alerta si descargas un .exe

## Powershell

```powershell
$job = Start-Job { 
	# Con el $using bindeamos el contexto de la función para enviar la variable program_location
	Set-Location $using:program_git_location
	function download_git {
		"FN: Descargando git..."
		Invoke-WebRequest -Uri $using:git_client -OutFile ".\git.exe"
	} download_git
}
# Creamos una tarea asincrona
Wait-Job $job
Receive-Job $job
"FN: Git Descargado"

$url = "https://www.7-zip.org/a/7z1900-x64.msi"
# $url = "https://d.winrar.es/d/101z1604783853/wS8eHLkeU3JIJ6EkflJo2g/winrar-x64-591.exe"
$file = "7zip1900-x64.msi"
Invoke-WebRequest -Uri $url -OutFile $file

```