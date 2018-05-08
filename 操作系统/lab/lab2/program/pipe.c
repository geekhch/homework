#include <string.h>
#include <stdio.h>
#include <errno.h>


int main(int argc, char *argv[])
{
  int status;
  int pid[2];
  int pipe_fd[2];
  
  char *prog1_argv[4];
  char *prog2_argv[2];
  
  prog1_argv[0]="/bin/ls";
  prog1_argv[1]="-l";
  prog1_argv[2]="/etc/";
  prog1_argv[3]=NULL;
  
  prog2_argv[0]="/bin/more";
  prog2_argv[1]=NULL;

  if (pipe(pipe_fd)<0)
  {  
    perror("pipe failed");
    exit(errno);
  }
  
  if ((pid[0]=fork())<0)
  {
    perror("Fork failed");
    exit(errno);
  }
  if (!pid[0]) //子进程1
  {
    close(pipe_fd[0]); //fildes[0]元素作为管道的输入描述符，
    /*将管道的写描述符复制给标准输出,然后关闭*/
    dup2(pipe_fd[1], 1); //fildes[1]元素作为管道的输出描述符。
    close(pipe_fd[1]);   //关闭输出
    execvp(prog1_argv[0], prog1_argv);
  }
  
  if (pid[0]) //父进程
  {
    if ((pid[1]=fork())<0)
    {
      perror("Fork failed");
      exit(errno);
    }
    if (!pid[1]) //父进程
    {
      close(pipe_fd[1]);
      dup2(pipe_fd[0],0); 
      close(pipe_fd[0]);   
      
      execvp(prog2_argv[0],prog2_argv);
    }
    
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    waitpid(pid[1],&status,0);
    printf("Done waiting for more.\n");
  }  
}

//filed[0]输入端, 0键盘输入