
all: test_velverlet test_kinerg test_force
	./test_velverlet
	./test_kinerg
	./test_force

test_velverlet: test_velverlet.o
	gcc $^ ljmd-serial.so -o $@

test_force: test_force.o
	gcc $^ ljmd-serial.so -o $@

test_kinerg: test_kinerg.o
	gcc $^ ljmd-serial.so -o $@

%.o: %.c
	gcc -c $< -I../include

clean:
	rm -rf test_force test_velverlet test_kinerg *.o *.so
