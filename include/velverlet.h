/* 
 * simple lennard-jones potential MD code with velocity verlet.
 * units: Length=Angstrom, Mass=amu; Energy=kcal
 *
 * baseline c version.
 */

#ifndef VERLET_H
#define VERLET_H

#include <fpvelverlet.h>
#include <spvelverlet.h>

/* velocity verlet */
void velverlet(mdsys_t *sys);

#endif

