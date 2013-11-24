#include <stdio.h>
#include <stdlib.h>

void uptime(){

        int i = 0;
        char *token;
        const char DELIMS[2] = ". ";
        char* totalsecs;
        char str[100];

        //getting contents of /proc/uptime
        FILE *file = fopen("/proc/uptime","r");
        fgets(str,100,file);
        fclose(file);

        //tokenizing stuff
        token = strtok(str,DELIMS);
        totalsecs = token;

        //getting total seconds
        int secs = atoi(totalsecs);
	
	//converting total seconds to other units
        int days = secs/86400;
        secs -= days*86400;
        int hours = secs/3600;
        secs -= hours*3600;
        int minutes = secs/60;
        secs -= minutes*60;
        int seconds = secs;

        printf("Uptime: %02d:%02d:%02d:%02d\n", days,hours,minutes,seconds);
}
void cpuinfo(){
        int i = 0;
        char *token;
        const char DELIMS[2] = ":\n";
        char str[100];
        char *toks[100];

	//getting contents of /proc/cpuinfo
        FILE *file = fopen("/proc/cpuinfo","r");
        fgets(str,100,file);
        fclose(file);

        int j = 0;
        token = strtok(str,DELIMS);
        while(token != NULL){
        toks[j] = token;
        token = strtok(NULL, DELIMS);
        }
        printf("CPU:%s\n",toks[0]);
}

void kernelinfo(){
        int i = 0;
        char *token;
        const char DELIMS[1] = "(";
        char str[100];
        char *toks[100];

        //getting contents of /proc/version
        FILE *file = fopen("/proc/version","r");
        fgets(str,100,file);
        fclose(file);

        int j = 1;
        //tokenizing stuff
        token = strtok(str,DELIMS);
        toks[0] = token;
        while(token != NULL){
        toks[j] = token;
        token = strtok(NULL, DELIMS);
        }
        printf("Kernel:%s\n",toks[0]);
}
int main(){

cpuinfo();
kernelinfo();
uptime();
}
