# Taras asincronas
Para realizar una tarea asincrona se utiliza `Start-Job` y `Wait-Job `.

Esto hace que el scope de tus funciones actuales no sean alcanzadas. Sin embargo para solucionar esto podrías realizar lo siguiente:

``` powershell
$job = Start-Job { 
    function create_dir {
        mkdir 33
    }
    create_dir
}
Wait-Job $job
Receive-Job $job
```

# Variables con distinto scope en tareas asincronas
``` powershell
$Servername = 'Server1'
Start-Job { "Target: " + $using:ServerName } | Receive-Job -Wait -AutoRemoveJob
```

## Ejemplo conjunto
``` powershell
$Servername = 'zServer1'
Start-Job { 
    Set-Location $env:ProgramFiles
    mkdir $using:ServerName 
    "Target: " + $using:ServerName 
} | Receive-Job -Wait -AutoRemoveJob
```