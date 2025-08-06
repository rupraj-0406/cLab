#include <stdio.h>
#include "HelloWorld.h"

int iMyGlobalVar;

void printHelloWorld() {
	iMyGlobalVar = 20;
	printf ("Hello\n");
	return;
}

