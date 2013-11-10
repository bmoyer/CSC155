//Ben Moyer, November 2013//
This program demonstrates using functions from APUE to synchronize a parent and child process.  When executed, the program creates a file called "file1.txt", and writes the integer 0 to it.  The process then forks, and the parent and child alternate opening the file, reading in the number, and incrementing it by one.  Each time the parent or child increments the number, it prints the number and indicates which process it is.

To compile the program, place it in a directory and type: gcc retry.c
To run the program, type: ./a.out
