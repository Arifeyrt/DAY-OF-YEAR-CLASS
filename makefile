all: compile run

compile:  test.cpp dayofyear.h dayofyear.cpp
	@echo "-------------------------------------------"
	@echo "Compiling.."
	@g++  test.cpp  dayofyear.cpp  -o test
	

run:
	
	@echo "Running the tests.."
	./test>>text.txt
	@echo "Printed to file."
	
