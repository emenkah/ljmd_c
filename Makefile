# -*- Makefile -*-
SHELL=/bin/sh
CC=gcc
CFLAGS=-Wall -O3 -ffast-math -fomit-frame-pointer -fPIC
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
	@mkdir -p bin
	mv ./ljmd-serial.x bin 


clean: clean_test
	rm -f *.mod objects/*.o ljmd-serial.x

# linker rule
ljmd-serial.x: $(OBJ) 
	$(CC) -o $@ $(CFLAGS) $^ $(LDLIBS)

# compilation pattern rule for objects
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	@mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) $< -o $@

ljmd-serial.so: $(OBJ)
	$(CC) -o $@ $^ -shared $(LDLIBS)
	@cp $@ test

test: ljmd-serial.so
	$(MAKE)	$(MFLAGS) -C test

.PHONY: clean_test

clean_test:
	$(MAKE)	$(MFLAGS) -C test clean

