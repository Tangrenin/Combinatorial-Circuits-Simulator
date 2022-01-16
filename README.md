# Combinatorial-Circuits-Simulator
## Master's c++ project

Simulation of combinatorial circuits in console application.

Example of such display : 
```
E = nor(d,xor(c,or(a,b)))
a:1 b:0
 |   |
 ** **
   |
  OR_     c:0
   |       |
   **** ****
       |
      XOR         d:1
       |           |
       ****** ******
             |
            NOR
             |
             E

Ouput value :  0

```

## Instructions: 
### Installation and running 
1. Clone the project 
2. Run the command `make test` or use cmake to run the project

### Usage 
The main.cpp file provides guided tests to demonstrate the circuits simulations.
If you want to tinker with it yourself :

#### Building a circuit

A circuit can be built in 3 different ways : 
1. Call the `OutputGate` constructor and provide it with a textual expression of the logical formula the circuit is supposed to simulate. ( Such as "E = nor(d,xor(c,or(a,b)))" )
2. Call the `OutputGate` constructor and provide it with a path to a text file where a circuit has been saved. (see _Saving a Circuit_ section)
3. Create some input variables with the class `InputGate` (feeding its constructor a simple character for the name, and eventually a truth value).
Then create successive Gates feeding them with either an InputGate or another Gate. In the end, call the `OutputGate` constructor with the last Gate you created as argument.

#### Displaying a circuit
Your interface with a circuit through its `OutputGate` object and using its methods :
- _*showOutput :*_ prints the truth value at the output of the circuit.
- _*outputToText :*_ Graphical display of the circuit in console.

#### Saving a circuit
You can save a circuit in a text file and rebuilt it from that file later using the following method :
- _*saveInFile :*_ saves the circuit in the _saved-circuits_ folder, using the circuit name to generate the filename.



## Instructions en français :
### Installation et execution
1. Cloner le projet
2. Exécutez la commande `make test` ou utilisez cmake pour lancer le projet.

### Utilisation
Le fichier main.cpp fournit des tests guidés pour démontrer le fonctionnement des simulations de circuits.
Si vous voulez bricoler par vous-même :

#### Construction un circuit
Un circuit peut être construit de 3 façons différentes :
1. Appelez le constructeur `OutputGate` et fournissez-lui une expression textuelle de la formule logique que le circuit est sensé simuler. (Par exemple, "E = nor(d,xor(c,or(a,b))").
2. Appelez le constructeur `OutputGate` et fournissez-lui un chemin vers un fichier texte où un circuit a été sauvegardé. (voir la section _Sauvegarde d'un circuit_)
3. Créez des variables booléennes d'entrée avec la classe `InputGate` (en fournissant à son constructeur un simple caractère pour le nom, et éventuellement une valeur de vérité).
   Ensuite, créez des portes successives en les alimentant soit avec une InputGate, soit avec une autre porte. Enfin, appelez le constructeur `OutputGate` avec la dernière Gate que vous avez créée comme argument.

#### Affichage d'un circuit
Vous interagissez avec un circuit à travers un objet `OutputGate`, en utilisant ses méthodes :
- _*showOutput :*_ Affiche la valeur de vérité en sortie du circuit.
- _*outputToText :*_ Affichage graphique du circuit en console.

#### Sauvegarder un circuit
Vous pouvez enregistrer un circuit dans un fichier texte et le reconstruire ultérieurement à partir de ce fichier en utilisant la méthode suivante :
- _*saveInFile :*_ enregistre le circuit dans le dossier _saved-circuits_, en utilisant le nom du circuit pour générer le nom du fichier.
