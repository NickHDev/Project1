/*
Author: Nicholas Hieb
Date: 02/01/2025
This File is the main file to be executed and runs child processes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int proc = 1;
    int simul = 1;
    char *iter = NULL;
    int completedChilds = 0;
    int runningChilds = 0;
    int status;
    int opt;

    // Command line arguments and parsing them for input.
    while ((opt = getopt(argc, argv, "hn:s:t:")) != -1)
    {
        switch (opt)
        {
        case 'n':
            proc = atoi(optarg);
            break;
        case 's':
            simul = atoi(optarg);
            break;
        case 't':
            iter = optarg;
            break;
        case 'h':
        default:
            printf("Usage: %s [-h] -n <number> -s <number> -t <number>\n", argv[0]);
            printf("Options:\n");
            printf("  -h\tPrints this help message.\n");
            printf("  -n\tTotal number of processes to create.\n");
            printf("  -s\tMaximum number of simultaneous processes.\n");
            printf("  -t\tArgument to pass to the child process.\n");
            return 0;
        }
    }

    // Loop to check for how many children have run.
    for (completedChilds = 0; completedChilds < proc;)
    {
        // Loop for running simultanious children.
        for (int i = 0; i < simul && completedChilds < proc; i++)
        {
            pid_t childPid = fork();
            if (childPid == 0)
            {
                char *args[] = {"./user", iter, NULL};
                execvp(args[0], args);
            }
            else if (childPid > 0)
            {
                completedChilds++;
            }
            else
            {
                perror("Fork Failed");
                EXIT_FAILURE;
            }
        }
        wait(NULL);// Waiting for children to finish
    }
    
    return EXIT_SUCCESS;
}
