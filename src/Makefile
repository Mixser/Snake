GLEW_PATH=/usr/local/Cellar/glew/2.0.0/
CFLAGS=-c -Wall -Wno-deprecated

FRAMEWORKS=-framework OpenGL -framework GLUT

INCLUDES=-I$(GLEW_PATH)include
APPNAME=snake

all: project clean

project: build_all
	g++ $(FRAMEWORKS) *.o  -o ../build/$(APPNAME)


build_all: util.o main.o GlutBackend.o  GameEngine.o GameBase.o Snake.o Apple.o

util.o:  util.cpp
	g++ $(CFLAGS) util.cpp

GameBase.o: GameBase.cpp 
	g++ $(CFLAGS) GameBase.cpp $(INCLUDES)

GlutBackend.o: GlutBackend.cpp
	g++ $(CFLAGS) GlutBackend.cpp $(INCLUDES)

GameEngine.o: GameEngine.cpp
	g++ $(CFLAGS) GameEngine.cpp $(INCLUDES)

Snake.o: Snake.cpp
	g++ $(CFLAGS) Snake.cpp $(INCLUDES)
Apple.o: Apple.cpp
	g++ $(CFLAGS) Apple.cpp $(INCLUDES)

main.o: main.cpp
	g++ $(CFLAGS) main.cpp $(INCLUDES)

clean:
	rm -rf *.o