/*
   Ben Moyer, 9/23/2013.
   CSC155, Lab 2
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAXLINE 80
#define MAX_ARGS 80

int main(void)
{
	char* argv[MAX_ARGS];
	char* tokenized = NULL;
	char delims[] = " ";

	char buf[MAXLINE];
	pid_t pid;
	int status;
	printf("%% ");

	while (fgets(buf, MAXLINE, stdin) != NULL ) {
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;  /* replace newline with null */

		if ((pid = fork()) < 0) {
			perror("fork");
		} else if (pid == 0) {  /* child */
			tokenized = strtok(buf,delims);
			int i = 0;
			while ( tokenized != NULL) {
				argv[i] = tokenized;
				tokenized = strtok(NULL,delims);
				i = i + 1;
			}
			argv[i] = NULL;
			execvp(argv[0],argv);
			printf("Error in cmd: %s", buf);
			exit(127);
		}

		/* parent */
		if ((pid  = waitpid(pid, &status, 0)) < 0)
			perror("waitpid");
		printf("%% ");
	}
	exit(0);
}
