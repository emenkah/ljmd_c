#ifndef FPVERLET_H
#define FPVERLET_H


#include <data.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <input.h>

#include <data.h>
#include <force_kinerg.h>
#include <output.h>

/* first part time integration verlet */
void fpvelverlet(mdsys_t *sys);


#endif
