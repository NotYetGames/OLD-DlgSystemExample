# DlgSystem (Dialogue System) Plugin Example Project

Branch Unreal version: `4.19`

Example project for the [DlgSystem](https://gitlab.com/NotYetGames/DlgSystem/tree/4.19) plugin.

See the [Wiki](https://gitlab.com/NotYetGames/DlgSystem/wikis/home) for the manual and tutorials.
A blueprint only version of this example project for `4.18` can be downloaded from [here](https://www.dropbox.com/s/b946mre9zw5mlx7/DlgExampleBP.zip?dl=0).

## Clone
```sh
git clone -b 4.19 https://gitlab.com/NotYetGames/DlgSystemExample.git
```

## Update (pull) 

Update:
```sh
# Update this repo
git pull
# Update Subtree
git subtree pull --prefix Plugins/DlgSystem https://gitlab.com/NotYetGames/DlgSystem.git 4.19 --squash
```

## Push subtree modifications
NOTE: This is only if you modified the `Plugins/DlgSystem` subtree.
```sh
git subtree push --prefix=Plugins/DlgSystem https://gitlab.com/NotYetGames/DlgSystem.git 4.19
```

## Other
NOTE: repo was added with the following command.

NOTE: Branch `master` does no longer exist.
```sh
git subtree add --prefix Plugins/DlgSystem https://gitlab.com/NotYetGames/DlgSystem.git master --squash
```
