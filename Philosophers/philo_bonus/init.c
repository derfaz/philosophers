#include "philo_bonus.h"

void	init_ph_struct(int ph_index)
{
	g_ph_strct.ph_index = ph_index;
	g_ph_strct.meal_num = 0;
	gettimeofday(&(g_ph_strct.et), &g_tz);
}

void	init_philo2(t_list	*pid_lst, pthread_t t1, pthread_t t2)
{
	t_list	*tmp;

	tmp = pid_lst;
	while (tmp)
	{
		waitpid(tmp->data, 0, 0);
		tmp = tmp->next;
	}
	join_thrd(t2);
	join_thrd(t1);
}

void	init_philo(void)
{
	t_list		*pid_lst;
	pid_t		pid;
	int			ph_index;
	pthread_t	main_death_thrd;
	pthread_t	main_death_thrd2;

	pid_lst = 0;
	ph_index = 1;
	thrd_crt_error(pthread_create(&main_death_thrd2, 0, &main_death_hand2, 0));
	while (ph_index <= g_prm->ph_num)
	{
		pid = fork();
		if (ph_index == 1)
			gettimeofday(&g_start_tv, &g_tz);
		is_pid_error(pid);
		if (!pid)
			handler1(ph_index);
		else
			pid_lst = ft_add_bottom_elem(pid_lst, pid);
		ph_index ++;
	}
	thrd_crt_error(pthread_create(&main_death_thrd, 0,
			&main_death_hand, (void *)pid_lst));
	init_philo2(pid_lst, main_death_thrd, main_death_thrd2);
}

void	join_thrd(pthread_t	death_thrd)
{
	if (pthread_join(death_thrd, NULL) != 0)
		printf("pthread not_joined\n");
}

void	init_params(char **argv)
{
	g_prm = (t_prm *)malloc(sizeof(t_prm));
	merror((void *) g_prm);
	g_prm->ph_num = ft_atoi(argv[0]);
	g_prm->dtime = ft_atoi(argv[1]);
	g_prm->etime = ft_atoi(argv[2]);
	g_prm->stime = ft_atoi(argv[3]);
	if (argv[4])
		g_prm->ml_num = ft_atoi(argv[4]);
	else
		g_prm->ml_num = -1;
	init_sem();
	init_philo();
	sem_close(g_sem_frks);
	sem_close(g_sem_philos);
	sem_close(g_sem_kill_ch);
	sem_close(g_sem_gettime);
	sem_close(g_sem_print);
	sem_close(g_sem_ml_num);
	free_all();
}
