#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void sig2str(int signo/*, char *str*/){

char *test = strdup(sys_siglist[signo]);
printf("%s\n",test);
}

int main()
{

sig2str(1);
sig2str(2);
sig2str(3);


}
