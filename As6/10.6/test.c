#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
void    TELL_WAIT(void);        /* parent/child from Section 8.9 */
void    TELL_PARENT(pid_t);
void    TELL_CHILD(pid_t);
void    WAIT_PARENT(void);
void    WAIT_CHILD(void);





static volatile sig_atomic_t sigflag; /* set nonzero by sig handler */
static sigset_t newmask, oldmask, zeromask;

static void
sig_usr(int signo)   /* one signal handler for SIGUSR1 and SIGUSR2 */
{
    sigflag = 1;
}

void
TELL_WAIT(void)
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR)
        err_sys("signal(SIGUSR1) error");
    if (signal(SIGUSR2, sig_usr) == SIG_ERR)
        err_sys("signal(SIGUSR2) error");
    sigemptyset(&zeromask);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGUSR1);
    sigaddset(&newmask, SIGUSR2);

    /*
     * Block SIGUSR1 and SIGUSR2, and save current signal mask.
     */
    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        err_sys("SIG_BLOCK error");
}

void
TELL_PARENT(pid_t pid)
{
    kill(pid, SIGUSR2);              /* tell parent we're done */
}

void
WAIT_PARENT(void)
{
    while (sigflag == 0)
        sigsuspend(&zeromask);   /* and wait for parent */
    sigflag = 0;

    /*
     * Reset signal mask to original value.
     */
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        err_sys("SIG_SETMASK error");
}

void
TELL_CHILD(pid_t pid)
{
    kill(pid, SIGUSR1);             /* tell child we're done */
}

void
WAIT_CHILD(void)
{
    while (sigflag == 0)
        sigsuspend(&zeromask);  /* and wait for child */
    sigflag = 0;

    /*
     * Reset signal mask to original value.
     */
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        err_sys("SIG_SETMASK error");
}


int main()
{
//create the file, write int 0 to it
FILE *file = fopen("file1.txt", "w");
fprintf(file, "%d", 0);
fclose(file);

pid_t pid = fork(); 

while(1){ //loop for the forks to play in

//open the target file
FILE *file2 = fopen("file1.txt", "w+");

//allocating buffer to read the number into
char *s = malloc(sizeof(int));
fgets(s, 4, file2);

//converting number char to int, incrementing
//long int addone = strtol(s,NULL,0);
int addone = atoi(s);
addone++;

//writing back incremented number
fprintf(file2,"%d",addone);
fclose(file2);

if( pid==0 ) { printf("Incremented by CHILD to %d\n",addone);  }
if( pid!=0 ) { printf("Incremented by PARENT to %d\n",addone); wait();}
free(s);
}

}
