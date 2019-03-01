-- Ants & Doodlebugs -- 
HW Assignment #4
by Aaron Krueger and Theo Campbell

The purpose of this program is to run a 2D game of Ants and Doodlebugs, where 
the doodlebugs are responsible for eating the ants and the ants can attempt to
outlive the doodlebugs.

To run the program, place arguments on the command line in the following order:
(Dimensions of Grid) (Number of Doodlebugs) (Number of Ants) (Number of 
Time Steps) (Seed value) (Pause)
The dimensions of the grid are n x n
The number of doodlebugs will be the number of doodlebugs in the grid
The number of ants will be the number of ants in the grid. Do not include more
organisms than there are spaces on the grid
The number of time steps is the number of steps the program should take
The seed value is the value of the random number generator. Input a 0 if you 
would like to use the current time as a seed
The pause value will cause the grid to print and pause every (n % pause) steps

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

#Production#
Runs the program using argc and argv[]
production - the constructor that obtains the input values
runProduction - causes each organism to step through the program, going
row by column. Prints out original command line and other values 
pertaining to the program

Test output is pasted below:
Running the grid test
                    
                    
   o                
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
(The default grid of size 20, which is completely empty except for an Ant)
GridTest() Passed

Running the make ants test
The grid before an Ant is added
   
   
   
The grid after an Ant is added
   
  o
   
makeAntsTest() Passed

Running the move ants test
The grid before the Ant moves
  
 o
The grid after the Ant moves
  
o 
antsMoveTest() Passed

Running the breed ants test
The grid before the Ant breeds
   
 o 
   
The grid after the Ant breeds
   
 o 
 o 
antsBreedTest() Passed

Running the ants die test
The grid before the Ant dies
   
 o 
   
The grid after the Ant dies
   
   
   
antsDieTest() Passed

Running the make doodlebugs test
The grid before the Doodlebug is constructed
   
   
   
The grid after the Doodlebug is constructed
x  
   
   
makeDoodlesTest() Passed

Running the move doodlebugs test
The grid before the Doodlebug moves
  
 x
The grid after the Doodlebug moves
  
x 
doodleMoveTest() Passed

Running the breed doodlebugs test
The grid before the Doodlebug attempts to breed
   
 x 
   
The grid after the Doodlebug attempts to breed
   
 xx
   
doodleBreedTest() Passed

Running the doodle eats ant test
The grid before the Ant gets eaten
 o
ox
The grid after the Ant gets eaten (and one of the ants moves)
o 
x 
doodleEatTest() Passed

Running the doodlebug dies test
The grid before the Doodlebug dies
   
 x 
   
The grid after the Doodlebug dies
   
   
   
doodleDieTest() Passed

Running the ants don't move test
The grid before the Ant attempts to move
 oo
ooo
ooo
The grid after the Ant attempts to move (the exact same)
 oo
ooo
ooo
antsDontMoveTest() Passed

Running the ants don't breed test
The grid before the Ant attempts to breed
 oo
ooo
ooo
The grid after the Ant attempts to breed (the exact same)
 oo
ooo
ooo
antsDontBreedTest() Passed

Running the doodles don't move test
The grid before the Doodlebug attempts to move
 x 
xxx
 x 
The grid after the Doodlebug attempts to move (the exact same)
 x 
xxx
 x 
doodleDontMoveTest() Passed

Running the doodle don't breed test
The grid before the Doodlebug attempts to breed
 xx
xxx
xxx
The grid after the Doodlebug attempts to breed (the exact same)
 xx
xxx
xxx
doodleDontBreedTest() Passed

The only code not written by us was the prototypes for certain methods and 
their declarations