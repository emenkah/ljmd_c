## Unoptimized
Each sample counts as 0.01 seconds.
| % time|   cumulative secs |   self secs| calls    | self us/calls| total us/call |name|           
|-------|-------------------|------------|----------|--------------|---------------|----|
|  76.91|      2.98   	 	| 2.98  	 |  10001   |298.37  	   | 377.97  	   |force
|  19.61|      3.75    		| 0.76 		 |346714668 |    0.00	   |     0.00  	   |  pbc
|   1.42|      3.80    		| 0.06 		 |   10001  |   5.51 	   |    5.51  	   | ekin
|   1.29|      3.85    		| 0.05 		 |   10000  |   5.01 	   |  382.97 	   | velverlet
|   0.90|      3.89    		| 0.04 		 |   30006  |   1.17 	   |    1.17 	   | azzero
|   0.00|      3.89    		| 0.00 		 |     101  |   0.00 	   |    0.00       | output
|   0.00|      3.89    		| 0.00 		 |      12  |   0.00 	   |    0.00       | get_a_line

### After Optimization by avoinding computationally expensive math functions

| % time|   cumulative secs |   self secs| calls    | self us/calls| total us/call |name|           
|-------|-------------------|------------|----------|--------------|---------------|----|
| 73.10 |    0.72     	 	| 0.72  	 |    10001 |71.63	       |95.67  	       |force
| 23.00 |    0.94      		| 0.23 		 | 173357337|  0.0	       |  0.00   	   |  pbc
|  2.04 |    0.96      		| 0.02 		 |          |     	       |           	   | ekin
|  1.53 |    0.98      		| 0.02 		 |    30012 | 0.50	       | 0.50  	       | velverlet
|  0.00 |    0.98      		| 0.00 		 |    10000 | 0.00	       | 0.00  	       | azzero
|  0.00 |    0.98      		| 0.00 		 |       12 | 0.00	       | 0.00          | get_a_line



