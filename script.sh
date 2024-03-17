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

echo "## cd build"
cd build

echo ""

echo "## cmake .."
cmake ..

echo ""

echo "## cmake --build ."
cmake --build .

echo ""

echo "## ./lab0"
./lab0
