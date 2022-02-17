#include "philo.h"

void	*death_hand(void *arg)
{
	int	i;

	(void)arg;
	while (g_alive)
	{
		gettime_lock(&g_cur_tv);
		my_usleep(30, g_cur_tv);
		if (check_mealnum())
			break ;
		gettime_lock(&g_cur_tv);
		i = 0;
		while (i < g_prm->ph_num)
		{
			if (ph_time(g_cur_tv, i) > g_prm->dtime)
			{
				g_alive = 0;
				printf_lock(abs_time(g_cur_tv), i, "died");
				break ;
			}
			i++;
		}
	}
	return (0);
}

void	gettime_lock(struct timeval *curtime)
{
	pthread_mutex_lock(g_gettime_mutex);
	gettimeofday(curtime, &g_tz);
	pthread_mutex_unlock(g_gettime_mutex);
}

void	printf_lock(int time, int ph_index, char *str)
{
	ph_index++;
	pthread_mutex_lock(g_printf_mutex);
	if (!g_death_prnt)
	{
		if (! g_alive)
		{
			printf("%d %d died\n", time, ph_index);
			g_death_prnt = 1;
			exit (0);
		}
		else
			printf("%d %d %s\n", time, ph_index, str);
	}
	pthread_mutex_unlock(g_printf_mutex);
}
