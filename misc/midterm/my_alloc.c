#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main()
{
int *w, *x, *y, *z;
w = (int*)malloc(sizeof(int));
x = (int*)malloc(sizeof(int));
y = (int*)malloc(sizeof(int));
z = (int*)malloc(sizeof(int));
*w = 2; *x = 4; *y = 6; *z = 8;


printf("w: %d x: %d y: %d z: %d\n", *w, *x, *y, *z);
*w = (*w)*(*w);
*x = (*x)*(*x);
*y = (*y)*(*y);
*z = (*z)*(*z);
printf("and after squaring them: \n");
printf("w: %d x: %d y: %d z: %d\n", *w, *x, *y, *z);
free(w); free(x); free(y); free(z);

}
