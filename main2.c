// main2.c
#include  <stdio.h>
#include  <sys/types.h>

#define   MAX_COUNT  200

void  ChildProcess(int);                /* child process prototype  */
void  ParentProcess(int);               /* parent process prototype */

void  main(void)
{
     pid_t  pid;

     pid = fork();
  
     if (pid == 0) 
          ChildProcess(pid);
     else 
          ParentProcess(pid);
}

void  ChildProcess(int id)
{
     int   i;
     printf("CHILD has %d\n",id);
     for (i = 1; i <= MAX_COUNT; i++)
          printf("   This line is from child, value = %d\n", i);
     printf("   *** Child process is done ***\n");
}

void  ParentProcess(int id)
{
     int   i;
     printf("PARENT has %d\n", id);
     for (i = 1; i <= MAX_COUNT; i++)
          printf("This line is from parent, value = %d\n", i);
     printf("*** Parent is done ***\n");
}