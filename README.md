# Lem_in
This **algorithmic** project is about finding the most efficient way to allow ants to reach the end of a labyrinth (the less turns possible).  
First, just clone this project and use the command **`make`** in order to build the binary then lauch it : **`./lem-in`**..
After that, you must enter the number of ants.
Then, you must enter a map :

### Map entry (Input)

take care : if your input is wrong, the programm will be executed, even if there are missing informations.
* define rooms like : **`name coordx coordy`**. (no `-` in rooms name)
* define connections like : **`name1-name2`**.
* use **`##START`** and **`##END`** before the line defining the starting or ending room.
* You can enter comments, they must follow a `#`

### Rules

* One room cannot contain more than 1 ant, except the starting and ending ones.
* All ants are in the starting room at the beginning.
* At each turn, the programm can move an ant only once through a connection.
* the room the ant is going on must be empty.

### Output

For each line written, it represents one turn.
The syntax is the following :  
**`Lx-y`** with x the id of the ant and y his location (room's name)
