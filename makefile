LIB=-lSDL2 -lSDL2_image
SRC= $(wildcard src/*.cpp)
OBJ= $(SRC:.cpp=.o)
CPLUS_INCLUDE_PATH= "include"
all: $(OBJ) main.o
	g++  -o Programme  $(LIB) main.o $(OBJ) 


main.o:main.cpp
	g++ -c main.cpp -I include -o main.o
src/%.o:src/%.cpp 
	g++ -c $^ -I include -I /usr/include -o $@ 

mrproper: 
	rm -rf src/*.o all


       	
