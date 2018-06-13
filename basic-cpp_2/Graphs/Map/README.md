# English

### Description

A road map is defined as a group of cities and highways. It can be represented by a directed graph where the vertices represent the cities and the edges are the one-way highways.

### Find out:

1. Which city is the most overcrowded (based on the maximum number of freeways entering the city).
2. Check if the card is valid (we consider that the card is valid if we have at least one path between 2 cities. Obs: a one way way between 2 cities is enough!);
3. For a specific city, determine which cities are "inaccessible" (two cities are said to be inaccessible to each other if we do not have a two-way road between them)
4. Determine which is the nearest service station where a car can stop (based on gas consumption, initial gas quantity and initial position).

### Input 

7 8 (number of cities, number of highways)

Boston Chicago LasVegas LosAngeles NewYork Washington Wisconsin (liste of cities)

NewYork LasVegas (pairs of cities linked by a highway)

LosAngeles NewYork

Washington NewYork

LasVegas Washington

Washington LosAngeles

Boston Chicago

Chicago Wisconsin

Wisconsin Boston



2 (number of gas stations)

LasVegas Chicago (names of gas stations)

2 (number of cars)

LosAngeles 7 3 (car 1 – initial position, initial gas quantity, 
consumption)

Wisconsin 5 3 (car 2 – initial position, initial gas quantity, 
consumption)


# French

### Description

On définit une carte routière comme un groupe de villes et d'autoroutes entre elles. On peut la représenter par un graphe orienté où les sommets représentent les villes et les arêtes sont les autoroutes à sens unique.

### Trouver:

1. Quelle ville est la plus surpeuplée (en fonction du nombre maximum d'autoroutes qui entrent
dans cette ville).
2. Vérifier si la carte est valide (nous considérons que la carte est valide si nous avons au moins un chemin entre 2 villes. 
Obs: un chemin à sens unique entre 2 villes est suffisant!) ;
3. Pour une ville spécifique, déterminer quelles villes sont dites «inaccessibles» (deux villes sont dites inaccessibles l'une à l'autre si nous n'avons pas de route à double sens entre elles)
4. Déterminer quelle est la station-service la plus proche où une voiture peut s'arrêter (compte tenu de sa consommation de gaz, de la quantité initiale de gaz et de sa position initiale).


### Input 

7 8 (nombre villes, nombre autoroutes)

Boston Chicago LasVegas LosAngeles NewYork Washington Wisconsin (liste villes)

NewYork LasVegas (paires villes liées par une autoroute)

LosAngeles NewYork

Washington NewYork

LasVegas Washington

Washington LosAngeles

Boston Chicago

Chicago Wisconsin

Wisconsin Boston


2 (nombre stations-service)

LasVegas Chicago (noms stations-service)

2 (nombre voitures)

LosAngeles 7 3 (voiture 1 – position initiale, quantité initiale gaz, 
consommation)

Wisconsin 5 3 (voiture 2 – position initiale, quantité initiale gaz, 
consommation)