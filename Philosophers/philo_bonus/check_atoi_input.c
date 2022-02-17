#include "philo_bonus.h"

int	is_num(char *str)
{
	if (str[0] != '-' && !ft_isdigit(str[0]))
		return (0);
	str++;
	while (str && *str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	check_atoi_input2(char *arg, char *max, int sign)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	if (ft_strlen(arg) == ft_strlen(max))
	{
		while (*arg)
		{
			if (*arg > *max && *(arg + 1))
				return (0);
			if (!*(arg + 1) && ((!sign && *arg > '7') || (sign && *arg > '8')))
				return (0);
			arg++;
			max++;
		}
	}
	return (1);
}

int	check_atoi_input(char *arg, char *max)
{
	int	sign;

	sign = 0;
	if (*arg == '-')
	{
		sign = -1;
		arg++;
	}
	while (*arg == '0')
		arg++;
	if (!*arg)
		return (1);
	return (check_atoi_input2(arg, max, sign));
}
