#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int proc;
    int simul;
    int completedChilds = 0;
    int runningChilds = 0;
    int status;
    char *iter = NULL;
    
    // Help Argument and how to use.
    if (argc < 3 || (argc == 2 && strcmp(argv[1], "-h") == 0))
    {
        printf("Usage: %s [-h] [-n <number>] [-s <number>] [-t <number>]", argv[0]);
        printf("Option: -h  \tPrints this help message.\n");
        return 0;
    }

    // Command line arguments and parsing them for input.
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-n") == 0)
        {
            proc = atoi(argv[++i]);
        }
        else if (strcmp(argv[i], "-s") == 0)
        {
            simul = atoi(argv[++i]);
        }
        else if (strcmp(argv[i], "-t") == 0)
        {
            iter = argv[++i];
        }
    }

    // Loop to check for how many children have run.
    while (completedChilds < proc)
    {
        //printf("running childs: %d", runningChilds);
        // Loop to Check for how many children are currently running.
        while (runningChilds < simul && (completedChilds + runningChilds) < proc)
        {
            pid_t childPid = fork();
            if (childPid == 0)
            {
                char *args[] = {"./user", iter, NULL};
                execvp(args[0], args);
            }
            else
            {
                runningChilds++;
            }
        }
    }
    // Waiting for children to finish
    pid_t finishedPid = wait(&status);
    if (finishedPid > 0)
    {
        completedChilds++;
        runningChilds--;
    }

    return EXIT_SUCCESS;
}
