all: clean clear compile run

compile: main.cpp EightPuzzle.cpp EightPuzzle.h BoardGame2D.cpp BoardGame2D.h
	@echo "-------------------------------------------------"
	@echo "Compiling..."
	@g++ -std=c++11 -c main.cpp -o main.o
	@g++ -std=c++11 -c EightPuzzle.cpp -o EightPuzzle.o
	@g++ -std=c++11 -c BoardGame2D.cpp -o BoardGame2D.o
	@g++ main.o BoardGame2D.o EightPuzzle.o -lm -o main.out

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