#!/usr/bin/env python 

from ctypes import *
import os,sys

dso = CDLL('../ljmd-serial.so')


def read_file(inputfile):
    f = open(inputfile,"r")
    lines = [line.rstrip('\n').split(" ")[0] for line in f]
    natoms,mass,epsilon,sigma,rcut,box,restfile,\
    trajfile,ergfile,nsteps,dt,nprint =lines

    c_nprint   =c_int(int(nprint))
    c_natoms = c_int(int(natoms))
    c_nsteps = c_int(int(float(nsteps)))
    c_dt = c_double(float(dt))
  #  c_line = c_int(int(line))
    c_mass = c_double(float(mass))
    c_epsilon = c_double(float(epsilon))
    c_sigma = c_double(float(sigma))
    c_rcut = c_double(float(rcut))
    c_box = c_double(float(box))
    c_restfile = c_char_p("".join(restfile.split()).encode())
    c_trajfile = c_char_p("".join(trajfile.split()).encode())
    c_ergfile = c_char_p("".join(ergfile.split()).encode())

    print('ko')
    try:
        dso.simulation(c_nprint,c_natoms,c_nsteps, c_mass,c_epsilon,c_sigma,
                c_box,c_rcut,c_dt,c_restfile.value,c_trajfile.value,c_ergfile.value) 
        
        print('ok')

    except (OSError):
        print("Shared object `../ljmd.so` not found.\n Run `make` for solve the problem")



if __name__ == '__main__':
	
	if len(sys.argv) > 1:
		inputfile = str(sys.argv[1])
		read_file(inputfile)
	else:
            pass

