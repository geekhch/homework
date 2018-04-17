#include <stdio.h>
#include <signal.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <sys/termios.h>

int main()
{
  int cpid;
  int ppid;
  char buf[256];
  
  ppid=getpid();
  cpid=fork();
  
  if (cpid<0)
    exit(-1);
    
  if (!cpid)
  {
    printf("ID(child)=%d\n",getpid());
    
    setpgid(0,0);
    tcsetpgrp(0,getpid());
    execl("/bin/vi","vi",NULL);
    exit(-1);
  }
   
  printf("ID(parent)=%d\n",ppid);
  setpgid(cpid,cpid);
  tcsetpgrp(0,cpid);
  waitpid(cpid,NULL,0);
  tcsetpgrp(0,ppid);

  while(1)
  {
    memset(buf, 0, 256);
    fgets(buf, 256, stdin);
    puts("ECHO: ");
    puts(buf);
    puts("\n");
  }
}
