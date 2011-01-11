SOURCES =	main.cpp sdlglutils.cpp slope.c skiman.cpp
OBJECTS	=	$(SOURCES:.cpp=.o)
TARGET	=	ski
LIBS	=	$(shell sdl-config --libs) -lGL -lGLU  -lSDL_image

all: $(OBJECTS)
	g++ $(LIBS) -o $(TARGET) $(OBJECTS)

%o: %cpp
	g++ -o $@ -c $<

x: all
	./$(TARGET)

clean:
	rm -rf $(OBJECTS)

superclean : clean
	rm -rf $(TARGET)
