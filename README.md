# Runner fantasia
##### C'est un runner qui a pour nom Fantasia. Ce jeux débute et avancera grace à Alan Gainié

## L'objectif du projet

__Le but initial__

Le but initial étais de créer un jeu vidéo qui serrai une copie ou presque du projet de jeux vidéo flash créer en CSFML sous le nom de `Little-Mario-Bros` toutefois celui-ci étant régulièrement mis en suspend pour des raisons pratique, technique ou de motivation. Le projet : Runner Fantasia deviens aulieu d'une maquette un projet de jeu flash plus probable.

**Etape**

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
Ce projet à été réaliser avec une anciene norme d'Epitech Rennes. Etant ancienne étudiant d'Epitech et aillant apris le CSFML au prêt d'eux je me suis d'abord possitioner sur la norme d'Epitech afin de réaliser se projet.

# Etat du projet

**Ce mecredi 10 septembre** j'ai pue débuter la structure de base du projet. Et corriger certains bug relatif à un ancien program depuis le quelle avait été tirer quelques éléments de la structure présente. J'ai pu documenter avec des docxygène ainsi que mettre en place une structure plus professionelle pour mon program.

**Ce jeudi 11 septembre** j'ai pue retravailler les éléments afin de les optimisé les rendres plus dynamique et durable. Toutefois aillant d'autres projets en parrallèle je n'ai consacré que quelques heures dessus. Le premier ticket que j'attaque par conséquent est celui :

-> De réaliser une librarie dynamique pour des composants/élements que je vais réutiliser lors du program. Celle-ci contiendra dans sa V1 : initSprite, initIcon, initScene, initParralaxe, initButton, initScore

Ceux qui sont réaliser à se jour : ✅ initSprite, ✅ initIcon

Depuis cette date aucune mise à jour n'a été réaliser sur le projet aillant eut beaucoup de chose à réaliser en parrallèle IRL. Toutefois pour revenir au progression pour le premier tickets qui comporte en somme plusieurs éléments il à été réaliser : 

Une amélioration des éléments : 🌳 Structure de code (arborescence), ✅ initSprite, ✅ initIcon

Créations des éléments : ✅ initMacros, ✅ initScene, ✅ initText

Qui sont d'ailleurs à améliorer. J'ai aussi ajouter un program interne de création de log `log_message` et décomposer la structure avec un program de setting et un de destruction afin de libérer plus facilement la mémoire.

**Publication sur github**

> Après trois mois de dévelopement sur la mise en place du premier system de base pour la création du jeu je le passe sur github afin d'avoir une trace du projet ainsi que pouvoir avancer plus régulièrement sur le projet personnel. Dans cette optique je fais faire une refonte de mon README, améliorer le system de log, finaliser le system de scene qui est un outils critique pour la poursuite du projet.
> 
> `Date de publication sur le repo github : 23/12/2025 2:43`

**Status du projet**

Aucune étape significative ont été réaliser. Toutefois le projet avance. Continuons sur la lancer et limitons les erreurs de warning afin de poursuivre correctement le projet. ^^
