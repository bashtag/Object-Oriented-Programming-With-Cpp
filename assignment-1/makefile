all: clean clear compile run

compile: main.o Tetromino.o Termino.hpp
	@echo "------------------------------------------"
	@echo "Compiling..."
	@g++ main.o Tetromino.o -o main.out

main.o:
	@g++ -std=c++11 -c main.c -o main.out

Tetromino.o: Tetromino.hpp
	@g++ -std=c++11 -c Tetromino.cpp -o Tetromino.o

run:
	@echo "------------------------------------------"
	@echo "Running..."
	@echo "=========================================="
	./main.out
	@echo "=========================================="
	@echo "Completed..."

clean:
	@echo "------------------------------------------"
	@echo "Removing Compield Files..."
	@rm -f *.out
	@rm -f *.o

clear:
	@clear