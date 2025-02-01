#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    
    if (argc == 1 || (argc == 2 && strcmp(argv[1], "-h") == 0))
    {
        printf("Usage: %s <filename> <number1> <number2> ... <numberN>\n", argv[0]);
        printf("Option: -h\tPrints this help message.\n");
        return 0;
    }
}