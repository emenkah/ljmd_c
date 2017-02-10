/* 
 * simple lennard-jones potential MD code with velocity verlet.
 * units: Length=Angstrom, Mass=amu; Energy=kcal
 *
 * baseline c version.
 */


#include <force_kinerg.h>
#include <utilities.h>
#include <math.h>



/* generic file- or pathname buffer length */
#define BLEN 200



/* compute kinetic energy */
void ekin(mdsys_t *sys)
{
    int i;

    sys->ekin=0.0;
    for (i=0; i<sys->natoms; ++i) {
        sys->ekin += 0.5*mvsq2e*sys->mass*(sys->vx[i]*sys->vx[i] + sys->vy[i]*sys->vy[i] + sys->vz[i]*sys->vz[i]);
    }
    sys->temp = 2.0*sys->ekin/(3.0*sys->natoms-3.0)/kboltz;
}

 

/* compute forces */
void force(mdsys_t *sys) 
{
    double r, rcsq, ffac;
    double rx,ry,rz, c12, c6, boxby2, boxby3 ;
    int i,j;

    /* zero energy and forces */
    sys->epot=0.0;
    azzero(sys->fx,sys->natoms);
    azzero(sys->fy,sys->natoms);
    azzero(sys->fz,sys->natoms);
	
	c12 = 4.0 * sys->epsilon * pow(sys->sigma, 12.0);
	c6  = 4.0 * sys->epsilon * pow(sys->sigma, 6.0);
	boxby2 = (0.5*sys->box);
	boxby3 =  2.0*boxby2;
	
	rcsq = sys->rcut * sys->rcut;
    for(i=0; i < (sys->natoms)-1; ++i) {
        for(j=i+1; j < (sys->natoms); ++j) {

            /* particles have no interactions with themselves */
            
            /* get distance between particle i and j */
            rx=sys->rx[i] - sys->rx[j];
         	while (rx >  boxby2) rx -= boxby3 ;			
			while (rx < -boxby2) rx += boxby3;

            ry=sys->ry[i] - sys->ry[j];
         	while (ry >  boxby2) ry -= boxby3 ;			
			while (ry < -boxby2) ry += boxby3;

            rz=sys->rz[i] - sys->rz[j] ;
         	while (rz >  boxby2) rz -= boxby3 ;			
			while (rz < -boxby2) rz += boxby3;

            r = rx*rx + ry*ry + rz*rz;
      

            /* compute force and energy if within cutoff */
            if (r < rcsq) {
				double r6, rinv;
				rinv = 1.0/r ;
				r6 = rinv*rinv*rinv ;	
				
                ffac = (12.0*c12*r6 - 6.0*c6)*r6*rinv;
                
                sys->epot += r6*(c12*r6 - c6);

                sys->fx[i] += rx*ffac;
                sys->fy[i] += ry*ffac;
                sys->fz[i] += rz*ffac;

                sys->fx[j] -= rx*ffac;
                sys->fy[j] -= ry*ffac;
                sys->fz[j] -= rz*ffac;
            }
        }
    }
}
