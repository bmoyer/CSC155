#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
char* date;
int main(int argc, char *argv[])
{
	char buf[30];
	DIR *dp;
	struct dirent *dirp;

	struct stat b1;
	char *ptr;
	char *date;

	bzero(buf, sizeof(buf));
	if (argc != 4){
		fprintf(stderr, "usage : ./mystat <file1> <file2> <file3>\n");
		exit(1);
	}
	int i = 0;
	for(i = 1; i < 4; i++){
	stat(argv[i], &b1);
//	printf("\nFile: %s\n", argv[i]);
	
	printf("File: %s, Time: %s", argv[i], ctime(&b1.st_ctime));


	if( (char*)&b1.st_ctime > date ) { date = ctime(&b1.st_ctime); } 
	if( i != 1) { if( ctime(&b1.st_ctime) > date) { date = ctime(&b1.st_ctime); } }

	//time of last status change.  can be modified.
	}
	printf("%s",date);
	exit(0);
}
