# -*- Makefile -*-
SHELL=/bin/sh
CC=gcc
CFLAGS=-Wall -g -O3 -ffast-math -fomit-frame-pointer
CFLAGS1=-Wall -pg -O3 -ffast-math -fomit-frame-pointer
LDLIBS=-lm
INCLUDE = include
SRCDIR = src
OBJDIR = objects

CFLAGS += -I$(INCLUDE)
# list of source files
SRC=$(wildcard $(SRCDIR)/*.c)
DEPS=$(wildcard $(INCLUDE)/*.h) 
OBJ=$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

default: ljmd-serial.x
	mv ./ljmd-serial.x bin 

ljmd-perf: $(OBJ) 
	$(CC) -o $@ $(CFLAGS1) $^ $(LDLIBS)


clean:
	rm -f *.mod objects/*.o ljmd-serial.x

# linker rule
ljmd-serial.x: $(OBJ) 
	$(CC) -o $@ $(CFLAGS) $^ $(LDLIBS)

# compilation pattern rule for objects
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c $(CFLAGS) $< -o $@

