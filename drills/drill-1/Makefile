all: clean clear compile run

compile: main.o MyVector.o
	@echo "------------------------------------------"
	@echo "Compiling..."
	@g++ main.o MyVector.o -lm -o main.out

main.o:
	@g++ -std=c++11 -c main.cpp -o main.o

MyVector.o: MyVector.hpp
	@g++ -std=c++11 -c MyVector.cpp -o MyVector.o

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