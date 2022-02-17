#include "philo_bonus.h"

void	efun(void)
{
	sem_wait(g_sem_frks);
	gettime_lock(&g_cur_tv);
	printf_lock(abs_time(g_cur_tv), g_ph_strct.ph_index, "has taken a fork");
	sem_wait(g_sem_frks);
	gettime_lock(&(g_ph_strct.et));
	printf_lock(abs_time(g_ph_strct.et),
		g_ph_strct.ph_index, "has taken a fork");
	printf_lock(abs_time(g_ph_strct.et), g_ph_strct.ph_index, "is eating");
	my_usleep(g_prm->etime * 1000, g_ph_strct.et);
	(g_ph_strct.meal_num)++;
	if (g_ph_strct.meal_num == g_prm->ml_num)
		sem_post(g_sem_ml_num);
	sem_post(g_sem_frks);
	sem_post(g_sem_frks);
}

void	sfun(void)
{
	gettime_lock(&g_cur_tv);
	printf_lock(abs_time(g_cur_tv), g_ph_strct.ph_index, "is sleeping");
	my_usleep(g_prm->stime * 1000, g_cur_tv);
}

static void	*handler2(void)
{
	while (1)
	{
		if (g_alive)
			efun();
		else
			break ;
		if (g_ph_strct.meal_num == g_prm->ml_num)
			break ;
		if (g_alive)
			sfun();
		else
			break ;
		gettime_lock(&g_cur_tv);
		if (g_alive)
			printf_lock(abs_time(g_cur_tv), g_ph_strct.ph_index, "is thinking");
		else
			break ;
	}
	return (0);
}

void	*handler1(int ph_index)
{
	pthread_t	ch_death_thrd;

	g_alive = 1;
	gettime_lock(&g_cur_tv);
	init_ph_struct(ph_index);
	thrd_crt_error(pthread_create(&ch_death_thrd, 0, &ch_death_hand, 0));
	if (g_prm->ph_num > 1)
		handler2();
	else
	{
		while (g_alive)
		{
		}
	}
	join_thrd(ch_death_thrd);
	return (0);
}
