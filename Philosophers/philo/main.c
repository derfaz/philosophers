#include "philo.h"

int	check_args(int argc, char **argv)
{
	int		i;
	char	*max;

	if (argc != 4 && argc != 5)
		return (0);
	i = 0;
	max = ft_itoa(INT_MAX);
	while (argv && argv[i])
	{
		if (!check_atoi_input(argv[i], max) || ft_atoi(argv[i]) <= 0)
		{
			printf("arg_error_details:\n");
			printf("argv[%d] = %s\n", i, argv[i]);
			free(max);
			return (0);
		}
		i++;
	}
	free(max);
	return (1);
}

void	merror(void*p)
{
	if (!p)
	{
		printf("malloc_error\n");
		exit(-1);
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

void	mutex_init_error(int mutex_init_res)
{
	if (mutex_init_res)
	{
		printf("mutex not_created\n");
		exit (mutex_init_res);
	}
}

int	main(int argc, char **argv)
{
	g_alive = 1;
	gettimeofday(&g_start_tv, &g_tz);
	if (!check_args(argc - 1, argv + 1))
	{
		printf("args error\n");
		exit(0);
	}
	g_death_prnt = 0;
	init_params(argv + 1);
}
