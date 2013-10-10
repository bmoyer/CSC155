#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
int main(int argc, char *argv[])
{
	char buf[30];
	DIR *dp;
	struct dirent *dirp;
	bzero(buf, sizeof(buf));
	if (argc != 4){
		fprintf(stderr, "usage : ls1 <directory> <directory> <directory>\n");
		exit(1);
	}
	int i = 0;
	for(i = 1; i < 4; i++){
	if ((dp = opendir(argv[i])) == NULL ) {
		strncpy(buf, "can't open", sizeof("can't open"));
		strcat(buf, argv[1]);
		strcat(buf, "\n");
		fprintf(stderr, buf);
		exit(1);
	}
	printf("\nDirectory #%d: %s\n---------\n",i,argv[i]);
	while ((dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->d_name);
	closedir(dp);
	}
	exit(0);
}
