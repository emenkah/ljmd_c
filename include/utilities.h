/* 
 * simple lennard-jones potential MD code with velocity verlet.
 * units: Length=Angstrom, Mass=amu; Energy=kcal
 *
 * baseline c version.
 */


#ifndef UTILITIES_H
#define UTILITIES_H

#include <data.h>
#include <stdio.h>
#include <string.h>


/* helper function: zero out an array */
void azzero(double *d, const int n);

/* helper function: apply minimum image convention */
double pbc(double x, const double boxby2);


#endif
