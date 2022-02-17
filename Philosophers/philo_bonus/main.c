#include "philo_bonus.h"

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

int	main(int argc, char **argv)
{
	g_alive = 1;
	if (!check_args(argc - 1, argv + 1))
	{
		printf("args error\n");
		exit(0);
	}
	init_params(argv + 1);
}
