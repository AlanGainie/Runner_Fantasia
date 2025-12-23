# Runner fantasia
##### A runner to name is fantasia. Game start and go with Alan Gainié

## L'objectif du projet

Le but de se projet est de faire une sorte de runner afin de se remetre dans le bain du CSFML et de la création/ édition de jeux vidéo 2D rétro. Ce que je vais essayer de réaliser :

- Facile
-> Mettre en place un background animer (parralaxe)
-> Mettre en place les déplacements des personnages
-> Gérer les sprites (croper)
-> Mettre des sounds effect

- - Moyen
-> Mettre en place un system de saut personnaliser (parrabolique)
-> Faire une mini map
-> Ajouter un item de pièce
-> Ajouter un drapeau (condition de fin)

- - - Difficile
-> Mettre en place un boutton cliquable afin de pouvoir sauvegarder la progression
-> Rajoutter des options
-> Faire des chargements de niveaux personnaliser

- - - - Hardcore
-> Ajouter des énemie

## Githelp

Dans ce projet ont utilise github dans se but nous avons besoin des commandes suivantes :

    Commande de base LINUX/WINDOWS en indite de commande:
        git status -> permet de voir l'état des add, commit, push

        git add ... -> Ajouter l'ensemble des fichiers modifier qu'on souhaite envoyé
        git commit -m ... -> Nomme l'envoie (pareil qu'un timbre pour une envelope)
        git push -> envoie le paquet

        git pull -> Pour récupérer le contenue du git
        git merge -> Pour rassembler le contenue local (tien) et celui du git

# Méthodologie
Ce projet à été réaliser avec la norme d'epitech. Etant ancienne étudiant d'Epitech et aillant apris le CSFML au prêt d'eux je me suis d'abord possitioner sur la norm d'Epitech afin de réaliser se projet.

# Etat du projet

Ce mecredi 10 septembre j'ai pue débuter la structure de base du projet. Et corriger certains bug relatif à un ancien program depuis le quelle avait été tirer quelques éléments de la structure présente. J'ai pu documenter avec des docxygène ainsi que mettre en place une structure plus professionelle pour mon program.

Ce jeudi 11 septembre j'ai pue retravailler les éléments afin de les optimisé les rendres plus dynamique et durable. Toutefois aillant d'autres projets en parrallèle je n'ai consacré que quelques heures dessus. Le premier ticket que j'attaque par conséquent est celui :

-> De réaliser une librarie dynamique pour des composants/élements que je vais réutiliser lors du program. Celle-ci contiendra dans sa V1 : initSprite, initIcon, initScene, initParralaxe, initButton, initScore

Ceux qui sont réaliser à se jour : ✅ initSprite, ✅ initIcon
