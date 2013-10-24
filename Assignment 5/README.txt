= iManip.c =
Author: Ben Moyer
Date: 10/23/13
= Description = 
iManip is a simpel shell that can take various command names and return the result of the command to the user.  Supported commands are as follows:
-bit_shift_left X Y returns integer X shifted left Y places
-bit_shift_right X Y returns integer X shifted right Y places
-bit_and X Y returns X <bitwise AND> Y
-bit_or X Y returns X <bitwise OR> Y
-bit_xor X Y returns X <bitwise XOR> Y
-reverse X returns the reverse of the string X
-caesar_cipher X Y returns the string X shifted Y places in the manner of a Caesar's Cipher
-process_file X Y takes a file X, which has one of the preceding commands on each line.  It writes the return of each command to a new line in a new file Y.  

= Using iManip =
To compile iManip, put iManip.c in some directory and type the following: gcc iManip.c -o iManip

To run iManip, type ./iManip after the program has been compiled.