#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[])
{
	struct stat buf;
	double fileAge;
	time_t now;
	char* newestFileName;

	//checking usage
	if (argc != 4){
		fprintf(stderr, "usage : ./mystat <file1> <file2> <file3>\n");
		exit(1);
	}
	
	printf("\n**Filename - Last Modification Time**\n");	

	//putting the current time into 'now' variable
	time(&now);
	
	//looping through each argument
	for(int i=1; i < 4; i++){ 
	
	//putting file info into the buffer
	stat(argv[i], &buf);
	
	//Printing last modification time of each file entered
	printf("%s - %s", argv[i], ctime(&buf.st_ctime));
	
	//if this is the first arg, set time difference and filename
	if( i == 1) {
		fileAge = difftime(now, buf.st_ctime);
		newestFileName = argv[i];
	 }

	//newer file found, so update time dif(fileAge) and filename
	if( i !=1 && difftime(now, buf.st_ctime) < fileAge ){
		newestFileName = argv[i];
		fileAge = difftime(now, buf.st_ctime);
		}
}	
	printf("\nThe most recently modified file is: %s\n", newestFileName);
}
