# DlgSystem (Dialogue System) Plugin Example Project

Used Unreal version: 4.18

Example project for the [DlgSystem](https://gitlab.com/NotYetGames/DlgSystem) plugin.

See the [Wiki](https://gitlab.com/NotYetGames/DlgSystem/wikis/home) for the manual and tutorials.

## Clone
```sh
# Cloning all submodules
git clone --recursive -j2 https://gitlab.com/NotYetGames/DlgSystemExample.git
```

```sh
# If you cloned without the --recursive flag, run the following command
git submodule update --init --recursive
```

## Update 
```sh
git pull
# Update submodules
git submodule foreach git pull origin master
```