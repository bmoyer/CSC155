#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <setjmp.h>
#include <stdbool.h>
#ifdef _WIN32
#include <windows.h>
#define chdir _chdir

#else
#include <unistd.h>
#endif

#define MAX_LENGTH 1024
#define DELIMS " \t\r\n"

//error catching test
#define TRY do{ jmp_buf ex_buf__; if( !setjmp(ex_buf__) ){
#define CATCH } else {
#define ETRY } }while(0)
#define THROW longjmp(ex_buf__, 1)



char buf[100];

void kill(){ printf("Stopping execution, bye"); exit(0);}

bool isValidInput(char *cmdArray[]){

	char *cmd = cmdArray[0];

	if( strcmp(cmd, "exit") == 0) { return true; }
	if( strcmp(cmd, "bit_shift_left") == 0) { return true; }
	if( strcmp(cmd, "bit_shift_right") == 0) { return true; }
	if( strcmp(cmd, "bit_or") == 0) { return true; }
	if( strcmp(cmd, "bit_xor") == 0) { return true; }
	if( strcmp(cmd, "bit_and") == 0) { return true; }
	if( strcmp(cmd, "process_file") == 0) { return true; }
	if( strcmp(cmd, "caesar_cipher") == 0) { return true; }
	if( strcmp(cmd, "reverse") == 0) { return true; }
	else { return false; }

}


void reverse(char s[]){
	int length = strlen(s); int c, i, j;

	for(i = 0, j = length-1; i<j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	sprintf(buf,"%s", s);
}

void caesar(char s[], int shift){
	if( shift > 25) { shift = shift%26; }

	int i = 0;
	while( s[i] != '\0' ){
		if( s[i] >= 65 && s[i] <=90){   //handling caps
			if( s[i] + shift > 90){
				s[i] = ((s[i] + shift)%90)+64;
			}
			else
			{
				s[i] += shift;
			}
		}
		if( s[i] >=97 && s[i] <= 122){ 
			if( s[i] + shift > 122){ //handling lowercase
				s[i] = ((s[i] + shift)%58) + 90;
			}
			else
			{
				s[i] += shift;
			}
		}
		if( s[i] >= 48 && s[i] <= 57){
			if( s[i] + shift > 57 ){ //handling ints 0-9
				//s[i] = ((s[i] + shift)%58) + 38;
				s[i] = ((s[i] + shift)%57) + 47;
			}

			else
			{
				s[i]+= shift;
			}
		}
		i++;
	}
	sprintf(buf, "%s", s);
}

char *handle(char *cmdArray[])
{
	TRY{
		char *cmd = cmdArray[0];
		if( strcmp(cmd,"bit_or") == 0) { sprintf(buf, "%d", atoi(cmdArray[1]) | atoi(cmdArray[2])); return buf; }
		if( strcmp(cmd,"bit_and") == 0) { sprintf(buf, "%d", atoi(cmdArray[1]) & atoi(cmdArray[2])); return buf; }
		if( strcmp(cmd,"bit_xor") == 0) { sprintf(buf, "%d", atoi(cmdArray[1]) ^ atoi(cmdArray[2])); return buf; }
		if( strcmp(cmd,"bit_shift_right") == 0) { sprintf(buf, "%d", atoi(cmdArray[1]) >> atoi(cmdArray[2])); return buf; }
		if( strcmp(cmd,"bit_shift_left") == 0) { sprintf(buf, "%d", atoi(cmdArray[1]) << atoi(cmdArray[2])); return buf; }
		if( strcmp(cmd,"reverse") == 0) { reverse(cmdArray[1]); return buf; }
		if( strcmp(cmd,"caesar_cipher") == 0) { caesar(cmdArray[1], atoi(cmdArray[2])); return buf; }
	}
	CATCH{
		printf("error in command");
	}
	ETRY;
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
			//going line by line through fileIn, filling commandArray[] for processing
			if (cmd = strtok(line, DELIMS)){
				i = 0;
				while( cmd != NULL){
					commandArray[i] = cmd;
					cmd = strtok(NULL, DELIMS);
					i++;
				}
				//write results to the new file, plus a newline.
				if( isValidInput(commandArray)) {
					fputs( handle(commandArray), fileOut);

					fputs("\n",fileOut);
				}
				else { fputs("<Invalid command>\n", fileOut); }
			}


		}
		//tying up some loose ends before we're done
		fclose(fileIn);
		fclose(fileOut);
		printf("Done processing.  Output written to %s.\n", cmdArray[2]);
	}
	else{ printf("Input file was null, try again.\n"); }	
};


//all commands are initially sent here for processing.
void processInput(char *cmdArray[]){
	char *cmd = cmdArray[0];
	if( strcmp(cmd,"exit") == 0) { printf("cya\n"); exit(0);}
	if( strcmp(cmd,"process_file") == 0) { processFile(cmdArray);}
	if( strcmp(cmd,"process_file") != 0) { printf("%s\n",handle(cmdArray)); }
}

int main(int argc, char *argv[]) {
	char *cmd;
	char line[MAX_LENGTH];
	char *commandArray[10];
	int i;

	while (1) {
		printf(">> ");
		if (!fgets(line, MAX_LENGTH, stdin)) break;

		if ((cmd = strtok(line, DELIMS))) {

			i = 0;	
			while( cmd != NULL ){
				commandArray[i] = cmd;	
				cmd = strtok(NULL, DELIMS);	
				i++;
			}
			//all input is put into commandArray[] and sent to processInput() for processing

			if( isValidInput(commandArray)) {processInput(commandArray);}
			else { printf("Command not supported\n"); }
		}
	}
}

