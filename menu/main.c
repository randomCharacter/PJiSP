#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"

#define MAX_PATH 30
#define MAX_COMMAND 70

int main (int argc, char *argv[], char* envp[]) {
	char path[MAX_PATH];
	char command[MAX_COMMAND];
	menu_setup(path);

	strcpy(command, "gcc -lm ");
	strcat(command, path);
	strcat(command, " -o ");
	path[strlen(path)-2]=0;
	strcat(command, path);

	printf("Compiling %s\n", command);
	system(command);

	printf("Running %s\n", path);
	system(path);

	printf("\n");
	return 0;
}

