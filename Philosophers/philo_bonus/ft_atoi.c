#include "philo_bonus.h"

static long	num_print(const char *str, int i, int minusnum)
{
	long	num;

	num = 0;
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		num = num * 10 + (*(str + i) - 48);
		i++;
	}
	if ((minusnum % 2) == 0)
		return (num);
	else
		return (0 - num);
}

long	ft_atoi(const char *str)
{
	int	i;
	int	minusnum;

	i = 0;
	minusnum = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minusnum = minusnum + 1;
		i++;
	}
	if (*(str + i) >= '0' && *(str + i) <= '9')
		return (num_print(str, i, minusnum));
	else
		return (0);
}
