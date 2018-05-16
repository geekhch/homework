#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int status;
	int pid[2];
	int pipe_fd[2];
	int f = open("test.txt", O_APPEND|O_RDWR);
	
	char *prog1_argv[4];

	prog1_argv[0] = "/bin/echo";
	prog1_argv[1] = "'fdd'";
	prog1_argv[2] = ">";
	prog1_argv[3] = "test.txt";

	if (pipe(pipe_fd) < 0)  //创建管道
	{
		perror("pipe failed");
		exit(errno);
	}
	if ((pid[0] = fork()) < 0) //child 1
	{
		perror("Fork 1 failed");
		exit(errno);
	}

	if (!pid[0]) //子进程1
	{
		close(pipe_fd[0]); //fildes[0]元素作为管道的输入描述符，
		/*将管道的写描述符复制给标准输出,然后关闭*/
		dup2(pipe_fd[1], f); //fildes[1]元素作为管道的输出描述符。
		close(pipe_fd[1]);   //关闭输出
		printf("%d文件",f);
		write(f, prog1_argv, 2);
		execvp(prog1_argv[0], prog1_argv);
	}

	if (pid[0]) //父进程
	{
		if ((pid[1] = fork()) < 0)
		{
			perror("Fork failed");
			exit(errno);
		}

		if (!pid[1]) //子进程2
		{
			waitpid(pid[0], &status, 0);
			dup2(pipe_fd[0], pipe_fd[1]); //fildes[0]元素作为管道的输入描述符
			close(pipe_fd[0]); //关闭输出
		}
		
		if(pid[1])
		{
			dup2("pipe_fd[2]", 1);
			waitpid(pid[1], &status, 0);
			printf("Done waiting for more.\n");
		}
	}
}

//filed[0]输入端, 0键盘输入