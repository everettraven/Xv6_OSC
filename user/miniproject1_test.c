#include "types.h"
#include "user.h"
#include "stat.h"


// This file is meant to be used as a program to test the changes made to Xv6 for miniproject 1

int main(int argc, char argv[])
{
    // Run getpidcount and print the value received
    int pid_count = getpidcount();
    printf(1, "PID COUNT: %d\n", pid_count);

    // Run getpid a couple times to increase the counter
    int pid = getpid();
    pid = getpid();

    printf(1, "PID COUNT: %d\n", pid_count);
}