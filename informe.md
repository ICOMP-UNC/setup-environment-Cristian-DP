# Cristian Pereyra - Lab0: setup environment


# Indices

- [1. Git](#1-git)
	- [1.1 Conexión con GitHub](#11-conexión-con-github)
	- [1.2 Ramas](#12-ramas)
- [2. cmake](#2-cmake)
	- [2.1. Construyendo un proyecto básico](#21-Construyendo-un-proyecto-básico)
	- [2.2 Listo para construir y ejecutar](#22-Listo-para-construir-y-ejecutar)
	- [2.3 Agregando una libreria](#23-Agregando-una-libreria)
	- [2.4 Agregando libreria estatica y dinamica](#24-Agregando-libreria-estatica-y-dinamica)
- [3. Unity test](#3-Unity-test)
	- [3.1 Run Test](#31-Run-Test)
	- [3.2 Run Coverage](#32-Run-Coverage)

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

## 2.3 Agregando una libreria

Para agregar una biblioteca en CMake, use el comando **include_directories()** y especifique el directorio donde se encuentra los archivos header

```bash
include_directories (include)
```

## 2.4 Agregando libreria estatica y dinamica

1. Crear directorio 
	-	lib/lib[STATIC|DYNAMIC]/include
	-	lib/lib[STATIC|DYNAMIC]/src
	- 	lib/lib[STATIC|DYNAMIC]/CMakeLists.txt

2. Dentro de src declarar las funciones que serán utilizadas
3. Dentro de include declarar los headers a incluir
4. dentro de lib/lib[STATIC|DYNAMIC]/CMakeLists.txt asegurarse que esten ocnfigurados
	-	add_library (${PROJECT_NAME} [STATIC|SHARED] ${SOURCES})
5. Dentro del CMakeLists.txt top agregar
	- 	add_subdirectory(lib/libdyn)
	-	add_subdirectory(lib/libsta)
	-	target_include_directories( ${PROJECT_NAME} PUBLIC lib/libsta/include)
	-	target_include_directories(	${PROJECT_NAME}	PUBLIC lib/libdyn/include)
	-	target_link_libraries ( ${PROJECT_NAME}	static_library 	dinamyc_library)
6. Agregar al main.c
	- 	#include <dynamic.h>
	-	#include <math.h>


# 3. Unity test

## 3.1 Run Test

- comandos

```bash
$ cd build && make -GNinja -DRUN_TEST=1 ..
...
[1/9] Creating directories for 'unity-populate'
[1/9] Performing download step (git clone) for 'unity-populate'
Clonando en 'Unity'...
Tu rama está actualizada con 'origin/master'.
Ya en 'master'
[2/9] No update step for 'unity-populate'
[3/9] No patch step for 'unity-populate'
[5/9] No configure step for 'unity-populate'
[6/9] No build step for 'unity-populate'
[7/9] No install step for 'unity-populate'
[8/9] No test step for 'unity-populate'
[9/9] Completed 'unity-populate'
...

$ ninja

[12/12] Linking C executable tests/test_lab0

$ ctest --test-dir tests/ -VV

...
1: Test command: /home/devuser/Facultad/SO2/setup-environment-Cristian-DP/build/tests/test_lab0
1: Working Directory: /home/devuser/Facultad/SO2/setup-environment-Cristian-DP/build/tests
1: Test timeout computed to be: 10000000
1: /home/devuser/Facultad/SO2/setup-environment-Cristian-DP/tests/unity/main.c:45:test_mypow_base_and_exp_pos:PASS
1: /home/devuser/Facultad/SO2/setup-environment-Cristian-DP/tests/unity/main.c:46:test_mypow_base_neg_and_exp_pos:PASS
1: /home/devuser/Facultad/SO2/setup-environment-Cristian-DP/tests/unity/main.c:47:test_mypow_base_neg_and_exp_neg:PASS
1: /home/devuser/Facultad/SO2/setup-environment-Cristian-DP/tests/unity/main.c:48:test_mypow_base_pos_and_exp_neg:PASS
1: 
1: -----------------------
1: 4 Tests 0 Failures 0 Ignored 
1: OK
1/1 Test #1: test_lab0 ........................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.00 sec

```


## 3.2 Run Coverage

```bash
$ cmake -GNinja -DRUN_COVERAGE=1 ..

[1/9] Creating directories for 'unity-populate'
[1/9] Performing download step (git clone) for 'unity-populate'
Clonando en 'Unity'...
Ya en 'master'
Tu rama está actualizada con 'origin/master'.
[2/9] No update step for 'unity-populate'
[3/9] No patch step for 'unity-populate'
[5/9] No configure step for 'unity-populate'
[6/9] No build step for 'unity-populate'
[7/9] No install step for 'unity-populate'
[8/9] No test step for 'unity-populate'
[9/9] Completed 'unity-populate'

$ ninja

[12/12] Linking C executable tests/test_lab0

$ ctest --test-dir tests/

Internal ctest changing into directory: /home/devuser/Facultad/SO2/setup-environment-Cristian-DP/build/tests
Test project /home/devuser/Facultad/SO2/setup-environment-Cristian-DP/build/tests
    Start 1: test_lab0
1/1 Test #1: test_lab0 ........................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.00 sec

$ gcovr -r /home/devuser/Facultad/SO2/setup-environment-Cristian-DP .
------------------------------------------------------------------------------
                           GCC Code Coverage Report
Directory: ..
------------------------------------------------------------------------------
File                                       Lines    Exec  Cover   Missing
------------------------------------------------------------------------------
src/MathFunctions.c                           10       9    90%   17
tests/unity/main.c                            28      28   100%
------------------------------------------------------------------------------
TOTAL                                         38      37    97%
------------------------------------------------------------------------------
```

# Anexo

## A.1 Documentacion con Doxyfile

- Para crear Documentacion

```bash
$ cd docs 
$ doxygen
```
- Para crear Doxyfile

```bash
$ cd docs
$ oxygen -g 
```