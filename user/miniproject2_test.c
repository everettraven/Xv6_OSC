#include "types.h"
#include "user.h"
#include "stat.h"


// This file is meant to be used as a program to test the changes made to Xv6 for miniproject 1

int main(int argc, char *argv[])
{
    int child1 = 1, child2 = 1;

    int parent_pid = getpid();

    printf(1, "Child 1 PID: %d\nChild 2 PID: %d\n", parent_pid + 1, parent_pid + 2);
    // Create two children to run the same task, but change their ticket counts
    child1 = fork();
    if (child1 > 0)
    {
        child2 = fork();
    }

    if(child1 == 0 && child2 > 0)
    {
        int i;
        int pid = getpid();
        changetickets(pid, 10);
        for(i = 0; i < 10; i++)
        {
            printf(1, "%d\n", getpid());
            // printf(1,"%d\n", i);
        }
    }
    else if(child1 > 0 && child2 == 0)
    {
        int j;
        int pid = getpid();
        changetickets(pid, 1000);
        for(j = 10; j < 20; j++)
        {
            printf(1, "%d\n", getpid());
            // printf(1,"%d\n", j);
        }
    }

    else{
        wait();
        wait();
        exit();
    }

}