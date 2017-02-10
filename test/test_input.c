#include <input.h>
#define BLEN 200

void InputReadTest(){

  int nprint, err;
    char restfile[BLEN], trajfile[BLEN], ergfile[BLEN], line[BLEN];
    FILE *fp,*traj,*erg;
	
	
    /* read input file */
    readInputRest(&sys ,  restfile,  trajfile,  ergfile,  line, &nprint);


	
 int natoms_t=108;
 double mass_t=39.948;          //    mass in AMU
 double epsilon_t=0.2379;          // epsilon in kcal/mol
 double sigma_t=3.405;            // sigma in angstrom
 double rcut=8.5;                 // rcut in angstrom
 double length_t=17.1580;          // box length (in angstrom)
 string rest_t='argon_108.rest';   // restart
 string traj_t='argon_108.xyz';    // trajectory
 string energ_t='argon_108.dat';   // energies
 int nrMDsteps_t=10000;                // nr MD steps
 double timestep_t=5.0;                   // MD time step (in fs)
 int frequency_t=100;                  // output print frequency



 if(natoms_t==sys->natoms){err+=1;}
else 	printf("\t natoms: FAILED \n");
				     
 if(mass_t==sys->mass){err+=1;}
 else 	printf("\t mass: FAILED \n");
 
 if(epsilon_t==sys->epsilon){err+=1;}
 else 	printf("\t epsilon: FAILED \n");

if(sigma_t==sys->sigma){err+=1;}
 else 	printf("\t sigma: FAILED \n");

if(rcut_t==sys->rcut){err+=1;}
 else 	printf("\t rcut: FAILED \n");

if(length_t==sys->box){err+=1;}
 else 	printf("\t length: FAILED \n");


 if(rest_t==restfile){err+=1;}
 else 	printf("\t restfile: FAILED \n");

if(traj_t==trajfile){err+=1;}
 else 	printf("\t trajfile: FAILED \n");

if(energ_t==ergfile){err+=1;}
 else 	printf("\t ergfile: FAILED \n");


if(nrMDsteps_t==sys->nsteps){err+=1;}
 else 	printf("\t rcut: FAILED \n");

if(timestep_t== sys->dt){err+=1;}
 else 	printf("\t rcut: FAILED \n");

if(frequency_t==&nprint){err+=1;}
 else 	printf("\t frequency: FAILED \n");




if (err==12 ){
		printf("\t TEST input:\t------\t PASSED\n");
	}
	else {
		printf("\t TEST input: \t ------- FAILED\n");
		return 99;
	}


   
}

int main()
{

  InputReadTest();
  return 0;

}
