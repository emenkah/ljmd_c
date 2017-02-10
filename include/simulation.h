#ifndef SIMULATION_H
#define SIMULATION_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <input.h>
#include <velverlet.h>
#include <data.h>
#include <utilities.h>
#include <force_kinerg.h>
#include <output.h>

#define BLEN 200

int simulation(int nprint,int natoms, int nsteps, double mass, double epsilon, 
          double sigma, double box, double rcut, double dt, char restfile[BLEN], 
		char trajfile[BLEN], char ergfile[BLEN] ) ;

#endif

