/* 
 * simple lennard-jones potential MD code with velocity verlet.
 * units: Length=Angstrom, Mass=amu; Energy=kcal
 *
 * baseline c version.
 */


#ifndef FORCE_KINERG_H
#define FORCE_KINERG_H

#include <data.h>
#include <constants.h>


/* compute kinetic energy */
void ekin(mdsys_t *sys);


/* compute forces */
void force(mdsys_t *sys); 

#endif
