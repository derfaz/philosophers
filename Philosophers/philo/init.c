#include "philo.h"

void	init_ph_struct(t_ph	**ph_str)
{
	*ph_str = (t_ph *)malloc(sizeof(t_ph));
	merror((void *)ph_str);
	(*ph_str)->meal_num = 0;
	gettimeofday(&((*ph_str)->et), &g_tz);
	(*ph_str)->thrd = (pthread_t *)malloc(sizeof(pthread_t));
}

void	init_hand_prm(t_hnd_prm **hprm, int frst)
{
	*hprm = (t_hnd_prm *) malloc(sizeof (t_hnd_prm));
	(*hprm)->first = frst;
	if (g_prm->ph_num - 1 > frst)
		(*hprm)->second = frst + 1;
	else
		(*hprm)->second = 0;
}

void	init_philo(void)
{
	int	i;

	g_ph_arr = (t_ph **) ft_calloc(g_prm->ph_num, sizeof(t_ph *));
	g_hand_prm_arr = (t_hnd_prm **) malloc(sizeof(t_hnd_prm *) * g_prm->ph_num);
	merror((void *) g_ph_arr);
	merror((void *) g_hand_prm_arr);
	i = 0;
	while (i < g_prm->ph_num)
	{
		init_ph_struct(&(g_ph_arr[i]));
		init_hand_prm(&(g_hand_prm_arr[i]), i);
		if (i % 2)
		{
			gettimeofday(&g_cur_tv, &g_tz);
			my_usleep(g_prm->etime / 2, g_cur_tv);
		}
		thrd_crt_error(pthread_create
			((g_ph_arr[i])->thrd, 0, &handler1, g_hand_prm_arr[i]));
		i ++;
	}
}

void	join_thrd(pthread_t	death_thrd)
{
	int	i;

	i = 0;
	if (pthread_join(death_thrd, NULL) != 0)
		printf("death_pthread not_joined\n");
	while (i < g_prm->ph_num)
	{
		if (pthread_join(*((g_ph_arr[i])->thrd), NULL) != 0)
			printf("pthread not_joined\n");
		i++;
	}
}

void	init_params(char **argv)
{
	pthread_t	death_thrd;

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
	init_mutexes();
	thrd_crt_error(pthread_create(&death_thrd, 0, &death_hand, 0));
	init_philo();
	join_thrd(death_thrd);
	free_all();
}
