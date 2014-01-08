all: project


project: util.o GlutBackend.o  GameEngine.o GameBase.o main.o Snake.o Apple.o
	g++  main.o util.o GameBase.o GlutBackend.o GameEngine.o Snake.o Apple.o  -o ../build/project -lGL -lGLU -lglut -lGLEW
	


util.o: util.cpp
	g++ -c util.cpp

GameBase.o: GameBase.cpp 
	g++ -c GameBase.cpp


GlutBackend.o: GlutBackend.cpp
	g++ -c GlutBackend.cpp

GameEngine.o: GameEngine.cpp
	g++ -c GameEngine.cpp

Snake.o: Snake.cpp
	g++ -c Snake.cpp
Apple.o: Apple.cpp
	g++ -c Apple.cpp

main.o: main.cpp
	g++ -c main.cpp 

clean:
	rm -rf *.o project