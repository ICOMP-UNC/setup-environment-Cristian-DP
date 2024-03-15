# Cristian Pereyra - Lab0: setup environment


# Indices

1. [Git](#git)
    1.1. [Conexión con GitHub](#conexión-con-github)
    1.2. [Ramas](#ramas)

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