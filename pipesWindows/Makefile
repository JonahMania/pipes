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

INCLUDES = -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib 

RM = rm -f
all: $(SRC) 
		g++ $(SRC) $(INCLUDES) -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o $(NAME)

clean:
		-$(RM) source/*.o
		-$(RM) source/*.core
