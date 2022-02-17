#include "philo.h"

void	efun(int first, int second)
{
	pthread_mutex_lock(g_frk_arr[first]);
	gettime_lock(&g_cur_tv);
	printf_lock(abs_time(g_cur_tv), first, "has taken a fork");
	pthread_mutex_lock(g_frk_arr[second]);
	gettime_lock(&((g_ph_arr[first])->et));
	printf_lock(abs_time((g_ph_arr[first])->et), first, "has taken a fork");
	printf_lock(abs_time((g_ph_arr[first])->et), first, "is eating");
	my_usleep(g_prm->etime * 1000, (g_ph_arr[first])->et);
	(g_ph_arr[first])->meal_num++;
	pthread_mutex_unlock(g_frk_arr[second]);
	pthread_mutex_unlock(g_frk_arr[first]);
}

void	sfun(int ph_index)
{
	gettime_lock(&g_cur_tv);
	printf_lock(abs_time(g_cur_tv), ph_index, "is sleeping");
	my_usleep(g_prm->stime * 1000, g_cur_tv);
}

int	check_mealnum(void)
{
	int	i;
	int	num_max_meals;

	i = 0;
	num_max_meals = 0;
	while (i < g_prm->ph_num)
	{
		if ((g_ph_arr[i]) && (g_ph_arr[i])->meal_num == g_prm->ml_num)
			num_max_meals++;
		i++;
	}
	if (num_max_meals == g_prm->ph_num)
		return (1);
	else
		return (0);
}

static void	*handler2(t_hnd_prm	*param)
{
	while (1)
	{
		if (g_alive)
			efun(param->first, param->second);
		else
			break ;
		if ((g_ph_arr[param->first])->meal_num == g_prm->ml_num)
			break ;
		if (g_alive)
			sfun(param->first);
		else
			break ;
		gettime_lock(&g_cur_tv);
		if (g_alive)
			printf("%d %d is thinking\n", abs_time(g_cur_tv), param->first + 1);
		else
			break ;
	}
	return (0);
}

void	*handler1(void *arg)
{
	t_hnd_prm	*param;

	param = arg;
	handler2(param);
	return (0);
}
