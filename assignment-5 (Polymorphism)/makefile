all: d1_all d2_all

d1_all: clean clear d1_compile d1_run

d2_all: clean clear d2_compile d2_run

d2_compile: driver2.o Tetromino.o TetrisVector.o AbstractTetris.o TetrisArray1D.o
	@echo "------------------------------------------"
	@echo "Compiling..."
	@g++ -g driver2.o Tetromino.o TetrisVector.o AbstractTetris.o TetrisArray1D.o -lm -o driver2.out

d1_compile: driver1.o Tetromino.o TetrisVector.o AbstractTetris.o TetrisArray1D.o
	@echo "------------------------------------------"
	@echo "Compiling..."
	@g++ -g driver1.o Tetromino.o TetrisVector.o AbstractTetris.o TetrisArray1D.o -lm -o driver1.out

driver1.o:
	@g++ -g -std=c++11 -c driver1.cpp -o driver1.o

driver2.o:
	@g++ -g -std=c++11 -c driver2.cpp -o driver2.o

Tetromino.o: Tetromino.hpp
	@g++ -g -std=c++11 -c Tetromino.cpp -o Tetromino.o

TetrisVector.o: TetrisVector.hpp
	@g++ -g -std=c++11 -c TetrisVector.cpp -o TetrisVector.o

AbstractTetris.o: AbstractTetris.hpp
	@g++ -g -std=c++11 -c AbstractTetris.cpp -o AbstractTetris.o

TetrisArray1D.o: TetrisArray1D.hpp
	@g++ -g -std=c++11 -c TetrisArray1D.cpp -o TetrisArray1D.o


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