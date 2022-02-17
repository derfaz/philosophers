#include "philo_bonus.h"

void	init_sem(void)
{
	sem_unlink("frks");
	g_sem_frks = sem_open("frks", O_CREAT, 0660, g_prm->ph_num);
	semerror(g_sem_frks);
	sem_unlink("philos");
	g_sem_philos = sem_open("philos", O_CREAT, 0660, g_prm->ph_num - 1);
	semerror(g_sem_philos);
	sem_unlink("sem_kill_ch");
	g_sem_kill_ch = sem_open("sem_kill_ch", O_CREAT, 0660, 0);
	semerror(g_sem_kill_ch);
	sem_unlink("sem_gettime");
	g_sem_gettime = sem_open("sem_gettime", O_CREAT, 0660, 1);
	semerror(g_sem_gettime);
	sem_unlink("sem_print");
	g_sem_print = sem_open("sem_print", O_CREAT, 0660, 1);
	semerror(g_sem_print);
	if (g_prm->ml_num != -1)
	{
		sem_unlink("sem_ml_num");
		g_sem_ml_num = sem_open("sem_ml_num", O_CREAT, 0660, 0 );
		semerror(g_sem_ml_num);
	}
}
