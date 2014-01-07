all: project


project: util.o GlutBackend.o GameBase.o main.o
	g++  main.o util.o GameBase.o GlutBackend.o   -o ../build/project -lGL -lGLU -lglut -lGLEW
	


util.o: util.cpp
	g++ -c util.cpp

GameBase.o: GameBase.cpp
	g++ -c GameBase.cpp


GlutBackend.o: GlutBackend.cpp
	g++ -c GlutBackend.cpp

main.o: main.cpp
	g++ -c main.cpp 

clean:
	rm -rf *.o project