#include "philo_bonus.h"

void	merror(void*p)
{
	if (!p)
	{
		printf("malloc_error\n");
		exit(-1);
	}
}

void	semerror(sem_t *sm)
{
	if (!sm)
	{
		printf("semaphore_crt_error\n");
		exit(-1);
	}
}

void	is_pid_error(pid_t pid)
{
	if (pid == -1)
	{
		printf("fork_error");
		exit (-1);
	}
}

void	thrd_crt_error(int ernum)
{
	if (ernum)
	{
		printf("thrd_crt_error\n");
		exit(ernum);
	}
}
