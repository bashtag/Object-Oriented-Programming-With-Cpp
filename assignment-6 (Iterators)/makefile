all: clean clear compile run

compile: driver.o
	@echo "------------------------------------------"
	@echo "Compiling..."
	@g++ -g driver.o -lm -o driver.out

driver.o:
	@g++ -g -std=c++11 -c driver.cpp -o driver.o

run:
	@echo "------------------------------------------"
	@echo "Running..."
	@echo "=========================================="
	./driver.out
	@echo "=========================================="
	@echo "Completed..."

clean:
	@echo "------------------------------------------"
	@echo "Removing Compield Files..."
	@rm -f *.out
	@rm -f *.o

clear:
	@clear