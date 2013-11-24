This program lists the Processor, Kernel version, and Uptime when run on a Raspberry Pi running Raspbian OS.

To compile, place rpiinfo.c in a directory.  Then, type:

gcc rpiinfo.c -o rpiinfo

To generate the executable.  To run, type:

./rpiinfo

Example output:

CPU: ARMv6-compatible processor rev 7 (v6l)
Kernel:Linux version 3.6.11+ 
Uptime: 00:02:13:39

