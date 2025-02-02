#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t childPid = fork();
    if (argc == 1 || (argc == 2 && strcmp(argv[1], "-h") == 0))
    {
        printf("Usage: %s [-h] [-n <number>] [-s <number>] [-t <number>]", argv[0]);
        printf("Option: -h\tPrints this help message.\n");
        return 0;
    }

    if (childPid == 0)
    {
        char *args[] = {"./user", argv[1], NULL};
        execvp(args[0], args);
    }
    else
    {
        wait(NULL);
        printf("Parent Process. My PID is: %d My Child PID is: %d\n", getpid(), childPid);
        return EXIT_SUCCESS;
    }

    int status = -1;
    waitpid(childPid, &status, WEXITED);

    return EXIT_SUCCESS;
}
