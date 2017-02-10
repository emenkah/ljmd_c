#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <data.h>
#include <constants.h>
#include <utilities.h>
#include <spvelverlet.h>
#include <fpvelverlet.h>


void  test_velverlet()
{

  mdsys_t sys;

  sys.natoms=2;
  sys.nsteps=1;
  sys.dt=5.0;
  sys.mass=39.948;
  sys.epsilon=0.2379;
  sys.sigma=3.405;
  sys.box=17.1580;
  sys.rcut=8.5;
  sys.temp=0;

  sys.rx=(double *)malloc(sys.natoms*sizeof(double));
  sys.ry=(double *)malloc(sys.natoms*sizeof(double));
  sys.rz=(double *)malloc(sys.natoms*sizeof(double));
  sys.vx=(double *)malloc(sys.natoms*sizeof(double));
  sys.vy=(double *)malloc(sys.natoms*sizeof(double));
  sys.vz=(double *)malloc(sys.natoms*sizeof(double));
  sys.fx=(double *)malloc(sys.natoms*sizeof(double));
  sys.fy=(double *)malloc(sys.natoms*sizeof(double));
  sys.fz=(double *)malloc(sys.natoms*sizeof(double));


        sys.rx[0]=1;
        sys.ry[0]=0;
        sys.rz[0]=0;

        sys.rx[1]=-1;
        sys.ry[1]=0;
        sys.rz[1]=0;

        sys.vx[0]=0;
        sys.vy[0]=0;
        sys.vz[0]=0;

        sys.vx[1]=0;
        sys.vy[1]=0;
        sys.vz[1]=0;

  sys.nfi=0;

  double aspected_ekin=0.0261;

  // Starting simulation with sys.natoms atoms for sys.nsteps step
  //Initializing Constant force
  sys.fx[0]=10;
  sys.fx[1]=10;

  // Starting integration loop
for(sys.nfi=1; sys.nfi <= sys.nsteps; ++sys.nfi) {

      fpvelverlet(&sys);

      spvelverlet(&sys);

      ekin(&sys);
  }
  

  if (abs(sys.ekin-aspected_ekin)<=0.001) 
       printf("\t TEST Velverlet:\t------ \t PASSED\n" );
  else{
       printf("\t TEST Velverlet:\t------ \t FAILED\n" );
       printf("\t NFI   \t   TEMP     \t  EKIN   \n");
       printf("\t %d   \t   %1.3f    \t  %1.3f \t\n",sys.nfi,sys.temp,sys.ekin);
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


int main()
{
  test_velverlet();

  return 0;

}
