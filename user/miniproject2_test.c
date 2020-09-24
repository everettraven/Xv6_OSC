#include "types.h"
#include "user.h"
#include "stat.h"


// This file is meant to be used as a program to test the changes made to Xv6 for miniproject 1

int main(int argc, char *argv[])
{
    int child1 = 1, child2 = 1;
   // Create two children to run the same task, but change their ticket counts
   child1 = fork();
   if (child1 > 0)
   {
        child2 = fork();
   }

   if(child1 < 0 && child2 > 0)
   {
        int i = 0;
        int pid = getpid();
        changetickets(pid, 3);
        for(i; i < 10; i++)
        {
            printf(1,"I am child1 printing: %d", i);
        }
   }
   else if(child1 > 0 && child2 < 0)
   {
        int i = 0;
        int pid = getpid();
        changetickets(pid, 100);
        for(i; i < 10; i++)
        {
            printf(1,"I am child2 printing: %d", i);
        }
   }

    exit();
}