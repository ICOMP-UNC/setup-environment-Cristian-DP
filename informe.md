# Cristian Pereyra - Lab0: setup environment


# Indices

- [1. Git](#1-git)
	- [1.1 Conexión con GitHub](#11-conexión-con-github)
	- [1.2 Ramas](#12-ramas)
- [2. cmake](#2-cmake)
	- [2.1. Construyendo un proyecto básico](#21-Construyendo-un-proyecto-básico)
	- [2.2 Listo para construir y ejecutar](#22-Listo-para-construir-y-ejecutar)

# 1. Git

## 1.1. Conexión con github

- https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent
- https://docs.github.com/en/authentication/connecting-to-github-with-ssh/adding-a-new-ssh-key-to-your-github-account

```bash
devuser@debian11-2:~/Facultad/SO2$ ssh-keygen -t ed25519 -C "__email__"
Generating public/private ed25519 key pair.
Enter file in which to save the key (/home/devuser/.ssh/id_ed25519): __enter__
Enter passphrase (empty for no passphrase): __enter__
Enter same passphrase again: __enter__
Your identification has been saved in /home/devuser/.ssh/id_ed25519
Your public key has been saved in /home/devuser/.ssh/id_ed25519.pub
The key fingerprint is:
__(Se oculto informacion)__
The key's randomart image is:
__(Se oculto informacion)__

```

```bash
devuser@debian11-2:~/Facultad/SO2$ git clone git@github.com:ICOMP-UNC/setup-environment-__oculto__.git

```

## 1.2. Ramas

Se crearon tres ramas:

- **cmake-config:** Se resolverá todo lo referido al apartado cmake
- **unity-integration:** Se resolverá todo lo referido a unity-integration
- **github-actions-config:** Se resolverá todo lo referido a github-actions-config

```bash
git branch // Lista todos los branch disponibles
git branch *nombre_de_rama* // se crea una rama nueva
git switch *rama* // se selecciona rama
```

# 2. cmake

## 2.1. Construyendo un proyecto básico
(https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

- **cmake_minimun_required (VERSION version [FATAL_ERROR]):** Esto establece la configuración de políticas y garantiza que las siguientes funciones de CMake se ejecuten con una versión compatible de CMake.
La opción FATAL_ERROR se acepta pero CMake 2.6 y versiones posteriores la ignoran. Se debe especificar para que las versiones 2.4 e inferiores de CMake produzcan un error en lugar de solo una advertencia.

```bash
$ cmake --version
cmake version 3.25.1

CMake suite maintained and supported by Kitware (kitware.com/cmake).
```

- **project():** Esta llamada es obligatoria en cada proyecto y debe realizarse poco después de cmake_minimum_required(). Este comando también se puede utilizar para especificar otra información a nivel de proyecto, como el idioma o el número de versión

```bash
project(<PROJECT-NAME>
        [VERSION <major>[.<minor>[.<patch>[.<tweak>]]]]
        [DESCRIPTION <project-description-string>]
        [HOMEPAGE_URL <url-string>]
        [LANGUAGES <language-name>...])
```

- **add_executable():** le dice a CMake que cree un ejecutable usando los archivos de código fuente especificados.

```bash
add_executable(<name> 	 #nombre de ejecutable
			<options>... #so de ejecución
			<sources>... #cofigo fuente
)
```

## 2.2 Listo para construir y ejecutar

- usando script

```bash
$ sh script.sh
```

- Paso a paso

```bash
$ mkdir build && cd build

#configurar el proyecto y generar un sistema de compilación nativo
$ cmake ../	
-- The C compiler identification is GNU 12.2.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/devuser/Facultad/SO2/setup-environment-Cristian-DP/build

# compilar/vincular el proyecto
$ cmake --build .
[ 50%] Building C object CMakeFiles/lab0_executble.dir/src/main.c.o
[100%] Linking C executable lab0_executble
[100%] Built target lab0_executble

# Run el ejecutable
$ ./lab0_executble 
Bienvenido a main de lab0-SO2-2024

```
