#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"

#define MAX_FILE 30
#define MAX_COMMAND 70

int main (int argc, char *argv[], char* envp[]) {
	char file[MAX_FILE];
	char command[MAX_COMMAND];
	char remove_command[MAX_FILE];
	int compile_only=menu_setup(file);

	strcpy(command, "gcc ");
	strcat(command, file);
	strcat(command, " -o ");
	file[strlen(file)-2]=0;
	strcat(command, file);
	strcat(command, " -lm");

	printf("Compiling %s\n", command);
	system(command);
	
	if(compile_only==0) {
		printf("Running %s\n", file);
		system(file);

		strcpy(remove_command, "rm ");
		printf("Removing executable\n");
		system(strcat(remove_command, file));
	}
	
	return 0;
}

