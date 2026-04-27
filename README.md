# cub3D - My first RayCaster with miniLibX

*Ce projet a été réalisé dans le cadre du cursus 42 par mida.*

---
### Description
cub3D is a technical project inspired by the world-famous Wolfenstein 3D, the first "First Person Shooter" in history. The objective is to develop a dynamic 3D graphical view inside a maze using the ray-casting technique.

### Features
The program implements the following functionalities:
- **3D Rendering**: Real-time graphical display using the ray-casting algorithm.
- **Interactivity**: Smooth movement (forward, backward, left, right) and camera rotation using keyboard and mouse events.
- **Map Parsing**: Rigorous parsing of `.cub` configuration files, including textures, colors, and map validation (closed walls, player position).
- **Graphical Management**: Use of the miniLibX library for window management, image rendering, and event handling.
- **Signal Handling**: Clean exit on window closure or pressing the ESC key.

### Technical Requirements
- Language: C.
- Compliance with the 42 Norm.
- Strict memory management: Absence of memory leaks and unexpected crashes.
- Optimization of ray-casting calculations to ensure a fluid user experience.

### Instructions
To compile the project, use the provided Makefile:
make

To run the program:
./cub3D maps/example.cub

### Resources and AI Usage
This project involved a deep study of trigonometric functions and the MiniLibX graphical library. In accordance with 42 curriculum guidelines, AI tools were utilized for algorithmic optimization and generating specific test cases for map parsing. All AI suggestions were reviewed, manually tested, and integrated to ensure full technical understanding of the engine.

********************************************************************************

### Description
cub3D est un projet technique inspiré par Wolfenstein 3D, considéré comme le premier "First Person Shooter" de l'histoire. L'objectif est de développer une vue graphique 3D dynamique à l'intérieur d'un labyrinthe en utilisant la technique du ray-casting.

### Fonctionnalités
Le programme implémente les fonctionnalités suivantes :
- **Rendu 3D** : Affichage graphique en temps réel basé sur l'algorithme de ray-casting.
- **Interactivité** : Déplacements fluides (avant, arrière, gauche, droite) et rotation de la caméra via les événements clavier et souris.
- **Parsing de Carte** : Analyse rigoureuse des fichiers de configuration `.cub`, incluant les textures, les couleurs et la validation de la structure de la carte.
- **Gestion Graphique** : Utilisation de la bibliothèque miniLibX pour la gestion des fenêtres, le rendu d'images et le traitement des événements.
- **Gestion des Signaux** : Fermeture propre du programme via la croix de la fenêtre ou la touche ESC.

### Exigences Techniques
- Langage : C.
- Respect de la Norme 42.
- Gestion stricte de la mémoire : Absence de fuites mémoire et de crashs inattendus.
- Optimisation des calculs de ray-casting pour garantir une expérience fluide.

### Instructions
Pour compiler le projet, utilisez le Makefile fourni :
make

Pour lancer le programme :
./cub3D maps/example.cub

### Ressources et Utilisation de l'IA
Ce projet a nécessité une étude approfondie des fonctions trigonométriques et de la bibliothèque graphique miniLibX. Conformément aux directives du cursus 42, des outils d'IA ont été utilisés pour l'optimisation algorithmique et la génération de tests spécifiques pour le parsing de cartes. Chaque suggestion a été revue, testée manuellement et intégrée afin de garantir une compréhension technique totale du moteur.
