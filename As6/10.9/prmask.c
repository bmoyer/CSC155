#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdint.h>
void err_sys(const char* x) 
{ 
    perror(x); 
    exit(1); 
}


pr_mask(const char *str)
{
    sigset_t    sigset;
    int         errno_save,i;
    

    errno_save = errno;     /* we can be called by signal handlers */
    if (sigprocmask(0, NULL, &sigset) < 0)
        err_sys("sigprocmask error");

	//adding some signals to test
	sigaddset(&sigset,SIGINT);
	sigaddset(&sigset,SIGQUIT);
	sigaddset(&sigset,SIGCONT);
	sigaddset(&sigset,SIGKILL);

    printf("%s", str);

    for(i=1; i < NSIG; i++){
    if(sigismember(&sigset, i)){
    printf("%s\n", strdup(sys_siglist[i]));
    }
	}


    printf("\n");
    errno = errno_save;
}

int main()
{
pr_mask("Starting main\n");
}
