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
void reverse(char s[]){
      int length = strlen(s) ;
      int c, i, j;

      for (i = 0, j = length - 1; i < j; i++, j--)
     {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
      }
printf("%s\n",s);
}

void caesar(char x[], int y){
printf("placeholder");
}

int handleInt(char *cmdArray[]){
if ( strcmp(cmdArray[0], "bit_or") == 0 && cmdArray[1] != NULL && cmdArray[2] != NULL)
	return atoi(cmdArray[1]) | atoi(cmdArray[2]) ;
if ( strcmp(cmdArray[0], "bit_and") == 0 && cmdArray[1] != NULL && cmdArray[2] != NULL)
	return atoi(cmdArray[1]) & atoi(cmdArray[2]) ;
if ( strcmp(cmdArray[0], "bit_xor") == 0 && cmdArray[1] != NULL && cmdArray[2] != NULL)
	return atoi(cmdArray[1]) ^ atoi(cmdArray[2]);
if ( strcmp(cmdArray[0], "bit_shift_left") == 0 && cmdArray[1] != NULL && cmdArray[2] != NULL)
	return atoi(cmdArray[1]) << atoi(cmdArray[2]) ;
if ( strcmp(cmdArray[0], "bit_shift_right") == 0 && cmdArray[1] != NULL && cmdArray[2] != NULL)
	return atoi(cmdArray[1]) >> atoi(cmdArray[2]) ;
}

void handleString(char *cmdArray[])
{
if ( strcmp(cmdArray[0], "caesar_cipher") == 0)
	caesar(cmdArray[0],atoi(cmdArray[1])); 
if( strcmp(cmdArray[0], "reverse") == 0 && cmdArray[1] != NULL){
	reverse(cmdArray[1]);}		
}

void handleProc(char *cmdArray[])
{
FILE *file = fopen(cmdArray[1], "r");
if (file != NULL){

char line[128];
while( fgets (line, sizeof line, file) != NULL)
{
//	fputs(line, stdout);  //this will print the file line by line
}
fclose(file);
}
else printf("file was null");

}//end function

int main(int argc, char *argv[]) {
  char *cmd;
  char line[MAX_LENGTH];
  char *commandArray[10];

  int i;

  while (1) {
    printf("$ ");
    if (!fgets(line, MAX_LENGTH, stdin)) break;

    // Parse and execute command
    if ((cmd = strtok(line, DELIMS))) {
	
	i = 0;	
	while( cmd != NULL ){
	commandArray[i] = cmd;	
	cmd = strtok(NULL, DELIMS);	
	i++;
	}

	//accessing members of commandArray
	//printf("arg1: %s arg2: %s", commandArray[0], commandArray[1]);
	char *firstCmd = commandArray[0];

	//check to make sure command is defined, if not print error message

	//int commands
	if( strcmp(firstCmd, "bit_or") == 0
	|| strcmp(firstCmd, "bit_and") == 0 
	|| strcmp(firstCmd, "bit_xor") == 0 
	|| strcmp(firstCmd, "bit_shift_left") == 0 
	|| strcmp(firstCmd, "bit_shift_right") == 0 ) 
	{ 
	printf("%d\n", handleInt(commandArray));
	}
	
	//string commands
	if ( strcmp(firstCmd, "reverse") == 0 
	|| strcmp(firstCmd, "caesar_cipher") == 0) 
	{ 
	handleString(commandArray);
	}
	
	if ( strcmp(firstCmd, "process_file") == 0) {  handleProc(commandArray); }
	
	//exit
	if ( strcmp(firstCmd, "exit") == 0) 
	{
	printf("Goodbye.\n");
	exit(0);
	}
	
}//end command parsing

}
}

