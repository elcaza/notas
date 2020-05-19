#!/bin/bash

#Las variables deben ir sin espacios
variable="Hola"

#Para usar una variable se usa "$"
echo $variable
echo "Args:"

#Todos los argumentos
echo $*

#Arg 1
echo $1
#Arg 2
echo $2
#Arg n
echo $3

#!/bin/bash
#Test IF-ELSE

# echo ' Adivina el valor numerico de la variable'
# read A

# if [ $A = 1 ];
# then
# echo 'Has acertado'
# exit 0
# else
# if [ $A = 2 ];
# then
# echo 'Estuviste cerca'
# fi
# fi

# exit

# read opcion
#   case $opcion in
#       s|S) 
#          echo "pulso la opción SI"
#       ;;
#       n|N)
#          echo "pulso la opción NO"
#       ;;
#       *)
#          echo "desconozco esa opción"
#       ;;
#   esac