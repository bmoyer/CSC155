#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifdef _WIN32
#include <windows.h>
#define chdir _chdir

#else
#include <unistd.h>
#endif

#define MAX_LENGTH 1024
#define DELIMS " \t\r\n"

//these are the functions that handle() will call
//they handle any commands passed in.


//this function should take any char *cmdArray[] and return the correct value
//this should directly handle int commands, and pass off string commands.
//ALL COMMANDS SHOULD GO HERe

//this takes cmdArray[] either from a line in a process_file or from user input directly
char test[100];

void reverse(char s[]){
int length = strlen(s); int c, i, j;

for(i = 0, j = length-1; i<j; i++, j--){
	c = s[i];
	s[i] = s[j];
	s[j] = c;
	}
sprintf(test,"%s", s);
}


char *handle(char *cmdArray[])
{
char *cmd = cmdArray[0];
if( strcmp(cmd,"bit_or") == 0) { sprintf(test, "%d", atoi(cmdArray[1]) | atoi(cmdArray[2])); return test; }
if( strcmp(cmd,"bit_and") == 0) { sprintf(test, "%d", atoi(cmdArray[1]) & atoi(cmdArray[2])); return test; }
if( strcmp(cmd,"bit_xor") == 0) { sprintf(test, "%d", atoi(cmdArray[1]) ^ atoi(cmdArray[2])); return test; }
if( strcmp(cmd,"bit_shift_right") == 0) { sprintf(test, "%d", atoi(cmdArray[1]) >> atoi(cmdArray[2])); return test; }
if( strcmp(cmd,"bit_shift_left") == 0) { sprintf(test, "%d", atoi(cmdArray[1]) << atoi(cmdArray[2])); return test; }
if( strcmp(cmd,"reverse") == 0) { reverse(cmdArray[1]); return test; }
if( strcmp(cmd,"caesar_cipher") == 0) { return *cmdArray; }//placeholder
}

void processFile(char *cmdArray[])
{
FILE *fileIn = fopen(cmdArray[1], "r");
FILE *fileOut = fopen(cmdArray[2], "wb+");
char *cmd; int i; char *commandArray[10];


if (fileIn != NULL){
char line[128];

while( fgets(line, sizeof line, fileIn) != NULL)
{
//this is where you should do stuff line-by-line
	if (cmd = strtok(line, DELIMS)){
	i = 0;
	while( cmd != NULL){
		commandArray[i] = cmd;
		cmd = strtok(NULL, DELIMS);
		i++;
		}
	//write results to the new file, plus a newline.
	fputs( handle(commandArray), fileOut);
	fputs("\n",fileOut);
	}

}
fclose(fileIn);
fclose(fileOut);
	}	
}

void processInput(char *cmdArray[]){
char *cmd = cmdArray[0];
if( strcmp(cmd,"process_file") != 0) { printf("%s\n",handle(cmdArray)); }
if( strcmp(cmd,"process_file") == 0) { processFile(cmdArray);}
}



//start of main
int main(int argc, char *argv[]) {
  char *cmd;
  char line[MAX_LENGTH];
  char *commandArray[10];
  int i;

  while (1) {
    printf("$ ");
    if (!fgets(line, MAX_LENGTH, stdin)) break;

    if ((cmd = strtok(line, DELIMS))) {
	
	i = 0;	
	while( cmd != NULL ){
	commandArray[i] = cmd;	
	cmd = strtok(NULL, DELIMS);	
	i++;
	}
	processInput(commandArray);

}

}
}

