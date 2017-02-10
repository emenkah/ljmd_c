#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
//#include <input.h>

#include <data.h>
#include <utilities.h>
#include <force_kinerg.h>
//#include <output.h>
//#include <velverlet.h>

void forceTest(mdsys_t sys, int num_particles){
	
    int nprint;
    sys.natoms=num_particles;
    sys.mass=39.948;
    sys.epsilon=0.2379;
    sys.sigma=3.405;
    sys.rcut=8.5;
    sys.box=17.1580;
    sys.nsteps=1000;
    sys.dt=0.5;

    nprint=100;


    // allocate memory 
    sys.rx=(double *)malloc(sys.natoms*sizeof(double));
    sys.ry=(double *)malloc(sys.natoms*sizeof(double));
    sys.rz=(double *)malloc(sys.natoms*sizeof(double));
    sys.vx=(double *)malloc(sys.natoms*sizeof(double));
    sys.vy=(double *)malloc(sys.natoms*sizeof(double));
    sys.vz=(double *)malloc(sys.natoms*sizeof(double));
    sys.fx=(double *)malloc(sys.natoms*sizeof(double));
    sys.fy=(double *)malloc(sys.natoms*sizeof(double));
    sys.fz=(double *)malloc(sys.natoms*sizeof(double));

    azzero(sys.fx, sys.natoms);
    azzero(sys.fy, sys.natoms);
    azzero(sys.fz, sys.natoms);

	
	force(&sys);
	
	if (abs(sys.fx[0]) == abs(sys.fx[1]) && (sys.fx[0] || sys.fx[1] < 0)){
		printf("\tForce Test Success\n");
	}
	else {
		printf("\tForce Test failed\n");
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


int main(){
/***Unit tetsting ***/
forceTest(sys1, 2); 
return 0;
}
