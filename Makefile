solver: main.o solver.o
	g++ -o solver main.o solver.o
main.o: main.cpp solver.h
	g++ -c -Wall -pedantic -g -std=c++11 main.cpp
solver.o: solver.cpp solver.h
	g++ -c -Wall -pedantic -g -std=c++11 solver.cpp
clean:
	rm *.o solver
