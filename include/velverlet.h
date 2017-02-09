/* 
 * simple lennard-jones potential MD code with velocity verlet.
 * units: Length=Angstrom, Mass=amu; Energy=kcal
 *
 * baseline c version.
 */

#ifndef VERLET_H
#define VERLET_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <input.h>

#include <data.h>
#include <force_kinerg.h>
#include <output.h>


/* velocity verlet */
void velverlet(mdsys_t *sys);

#endif

