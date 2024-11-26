## Fichier de configuration de Dosbox-X

/Users/damien/Library/Preferences/DOSBox-X 2024.10.01 Preferences

## Lignes à modifier


set path    = Z:\;Z:\SYSTEM;Z:\BIN;Z:\DOS;Z:\4DOS;Z:\DEBUG;Z:\TEXTUTIL;C:\TC

[autoexec]
# Lines in this section will be run at startup.
# You can put your MOUNT lines here.
mount C: /Users/damien/dev/DOS/c_drive
mount D: /Users/damien/dev/DOS/d_drive 

## Passer en BÉPO

Il est possible de passer en bépo en utilisant un driver écrit pour FreeDos : xkeyb

xkeyb est fournis dans le disque C: et dans le dossier XKEYB

L’activation se fait via : XKEYB.EXE KEY/BEPO_850.KEY

## Lancer Dosbox avec la bonne config

alias dosbox="dosbox -conf /home/$USER/dev/DOS/dosbox.conf"

## XFCE

Il faut supprimer les raccourcis clavier qui utilisent les touches F* car elles empêchent le bon fonctionnement
des raccourcis dans TurboC++.

Gestionnaire de paramètres > Gestionnaire de fenêtres > Clavier