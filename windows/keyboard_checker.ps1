# Script para checar si funciona tu teclado
# Imprimirá la tecla que presiones

"Presiona teclas para verificar que tu teclado funcione"
"Presiona CTRL+C para salir"
do
{
    ""
    "=========================================================="
    "Tecla presionada:"
    $key = $Host.UI.RawUI.ReadKey()
    $key
    ""

} while ($true)