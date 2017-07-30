# Need4Stek
Ce projet a pour but de créer une petite intelligence artificielle qui contrôle une voiture sur un circuit donné.

Elle doit être capable de terminer des circuits simples sans toucher de murs et en allant le plus vite possible.

Le logiciel de simulation 3d utilisé est VREP donc si vous voulez tester vous pouvez télécharger la version edu [ici](http://www.coppeliarobotics.com/downloads.html)

![exemple](https://image.prntscr.com/image/XTuXYcuSREyVTJskx5YCuA.png)

# Utilisation
Pour lancer l'ia il faut d'abord lancer VREP donc après l'avoir extrait allez dans le dossier VREP_PRO_EDU_V.. et executez **./vrep.sh**

Après ça VREP devrait s'ouvrir go dans File>Open Scene et selectionnez une des scenes dans le dossier VREP/scenes du repo 

Maintenant il faut compiler l'ia donc ouvrez un terminal et tapez la commande **make** puis lancez la commande **./pipes.sh** et la voiture devrait commencer à bouger

Attention à bien sélectionner "ODE" et non "Bullet.." en haut.
