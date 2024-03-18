# Buscar el directorio "build" en el directorio actual
if [ -d "./docs" ]; then
    echo "## Se encontró el directorio 'docs' en $(pwd)"
    echo "Se crearan la documentacion"
    doxygen

    echo "Abra el archivo ./docs/docs/html/index.html en su navegador preferido"
else
    echo "## No se encontró el directorio 'docs' en $(pwd)"
    echo "## Se creará el directorio ./docs"
    mkdir docs && cd docs

    echo "Se crearan el archivo Doxyfile"
    doxygen -g

    echo "Actualice los campos del Doxyfile y vuelva a ejecutar el script"
    exit 1
fi