# Test makefile

all: create_build_dir ./build/test_cb 

OBJ = ./build/cb.o ./build/test_cb.o

create_build_dir: 
	@ mkdir build

./build/test_cb: $(OBJ)
	@ gcc -o $@ $(OBJ)
	@ ./build/test_cb
	
./build/test_cb.o: ./test/test_cb.c 
	@ gcc -o $@ $< -c -W -Wall -pedantic -Itest/tinytest/ -Iinc/

./build/cb.o: ./src/cb.c ./inc/cb.h
	@ gcc -o $@ $< -c -W -Wall -ansi -pedantic -Iinc/

clean:
	@ rm -Rf build