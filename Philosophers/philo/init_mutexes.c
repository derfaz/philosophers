#include "philo.h"

void	init_mutexes(void)
{
	int	i;

	g_frk_arr = (pthread_mutex_t **)malloc \
			(sizeof(pthread_mutex_t *) * g_prm->ph_num);
	i = 0;
	while (i < g_prm->ph_num)
	{
		g_frk_arr[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		merror((void *)g_frk_arr[i]);
		mutex_init_error(pthread_mutex_init(g_frk_arr[i], 0));
		i++;
	}
	g_gettime_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	merror((void *)g_gettime_mutex);
	mutex_init_error(pthread_mutex_init(g_gettime_mutex, 0));
	g_printf_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	merror((void *)g_printf_mutex);
	mutex_init_error(pthread_mutex_init(g_printf_mutex, 0));
}
