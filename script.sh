#!/bin/bash

# Buscar el directorio "build" en el directorio actual
if [ -d "./build" ]; then
    echo "Se encontró el directorio 'build' en $(pwd)"
    echo "Se eliminará su contenido"
    rm -r ./build/*
else
    echo "No se encontró el directorio 'build' en $(pwd)"
    echo "Se creará el directorio ./build"
    mkdir build
fi

echo ">> cd build"
cd build

echo ">> cmake .."
cmake ..

echo ">> cmake --build ."
cmake --build .

echo ">> ./lab0_executble "
./lab0_executble 
