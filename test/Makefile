
all: test_velverlet.x test_kinerg.x test_force.x test_input.x 
	./test_velverlet.x
	./test_kinerg.x
	./test_force.x
	./test_input.x < argon_108.inp

test_velverlet.x: test_velverlet.o
	gcc $^ ljmd-serial.so -o $@

test_force.x: test_force.o
	gcc $^ ljmd-serial.so -o $@

test_kinerg.x: test_kinerg.o
	gcc $^ ljmd-serial.so -o $@

test_input.x: test_input.o
	gcc $^ ljmd-serial.so -o $@

%.o: %.c
	gcc -c $< -I../include

clean:
	rm -rf *.x *.o *.so
