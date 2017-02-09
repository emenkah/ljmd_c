/* 
 * simple lennard-jones potential MD code with velocity verlet.
 * units: Length=Angstrom, Mass=amu; Energy=kcal
 *
 * baseline c version.
 */

#include <velverlet.h>

/* velocity verlet */
void velverlet(mdsys_t *sys)
 {
 
     /* first part: propagate velocities by half and positions by full step */
     fpvelverlet(sys);
 
     /* compute forces and potential energy */
     force(sys);
 
     /* second part: propagate velocities by another half step */
     spvelverlet(sys);
 
 }


