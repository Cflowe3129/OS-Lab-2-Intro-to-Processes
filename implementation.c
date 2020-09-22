// main2.c
#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>
#include<time.h> 
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


void  ChildProcess(int);                /* child process prototype  */
void  ChildProcessTwo(int);                /* child process prototype  */
void  ParentProcess(int);               /* parent process prototype */
pid_t getpid(void);
pid_t getppid(void);


void  main(void)
{

  
    pid_t  pid;
    pid_t getpid;
    pid = fork();



    if (pid > 0) {
      pid = fork();
    }
      
      
    if(pid == 0) 
    { 
          ChildProcess(pid);
    } 
    else {     
      ParentProcess(pid);
    }
   
    
     
  
   
          
}

void  ChildProcess(int id)
{
     pid_t  ppid;
     pid_t  pid;
     pid_t  newPid;
  
     ppid = getppid();
     pid = getpid();

     time_t t;
     srandom((unsigned) time(&t));
        
        int   i;
        for (i = 1; i <= random() % 30; i++) {
          printf("   Child Pid: <%d> is going to sleep.\n",pid);
          sleep(random() % 10);
          printf("   Child Pid: is awake!     Where is my parent:<%d>\n",ppid);
        }
        exit(0);
     
}

void  ParentProcess(int id)
{
    
     int status;
     int waitID;
     while ((waitID = wait(&status)) > 0) {
        printf("Child Pid: <%d> has completed.\n", waitID);
     }

     printf("*** Parent is done ***\n");
     

     
}