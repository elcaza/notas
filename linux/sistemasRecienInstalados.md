# Sistemas recien instalados (vmware)

## Instalar las herramientas de compilación básicas
```
sudo apt -y install build-essential
sudo apt -y vim git
```

## Añadir usuario a sudoers
`sudo vim /etc/sudoers`

## Remover sourcelist CD
`sudo vim /etc/apt/sources.list`

## Instalar Linux Headers
```    
sudo apt install linux-headers-$(uname -r )
```

***

## Instalar las herramientas de vmWare
```
sudo apt -y install open-vm-tools
sudo apt -y install open-vm-tools-desktop
```

* Es necesario reiniciar luego de instalar las vm-tools