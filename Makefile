all:
	clear
	clang++ -std=c++11 *.cpp -lGL -lGLU -lglut

extra: 
	clear
	clang++ -std=c++11 -Wall -Wextra -pedantic *.cpp -lGL -lGLU -lglut

