NAME = pipes
SRC = source/tinyxml2.cpp\
      source/main.cpp\
	  source/initialize.cpp\
	  source/input.cpp\
      source/pipe.cpp\
	  source/texture.cpp\
	  source/map.cpp\
	  source/game.cpp\
	  source/connect.cpp\
	  source/timer.cpp\
	  source/button.cpp\
	  source/renderAll.cpp\
	  source/update.cpp\
	  source/runInput.cpp\
	  source/menu.cpp\

OBJ = $(SRC:.cpp=.o)
RM = rm -f
all: $(OBJ) 
		g++ $(OBJ) -lSDL2 -lSDL2_image -o $(NAME)

clean:
		-$(RM) source/*.o
		-$(RM) source/*.core

