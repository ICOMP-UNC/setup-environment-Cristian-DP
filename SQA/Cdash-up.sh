#!/bin/bash

# Solicitar al usuario que ingrese el parámetro
echo "1. Clonar Cdash"
echo "2. Levantar contenedores docker"
echo "3. crear usuario por defecto"

read -p "Por favor ingrese su eleccion: " choise

# Comparar el parámetro
if [ $choise -eq 1 ]; then
    echo "Se clonará CDash"
    git clone https://github.com/Kitware/CDash
elif [ $parametro -eq 2 ]; then
    echo "Se crearán los contendores docker"
    docker-compose  -f CDash/docker/docker-compose.yml \
                    -f CDash/docker/docker-compose.dev.yml  \
                    -f CDash/docker/docker-compose.mysql.yml \
                    --env-file CDash/.env.dev \
                    up -d 
elif [ $parametro -eq 2 ]; then
    echo "Se creará usuario por defecto"
    echo "--email=cristian.pereyra@lab0.so2 --password=12345678"
    echo "--firstname=cristian --lastname=pereyra"
    echo "--institution=lab0-SO2 --admin=1"
    docker exec --user www-data cdash bash -c "php artisan user:save --email=cristian.pereyra@lab0.so2 --password=12345678 --firstname=cristian --lastname=pereyra --institution=lab0-SO2 --admin=1"
fi
