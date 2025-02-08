**README**

This User Processes Program runs simultaneous child processes and returns the Process ID as well as the parent's process ID.

This program should be run by first comipling using the command "make" in the terminal.

When opening this file in the command line there are a few arguments to enter to run the program successfully along with numbers after the arguments. 

These arguments include [-n, -s, -t] with the optional -h argument in the beginning of the file for a list of helpful tips to run the program.

To run the program an example command would be "./oss -n 10 -s 5 -t 2" 

-n means number of children to run
-s means how many simultaneous children can run at the same time
-t means how many iterations of a sleep/wake cycle will these children run

There should also be a user.exe file to run as well if you want to run a single child process.
To use the user.exe an example command would be "./user 5"

If running these programs with the executable the sample command will work just remove ./oss and ./user

[!!CURRENT PROBLEMS!!]

[After the first iterations run on the child processes the PPID of the parent process will read 0]






