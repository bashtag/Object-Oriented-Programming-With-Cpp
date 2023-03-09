all: d1_all d2_all

d1_all: clean clear d1_compile d1_run

d2_all: clean clear d2_compile d2_run

d2_compile:
	@echo "------------------------------------------"
	@echo "Compiling..."
	@javac driver2.java

d1_compile:
	@echo "------------------------------------------"
	@echo "Compiling..."
	@javac driver1.java

d1_run:
	@echo "------------------------------------------"
	@echo "Running..."
	@echo "=========================================="
	java driver1
	@echo "=========================================="
	@echo "Completed..."

d2_run:
	@echo "------------------------------------------"
	@echo "Running..."
	@echo "=========================================="
	java driver2
	@echo "=========================================="
	@echo "Completed..."

clean:
	@echo "------------------------------------------"
	@echo "Removing Compield Files..."
	@rm -f *.class

clear:
	@clear