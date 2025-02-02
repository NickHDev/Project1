#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t PPID = getppid();
    int iterations = atoi(argv[1]);

    for (int i = 0; i < iterations; i++)
    {
        printf("\nUSER PID: %d PPID: %d Iteration: %d before sleeping\n", getpid(), PPID, i + 1);
        sleep(1);
        printf("USER PID: %d PPID: %d Iteration: %d after sleeping\n", getpid(), PPID, i + 1);
    }
    return EXIT_SUCCESS;
}
