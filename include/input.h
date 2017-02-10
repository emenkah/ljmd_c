#ifndef INPUT_H
#define INPUT_H

#include <stdio.h> 
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <data.h>
#include <utilities.h>

int get_a_line(FILE *fp, char *buf);

int readInputRest(mdsys_t *sys , char * restfile, char * trajfile, char * ergfile, char * line, int *nprint);

#endif
