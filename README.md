# Lem_in
This **algorithmic** project is about finding the most efficient way to allow ants to reach the end of a labyrinth.  
First, just clone this project and use the command **`make`** in order to build the binary then lauch it.
Then, the user must enter a map :

## Map entry (Input)

* define rooms like : **`name coordx coordy`**. (no `-` in rooms name)
* define connections like : **`name1 name2`**.
* use **`##START`** and **`##END`** before the line defining the starting or ending room.
* You can enter comments, they must follow a `#`

## Output

For each line written, it represents one turn of action.
The syntax is the following :  
**`Lx-y`** with x the id of the ant qnd y his location (room's name)
