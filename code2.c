#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>
void forexample()
{
if(fork()==0)
printf("hello from child!\n");
else
printf("hello from parent!\n");
}
int main()
{
forexample();
pid_t pid;
int status;
char *argv_list[]={"%s",NULL};
pid=fork();
if(pid==-1)
{
printf("can't fork,error occured\n");
exit(EXIT_FAILURE);
}
else if(pid==0)
{
printf("child process,pid=%u\n",getpid());
execv("%s",argv_list);
exit(0);
}
else
{
printf("parent process pid=%u\n",getpid());
if(waitpid(pid,&status,0)>0)
{
if(WIFEXITED(status) &&! WEXITSTATUS(status))
printf("program execution successful\n");
else if(WIFEXITED(status) && WEXITSTATUS(status))
{
if(WEXITSTATUS(status)==127)
{
printf("execv faliled\n");
}
else
printf("program terminated successfully,but returned a non-zero status\n");
}
else
printf("program didn't terminate normally\n");
}
else
{
printf("waitpid() failed\n");
}
exit(0);
}
pid_t cpid;
if(fork()==0)
exit(0);
else
cpid=wait(NULL);
printf("parent pid=%d\n",getpid());
printf("child pid=%d\n",cpid);
printf("START");
exit(0);
printf("end of program");
return 0;
}
forexample()
{
if(fork()==0)
printf("hello from child!\n");
else
printf("hello from parent!\n");
}
int main()
{
forexample();
pid_t pid;
int status;
char *argv_list[]={"%s",NULL};
pid=fork();
if(pid==-1)
{
printf("can't fork,error occured\n");
exit(EXIT_FAILURE);
}
else if(pid==0)
{
printf("child process,pid=%u\n",getpid());
execv("%s",argv_list);
exit(0);
}
else
{
printf("parent process pid=%u\n",getpid());
if(waitpid(pid,&status,0)>0)
{
if(WIFEXITED(status) &&! WEXITSTATUS(status))
printf("program execution successful\n");
else if(WIFEXITED(status) && WEXITSTATUS(status))
{
if(WEXITSTATUS(status)==127)
{
printf("execv faliled\n");
}
else
printf("program terminated successfully,but returned a non-zero status\n");
}
else
printf("program didn't terminate normally\n");
}
else
{
printf("waitpid() failed\n");
}
exit(0);
}
pid_t cpid;
if(fork()==0)
exit(0);
else
cpid=wait(NULL);
printf("parent pid =%d\n",getpid());
printf("child pid =%d\n",cpid);
printf("START");
exit(0);
printf("End of program");
return 0;
}
