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
