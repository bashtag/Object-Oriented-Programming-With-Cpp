all: d1_all d2_all

d1_all: clean clear d1_compile d1_run

d2_all: clean clear d2_compile d2_run

d2_compile: driver2.o Tetromino.o Tetris.o
	@echo "------------------------------------------"
	@echo "Compiling..."
	@g++ driver2.o Tetromino.o Tetris.o -lm -o driver2.out

d1_compile: driver1.o Tetromino.o Tetris.o
	@echo "------------------------------------------"
	@echo "Compiling..."
	@g++ driver1.o Tetromino.o Tetris.o -lm -o driver1.out

driver1.o:
	@g++ -std=c++11 -c driver1.cpp -o driver1.o

driver2.o:
	@g++ -std=c++11 -c driver2.cpp -o driver2.o

Tetromino.o: Tetromino.hpp
	@g++ -std=c++11 -c Tetromino.cpp -o Tetromino.o

Tetris.o: Tetris.hpp
	@g++ -std=c++11 -c Tetris.cpp -o Tetris.o

d1_run:
	@echo "------------------------------------------"
	@echo "Running..."
	@echo "=========================================="
	./driver1.out
	@echo "=========================================="
	@echo "Completed..."

d2_run:
	@echo "------------------------------------------"
	@echo "Running..."
	@echo "=========================================="
	./driver2.out
	@echo "=========================================="
	@echo "Completed..."

clean:
	@echo "------------------------------------------"
	@echo "Removing Compield Files..."
	@rm -f *.out
	@rm -f *.o

clear:
	@clear