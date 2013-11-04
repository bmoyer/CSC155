#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void sig2str(int signo, char *str){

char *test = strdup(sys_siglist[signo]);

//printf("%s\n",test);

}

//look for sig2str_max or something similar..

int main()
{

char *test = malloc(1000);

}
