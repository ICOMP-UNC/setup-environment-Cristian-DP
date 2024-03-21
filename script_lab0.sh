#!/bin/bash

echo "## Aplicamos lang-format -style=Microsoft -i a include y src "
clang-format -style=Microsoft -i include/*
clang-format -style=Microsoft -i src/*

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

echo ""

# Construimos el projecto
echo "## cd build"
cd build && cmake -GNinja .. && ninja

echo ""

# Ejecutamos el proyecto
echo "## ./lab0"
./lab0

# Eliminamos el directorio build
rm -r ../build
rm -r ../Makefile
