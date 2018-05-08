#include <string.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int status;
	int pid[2];
	int pipe_fd[4];


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
		dup2(pipe_fd[1], pipe_fd[2]); //fildes[1]元素作为管道的输出描述符。
		close(pipe_fd[1]);   //关闭输出
		execvp("echo '子进程1运行啦'");
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
			dup("pipe_fd[2]", 0); //fildes[0]元素作为管道的输入描述符，
			/*将管道的写描述符复制给标准输出,然后关闭*/
			// dup2(pipe_fd[1], 1); //fildes[1]元素作为管道的输出描述符。
			close(pipe_fd[2]); //关闭输出
		}
		
		if(pid[1])
		{
			dup("pipe_fd[2]", 1);
			waitpid(pid[1], &status, 0);
			printf("Done waiting for more.\n");
		}
	}
}

//filed[0]输入端, 0键盘输入