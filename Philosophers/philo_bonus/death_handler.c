#include "philo_bonus.h"

void	*ch_death_hand(void *arg)
{
	(void)arg;
	while (g_alive)
	{
		gettime_lock(&g_cur_tv);
		my_usleep(30, g_cur_tv);
		gettime_lock(&g_cur_tv);
		if (ph_time(g_cur_tv) > g_prm->dtime)
		{
			g_alive = 0;
			if (g_prm->ph_num != 1)
				sem_post(g_sem_kill_ch);
			printf_lock(abs_time(g_cur_tv), g_ph_strct.ph_index, "died");
			my_usleep(10, g_cur_tv);
			break ;
		}
	}
	return (0);
}

void	*main_death_hand2(void *arg)
{
	int	i;

	(void)arg;
	i = 0;
	if (g_prm->ph_num > 1 && g_prm->ml_num != -1)
	{
		while (i < g_prm->ph_num)
		{
			sem_wait(g_sem_ml_num);
			i++;
		}
		sem_post(g_sem_kill_ch);
	}
	return (0);
}

void	*main_death_hand(void *arg)
{
	t_list	*pid_lst;

	pid_lst = arg;
	sem_wait(g_sem_kill_ch);
	while (pid_lst)
	{
		kill(pid_lst->data, SIGKILL);
		pid_lst = pid_lst->next;
	}
	exit(0);
	return (0);
}

void	gettime_lock(struct timeval *curtime)
{
	sem_wait(g_sem_gettime);
	gettimeofday(curtime, &g_tz);
	sem_post(g_sem_gettime);
}

void	printf_lock(int time, int ph_index, char *str)
{
	sem_wait(g_sem_print);
	if (!g_alive)
	{
		printf("%d %d died\n", time, ph_index);
		sem_post(g_sem_kill_ch);
	}
	else
	{
		printf("%d %d %s\n", time, ph_index, str);
		sem_post(g_sem_print);
	}
}
