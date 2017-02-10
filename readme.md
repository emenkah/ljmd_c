# Best Practices in Scientific Computing

## The Lennard-Jones Molecular Dynamic Collaborative Project

The collaborative project invloved the optimization of a given Lennard-Joens potential molecular dynamics code through collaborative develoment.

A given single-file serial code was segmented in to moltiple files adaptiing to modular software reuse.

The package consists of a test-suite and which tests component implementation of the software:

1. Test for the computation of forces for a 2-particle system with a given cutoff.
2. Test for one full step time integration for given forces and velocity.
3. Test for the computation of kinatic energy for given velovites and mass.
4. Test for the verification of correct reading of Input parameter data.


Compiling the package:

```bash
make      :To compile the entire package 

make test :To comile and run all tests (This builds executables and runs them in the test directory)

make run  :To compile the test.sh file 

make ljmd-serial.so :To build the shared library 
```

The package has a python interface with top-level operations implemeted in python.

Force computations was also optimized and benchmarked. The plot below shows performance comparison.

For the compilation of the python script you need to run in the examples folder the follow line:

pyhton ../src/main.py argon_108.inp 
```

Pakage has two releases:
`release_v1` :Refcatored code and all the tests implementation

`release_v2` :Has an optimized force computation and a python interface to handle top-level operations.  

For the compilation of the python script you need to run in the examples folder the follow line:

pyhton ../src/main.py argon_108.inp 




```



## Unoptimized
Each sample counts as 0.01 seconds.
| % time|   cumulative secs |   self secs| calls    | self us/calls| total us/call |name         |           
|-------|-------------------|------------|----------|--------------|---------------|-------------|
|  76.91|      2.98   	 	| 2.98  	 |  10001   |298.37  	   | 377.97  	   |force        |
|  19.61|      3.75    		| 0.76 		 |346714668 |    0.00	   |     0.00  	   |  pbc        |
|   1.42|      3.80    		| 0.06 		 |   10001  |   5.51 	   |    5.51  	   | ekin        |
|   1.29|      3.85    		| 0.05 		 |   10000  |   5.01 	   |  382.97 	   | velverlet   |
|   0.90|      3.89    		| 0.04 		 |   30006  |   1.17 	   |    1.17 	   | azzero      |
|   0.00|      3.89    		| 0.00 		 |     101  |   0.00 	   |    0.00       | output      |
|   0.00|      3.89    		| 0.00 		 |      12  |   0.00 	   |    0.00       | get_a_line  |

### After Optimization by avoinding computationally expensive math functions

| % time|   cumulative secs |   self secs| calls    | self us/calls| total us/call |name 		 |           
|-------|-------------------|------------|----------|--------------|---------------|-------------|
| 98.77 |      1.40    	 	|  1.40  	 |    10001 |140.25	       |140.25 	       | force       |
| 0.71  |     1.41     		| 0.01  	 | 10000	|  1.0	       |  0.00   	   | fpvelverlet |
| 0.71  |     1.42     		| 0.01 		 |          |     	       |           	   | spvelverlet |
| 0.00  |     1.42     		| 0.00 		 |    30012 | 0.50	       | 0.50  	       | azzero      |
| 0.00  |     1.42     		| 0.00 		 |    10000 | 0.00	       | 0.00  	       | get_a_line  |


