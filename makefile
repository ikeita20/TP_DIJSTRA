all: executable.out

executable.out : main.o grille.o

	g++ main.o grille.o -o executable.out


main.o : main.cpp grille.h

	g++ -Wall -c main.cpp


grille.o : grille.cpp grille.h

	g++ -Wall -c grille.cpp


clean :
	rm *.o

veryclean : clean 
	rm *.out

