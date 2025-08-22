#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1024   // buffer size

// Function prototypes
void encode(const char *in, char *out, char *maxCh, int *maxCt);
void decode(const char *in, char *out);

#endif
