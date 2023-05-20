# Rush Hour Game
Rush Hour is a one-player game where the player takes on the role of a taxi driver who must collect money by dropping passengers to their destinations. This project involves developing a Rush Hour game with various features. The game is implemented in C++ and utilizes concepts such as functions, pointers, dynamic memory allocation, and file handling.

## Game Features

### Game Start Menu
Upon starting the game, the player is presented with a menu that provides the option to view the leaderboard. The leaderboard displays the top 10 scores along with player names. The leaderboard data is read from the "highscores.txt" file and stored in an array of size 10. If the current game score makes it to the leaderboard, the lowest score is removed, and the updated scores overwrite the file.
The player can choose to play the game using a yellow taxi or a red taxi. There is an option to assign the taxi color randomly or allow the player to select the color.
The player is prompted to enter their name after selecting a taxi.

### The Board
The game board is a 20x20 grid displayed on the screen. The board consists of roads (displayed in white) and buildings (displayed in black).
The player's taxi, along with other cars, obstacles, and passengers, is placed randomly on the board at the start of the game.
The board always has a minimum of 3 and a maximum of 5 passengers waiting to be picked up. Passengers can be located anywhere on the board except where other cars or obstacles are present.

### Game Play
The player's taxi can move in all four directions (up, down, right, and left) using the arrow keys.
The taxi needs to navigate through obstacles and other cars to pick up passengers. Once the taxi is adjacent to a passenger, the player can press the Spacebar to pick them up.
Each passenger has a desired destination on the board, which is highlighted in green once they are picked up. The taxi must take the passenger to their desired location as quickly as possible.
The desired destination for each passenger is randomly generated on the board and cannot be the same as their pickup location. The destination cannot be occupied by an obstacle.
Once the taxi picks up a passenger, they can only be dropped at their desired destination.
The player earns 10 points each time the taxi picks up and drops off a passenger successfully.
Overtaking another car on the board earns the player an extra point for each overtake.

### Negative Points
There are negative points associated with hitting people or obstacles. The number of points deducted depends on the type of taxi and the object hit.
**Red Taxi**: Hits an obstacle (tree or box) -2 points
**Red Taxi**: Hits another car -3 points
**Yellow Taxi**: Hits an obstacle (tree or box) -4 points
**Yellow Taxi**: Hits another car -2 points

### Other Features
Cars other than the taxi cannot be red or yellow.
All other cars on the board are also moving and can move up, down, right, and left. They cannot stop anywhere during the game.
Every time the taxi successfully drops off two passengers, the number of cars on the board increases by 1.
Every time the taxi successfully drops off two passengers, the speed of the cars on the board increases.
The yellow taxi is faster than the red taxi.

### Winning Criteria
The game has a total running time of 3 minutes.
If the player scores 100 points or more within the 3-minute time limit, they win the game.

### Graphics
Passengers are represented by stick figures, and cars are represented by rectangles with two circles.
The game provides an option for the taxi to be driven in AUTO mode. In AUTO mode, the game finds the shortest path from the pickup location to the passenger's destination and automatically maneuvers the taxi to that location while avoiding obstacles and collisions with other cars.

### Bonus Features
Additional bonus features can be implemented to earn extra marks. These features should be discussed with the teacher to determine their eligibility for bonus marks.
A new board is generated every time a new game is started. However, every corner of the board must be reachable. The board should consist of 35% buildings and 65% roads.

## How to Run the Game
1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/awahab111/RushHourDriver.git
   ```

2. Navigate to the project directory:

   ```bash
   cd RushHourDriver
   ```

3. Install the relevant libraries:

   ```bash
   sudo apt-get install make freeglut3-dev glew-utils libglew1.6-dev libfreeimage-dev
   ```

4. Run the program:

   ```bash
   make 
   ./game
   ```

## Project Requirements
The project is implemented in C++.
Concepts such as functions, pointers, dynamic memory allocation, and file handling are utilized.
The game incorporates the specified features, including the game start menu, game board, gameplay mechanics, scoring, and winning criteria.
Graphics are implemented using basic shapes and symbols.

## Conclusion
This Rush Hour game project aims to provide an engaging and challenging gaming experience for players. By implementing the specified features and incorporating programming concepts, the project allows players to navigate a taxi through a dynamic game board, picking up and dropping off passengers while avoiding obstacles and other cars. The scoring system, leaderboard, and time limit add a competitive element to the game, providing players with a goal to achieve within the given time frame.
