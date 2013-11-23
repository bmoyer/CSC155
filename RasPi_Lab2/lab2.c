#include <stdio.h>
#include <stdlib.h>

int main(){

        int i = 0;
        char *token;
        const char DELIMS[2] = ". ";
        char* timeArray[10];
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

        //beam it back down
        printf("Uptime: %02d:%02d:%02d:%02d\n", days,hours,minutes,seconds);
}

