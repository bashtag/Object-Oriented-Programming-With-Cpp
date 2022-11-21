all: clean clear compile run

compile: main.o Tetromino.o Tetris.o
	@echo "------------------------------------------"
	@echo "Compiling..."
	@g++ main.o Tetromino.o Tetris.o -lm -o main.out

main.o:
	@g++ -std=c++11 -c main.cpp -o main.o

Tetromino.o: Tetromino.hpp
	@g++ -std=c++11 -c Tetromino.cpp -o Tetromino.o

Tetris.o: Tetris.hpp
	@g++ -std=c++11 -c Tetris.cpp -o Tetris.o

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