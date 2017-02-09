/* 
 * simple lennard-jones potential MD code with velocity verlet.
 * units: Length=Angstrom, Mass=amu; Energy=kcal
 *
 * baseline c version.
 */


#include <data.h>
#include <velverlet.h>
#include <force_kinerg.h>
#include <fpvelverlet.h>


/* velocity verlet */
void velverlet(mdsys_t *sys)
 {
    int i;
 
     /* first part: propagate velocities by half and positions by full step */
    /* for (i=0; i<sys->natoms; ++i) {
         sys->vx[i] += 0.5*sys->dt / mvsq2e * sys->fx[i] / sys->mass;
         sys->vy[i] += 0.5*sys->dt / mvsq2e * sys->fy[i] / sys->mass;
         sys->vz[i] += 0.5*sys->dt / mvsq2e * sys->fz[i] / sys->mass;
         sys->rx[i] += sys->dt*sys->vx[i];
         sys->ry[i] += sys->dt*sys->vy[i];
         sys->rz[i] += sys->dt*sys->vz[i];
	 }*/

     fpvelverlet(sys);
 
     /* compute forces and potential energy */
     force(sys);
 
     /* second part: propagate velocities by another half step */
     for (i=0; i<sys->natoms; ++i) {
         sys->vx[i] += 0.5*sys->dt / mvsq2e * sys->fx[i] / sys->mass;
         sys->vy[i] += 0.5*sys->dt / mvsq2e * sys->fy[i] / sys->mass;
         sys->vz[i] += 0.5*sys->dt / mvsq2e * sys->fz[i] / sys->mass;
     }
 }


