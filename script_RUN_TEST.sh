#!/bin/bash -e

echo ""

# Buscar el directorio "build" en el directorio actual
if [ -d "./build" ]; then
    echo "## Se encontró el directorio 'build' en $(pwd)"
    echo "## Se eliminará su contenido"
    rm -r ./build/*
else
    echo "## No se encontró el directorio 'build' en $(pwd)"
    echo "## Se creará el directorio ./build"
    mkdir build
fi

echo "Compilamos el proyecto"
cd build && cmake -GNinja -DRUN_COVERAGE=1 ..

echo "Construimos el proyecto test"
ninja

echo "Ejecutamos los test en modo verbose"
ctest --test-dir tests/ -VV

echo "Ejecutamos el analisis de cobertura"
gcovr -r /home/devuser/Facultad/SO2/setup-environment-Cristian-DP .
