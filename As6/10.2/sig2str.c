#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void sig2str(int signo, char *str){
	char *sigName = strdup(sys_siglist[signo]);
	strcpy(str, sigName);
}

int main()
{
	int i;
	for(i=1; i<20; i++){ 

		char *test = malloc(50);
		sig2str(i,test);
		printf("%s\n",test);
		free(test);

	}

}
