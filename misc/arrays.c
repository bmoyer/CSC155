#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main()
{

long *longs;
char **arr;
longs = (long*)calloc(5, sizeof(long));
arr = (char **)calloc(5, sizeof(char*));
int i = 0; int j = 0;


printf("Array of longs:\n");

for(i=0; i<5; i++){
printf("longs[%d]: %lu\n",i, longs[i]);
}

printf("\nArray of pointers:\n");
for(j=0; j<5; j++){
printf("arr[%d]: %s\n",j, arr[j]);
}

}
