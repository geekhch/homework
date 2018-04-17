#include <string.h>
#include <stdio.h>
#include <errno.h>

int main(int argc,char*argv[])
{
  int pid;
  char *prog_argv[4];

  prog_argv[0]="/bin/ls";
  prog_argv[1]="-l";
  prog_argv[2]="/";
  prog_argv[3]=NULL;

  if ((pid=fork())<0)
  {
    perror("Fork failed");
    exit(errno);
  }

  if (!pid)
  {
    execvp(prog_argv[0],prog_argv);
  }

  if (pid)
  {
    waitpid(pid,NULL,0);
  }
}
