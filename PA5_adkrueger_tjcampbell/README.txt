-- Ants & Doodlebugs -- 
HW Assigment #4
by Aaron Krueger and Theo Campbell

The purpose of this program is to run a 2D game of Ants and Doodlebugs, where 
the doodlebugs are responsible for eating the ants and the ants can attempt to
outlive the doodlebugs.

#Doodlebug#
Doodlebug has four main methods: move, breed, starve, and step. It also has 
member variables that represent its grid, current row, current column, and 
countdowns for when it breeds and starves. Doodlebug inherits from Organism.
Move - responsible for causing the Doodlebug to make movements through the 
board, which are determined randomly between possible adjacent empty spaces, or
adjacent spaces that contain ants. This is done by switching the values of the
current doodlebug with that of the empty space, or "eating" the ant and taking
its place. If the doodlebug can't move, it will simply wait in the same spot. 
Breed - the Doodlebug will search for adjacent empty spaces. If any are 
available, the doodlebug will create another doodlebug in the empty space. 
Otherwise, it will wait to breed. This function only runs if the doodlebug 
didn't starve during the round.
Step - simply calls the move, starve, and breed functions (in that order). If
the doodlebug doesn't starve, it will breed.
Starve - checks whether the doodlebug will starve in the current round by 
looking at its starvation counter, then deleting it if it has starved.
 
#Ant#
Ant has three main methods: move, breed, and step. It also has member variables
that represent its grid, current row, current column, and countdown til it
breeds. Ant inherits from Organism.
Move - responsible for causing the Ant to make movements through the board, 
which are determined randomly between possible adjacent empty spaces. This is
done by switching the values of the current ant with that of the empty space. 
If the ant can't move, it will simply wait in the same spot. 
Breed - similar to the move function, as the Ant will initially search for 
empty spaces. Afterwards, the ant will create another ant in one of the spaces
(randomly decided from the bunch). This function only operates if the ant
has gone three moves without breeding or dying. If the ant can't breed, it will
wait until the next turn to do so.
Step - simply calls the move and breed methods in that order

#Organism#
Organism has several helpful methods. It is the parent class to both Ant and
Doodlebug.
isPrey - returns true if the Organism is an ant, or false if the Organism is
a Doodlebug. The value used is also true if the space refers to a nullptr
setAmAnt - sets the value of amAnt to true or false
isEmpty - returns true if the Organism in the grid is a nullptr, false if
it is an actual organism
canMoveHere - checks if the spaces to the north, south, east, or west is 
available, depending on input
doodleCanMoveHere - the same as canMoveHere, but also returns true if the 
space contains an Ant

#Grid#
The grid that contains pointers to all Organisms, and if not, contains a 
nullptr in empty spaces. The default size of the grid is 20.
setCellOccupant - sets the given coordinates to a certain organism*
getCellOccupant - returns the organism in the given coordinates
step - causes each organism to take a step, ignoring nullptrs
getLetter - returns a letter corresponding to whatever organism is in the 
given position. Blank space if nullptr, o if ant, and x if doodlebug
printGrid - prints out each organism of the array, using getLetter