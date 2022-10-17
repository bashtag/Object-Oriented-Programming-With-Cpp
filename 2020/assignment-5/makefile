all: clean clear compile run

compile: main.o BoardGame2D.o EightPuzzle.o Klotski.o PegSolitaire.o
	@echo "-------------------------------------------------"
	@echo "Compiling..."
	@g++ main.o BoardGame2D.o EightPuzzle.o Klotski.o PegSolitaire.o -lm -o main.out

main.o:
	@g++ -std=c++11 -c main.cpp -o main.o

BoardGame2D.o:
	@g++ -std=c++11 -c BoardGame2D.cpp -o BoardGame2D.o

EightPuzzle.o:
	@g++ -std=c++11 -c EightPuzzle.cpp -o EightPuzzle.o

Klotski.o:
	@g++ -std=c++11 -c Klotski.cpp -o Klotski.o

PegSolitaire.o:
	@g++ -std=c++11 -c PegSolitaire.cpp -o PegSolitaire.o

run:
	@echo "-------------------------------------------------"
	@echo "Running..."
	@echo "========================================================================="
	./main.out
	@echo "========================================================================="
	@echo "Completed."

clear:
	@clear

clean:
	@echo "-------------------------------------------------"
	@echo "Removing Compiled Files..."
	@rm -f *.out
	@rm -f *.o

clean_txt: clean
	@rm -f *.txt