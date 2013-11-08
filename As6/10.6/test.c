#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
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
