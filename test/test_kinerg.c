#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <data.h>
#include <constants.h>
#include <utilities.h>

void test_kinerg()
{
	const double result=27986992.114647;
	mdsys_t sys;
	
    /* read input file */
    sys.natoms=3;
    sys.mass=39.948;
    sys.epsilon=0.2379;
    sys.sigma=3.405;
    sys.rcut=8.5;
    sys.box=17.1580;
    sys.nsteps=1;
    sys.dt=5.0;
    
    //Allocate
    sys.rx=(double *)malloc(sys.natoms*sizeof(double));
    sys.ry=(double *)malloc(sys.natoms*sizeof(double));
    sys.rz=(double *)malloc(sys.natoms*sizeof(double));
    sys.vx=(double *)malloc(sys.natoms*sizeof(double));
    sys.vy=(double *)malloc(sys.natoms*sizeof(double));
    sys.vz=(double *)malloc(sys.natoms*sizeof(double));
    sys.fx=(double *)malloc(sys.natoms*sizeof(double));
    sys.fy=(double *)malloc(sys.natoms*sizeof(double));
    sys.fz=(double *)malloc(sys.natoms*sizeof(double));


	//Setting everything to 0
    azzero(sys.rx, sys.natoms);
    azzero(sys.ry, sys.natoms);
    azzero(sys.rz, sys.natoms);
    
    azzero(sys.vx, sys.natoms);
    azzero(sys.vy, sys.natoms);
    azzero(sys.vz, sys.natoms);
 
    //Giving velocities and positions
    sys.rx[0]=0.0;
    sys.rx[0]=7.0;
    sys.rx[0]=14.0;
    
    sys.vx[0]=12.0;
    sys.vx[1]=-10.0;
    sys.vx[2]=18.5;

    force(&sys);

    ekin(&sys);
    
    if(abs(sys.ekin-result)<1e-12)
        printf("\t TEST Kinetic energy :\t ------ \tPASSED\n");
    else{
        printf("\t TEST Kinetic energy test:\t------ \t FAILED\n");
        printf("%f \n%f\n",sys.ekin,result);
	}
    
    free(sys.rx);
    free(sys.ry);
    free(sys.rz);
    free(sys.vx);
    free(sys.vy);
    free(sys.vz);
    free(sys.fx);
    free(sys.fy);
    free(sys.fz);

}
