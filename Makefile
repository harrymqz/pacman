make: game.cpp
	g++ game.cpp Cell.cpp Maze.cpp -o game -std=c++11 -lglut -lGLU -lGL -lm 
clean:
	rm game
