all: clean clear compile run

compile: main.cpp lib.h lib.cpp
	@echo "-------------------------------------------------"
	@echo "Compiling..."
	@g++ -std=c++11 -c lib.cpp -o lib.o
	@g++ -std=c++11 -c main.cpp -o main.o
	@g++ main.o lib.o -lm -o main.out

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