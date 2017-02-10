/* 
 * simple lennard-jones potential MD code with velocity verlet.
 * units: Length=Angstrom, Mass=amu; Energy=kcal
 *
 * baseline c version.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <input.h>

#include <data.h>
#include <utilities.h>
#include <force_kinerg.h>
#include <output.h>
#include <velverlet.h>

/* generic file- or pathname buffer length */
#define BLEN 200


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
/*******Data Verification *********/
void InputReadTest(mdsys_t sys,  char * restfile, char * trajfile, char * ergfile, int nprint){

	printf("\tVerifying Input Parameters\n");
	printf("\t%d \n", sys.natoms);
    printf("\t%g \n", sys.mass);
    printf("\t%g \n", sys.epsilon);
    printf("\t%g \n", sys.sigma);
    printf("\t%g \n", sys.rcut);
    printf("\t%g \n", sys.box);
    printf("\t%s \n", restfile);
    printf("\t%s \n", trajfile);
    printf("\t%s \n", ergfile);
    printf("\t%d \n", sys.nsteps);
    printf("\t%g \n", sys.dt);
    printf("\t%d \n", nprint);
	
}




/* main */
int main(int argc, char **argv) {

	int nprint, err;
    char restfile[BLEN], trajfile[BLEN], ergfile[BLEN], line[BLEN];
    FILE *fp,*traj,*erg;
	
	mdsys_t sys, sys1;
	
    /* read input file */
	err=readInputRest(&sys ,  restfile,  trajfile,  ergfile,  line, &nprint);
	if (err== 0){
		printf("\tFile read: SUCESSS\n");
	}
	else {
		printf("\tInput file read FAILED!\n");
		return 99;
	}

	/*******Verifying input data **/	
	InputReadTest(sys, restfile,  trajfile,  ergfile, nprint);	


    /* initialize forces and energies.*/
    sys.nfi=0;
    force(&sys);
    ekin(&sys);
    
    erg=fopen(ergfile,"w");
    traj=fopen(trajfile,"w");

    printf("Starting simulation with %d atoms for %d steps.\n",sys.natoms, sys.nsteps);
    printf("     NFI            TEMP            EKIN                 EPOT              ETOT\n");
    output(&sys, erg, traj);

    /**************************************************/
    /* main MD loop */
    for(sys.nfi=1; sys.nfi <= sys.nsteps; ++sys.nfi) {

        /* write output, if requested */
        if ((sys.nfi % nprint) == 0)
            output(&sys, erg, traj);

        /* propagate system and recompute energies */
        velverlet(&sys);
        ekin(&sys);
    }
    /**************************************************/

    /* clean up: close files, free memory */
    printf("Simulation Done.\n");
    fclose(erg);
    fclose(traj);


	/***Unit tetsting ***/
   	forceTest(sys1, 2); 


    free(sys.rx);
    free(sys.ry);
    free(sys.rz);
    free(sys.vx);
    free(sys.vy);
    free(sys.vz);
    free(sys.fx);
    free(sys.fy);
    free(sys.fz);

    return 0;
}
