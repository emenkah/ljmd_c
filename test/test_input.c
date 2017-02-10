
#define BLEN 200

void InputReadTest(mdsys_t sys,  char * restfile, char * trajfile, char * ergfile, int nprint){

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


108               # natoms
39.948            # mass in AMU
0.2379            # epsilon in kcal/mol
3.405             # sigma in angstrom
8.5               # rcut in angstrom
17.1580           # box length (in angstrom)
argon_108.rest    # restart
argon_108.xyz     # trajectory
argon_108.dat     # energies
10000             # nr MD steps
5.0               # MD time step (in fs)
100               # output print frequency







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
