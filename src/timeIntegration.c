#include <timeIntegration.h>


/* velocity verlet */
void velverlet(mdsys_t *sys)
{
    /* first part: propagate velocities by half and positions by full step */
    fptimeInegration(sys);

    /* compute forces and potential energy */
    force(sys);
 
     /* second part: propagate velocities by another half step */
    fptimeInegration(sys);
  
}


