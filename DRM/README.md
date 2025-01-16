# deDRM

## Requerimientos
+ Kindle Account with SERIAL and purchased books
+ Calibre app
    + https://calibre-ebook.com/download_windows
+ Older version of Kindle app for windows or mac 
    + + https://kindleforpc.s3.amazonaws.com/70904/KindleForPC-installer-2.4.70904.exe

## Breve explicación de lo que se hace
1. Desinstalar todo lo referente a la app de Kindle en Windows o mac. Observa que no exista contenido en los siguientes lugares
    + C:\Users<USER>\AppData*\Amazon 
    + C:\Program Files\Amazon 
    + C:\Program Files (x86)\Amazon 
    + C:\ProgramData\Amazon
1. Descaragar plugin para Calibre (DeDRM v10.0.9)
    + https://github.com/noDRM/DeDRM_tools/releases/tag/v10.0.9
    + Descomprimir el zip
1. Instalar Calibre y sus plugins
    + Instalar Calibre
    + Instalar el plugin "noDRM" desde el zip descargado
    + Instalar KFX input plugin
    + Reiniciar Calibre
1. Instalar Kindle Reader App
    + Descargar la app en su versión: 2.4.70904
        + https://kindleforpc.s3.amazonaws.com/70904/KindleForPC-installer-2.4.70904.exe
    + Quitar temporalmente el internet. Si no lo haces Kindle actualizará automáticamente a una versión más nueva y no funcionará
    + Instalar 
    + Añadir un nuevo path para el almacenamiento de libros
        + Tools > Options > Content > define a new path to save the kindle books you download
    + Deshabilitar las actualizaciones automáticas
        + Tools > Options > General > disable "Automatically install updates..."
    + Iniciar sesión y descargar los libros
1. Quitar el DRM 
    + Ubicar los archivos de los libros
    + A través de arrastrar el libro hacia la App de Calibre (solo funciona así), arrastrar para añadir el libro
    + click derecho y convertir a otro formato

## Sources
+ https://www.reddit.com/r/Calibre/comments/1c2ryfz/2024_guide_to_dedrm_kindle_books/
+ https://www.reddit.com/r/Calibre/comments/1ck4w8e/2024_guide_on_removing_drm_from_kobo_kindle_ebooks/?tl=es-es&rdt=52686