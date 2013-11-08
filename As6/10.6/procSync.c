//Getting a parent and child to alternate output.
//Simple example of process synchronization.
#include <unistd.h>
#include <stdio.h>
#include <semaphore.h>

int main(){

sem_t mutex;
int pid;
sem_init(&mutex,9,1);

pid = fork();

while(1){

if( pid == 0) {
sem_wait(&mutex);
printf("I am the child!\n");
sem_post(&mutex);
}


if( pid != 0 ) {
sem_wait(&mutex);
printf("I am the parent!\n");
sem_post(&mutex);
}

}

}
