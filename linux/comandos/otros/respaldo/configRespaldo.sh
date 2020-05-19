#!/bin/bash

# Config para Respaldo automatizado V1
# @author henkerLove

CARPETA_RESPALDOS="/home/`whoami`/respaldos"
RUTA_SCRIPT="/home/antonio/Documents/comandos/respaldo.sh"
CARPETA_A_RESPALDAR="/var/www/html/cram2018/"
COMPRESION=""

if [ -d $CARPETA_RESPALDOS ]; then
	echo "Existe carpeta"
else
	mkdir $CARPETA_RESPALDOS
	#echo "Se ha creado carpeta"
fi

cd $CARPETA_RESPALDOS

if [ -e $RUTA_SCRIPT ] && [ ! -x $RUTA_SCRIPT ]; then
	echo "Existe el archivo"
	chmod +x $RUTA_SCRIPT
elif [ ! -e $RUTA_SCRIPT ]; then 
	echo "No se encuentra el script" 
	echo "No se encuentra el script" >> logError.txt
fi

( exec $RUTA_SCRIPT $CARPETA_A_RESPALDAR $COMPRESION )