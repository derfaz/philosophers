#include "philo.h"

static void	free_arr(void **arr, int len)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (i < len)
		{
			if (arr[i])
				free(arr[i]);
			i++;
		}
		free(arr);
	}
}

void	free_thrd(t_ph **g_ph_arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if ((g_ph_arr[i])->thrd)
			free((g_ph_arr[i])->thrd);
		i++;
	}
}

void	free_all(void)
{
	free_arr((void **)g_frk_arr, g_prm->ph_num);
	free_arr((void **)g_hand_prm_arr, g_prm->ph_num);
	free_thrd(g_ph_arr, g_prm->ph_num);
	free_arr((void **)g_ph_arr, g_prm->ph_num);
	if (g_prm)
		free(g_prm);
	free(g_gettime_mutex);
	free(g_printf_mutex);
}
