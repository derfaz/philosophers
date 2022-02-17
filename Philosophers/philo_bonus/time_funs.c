#include "philo_bonus.h"

int	abs_time(struct timeval cur)
{
	return ((cur.tv_sec - g_start_tv.tv_sec) * 1000
		+ (cur.tv_usec - g_start_tv.tv_usec) / 1000);
}

int	ph_time(struct timeval cur)
{
	return ((cur.tv_sec - g_ph_strct.et.tv_sec) * 1000
		+ (cur.tv_usec - g_ph_strct.et.tv_usec) / 1000);
}

void	my_usleep(int len_in_ms, struct timeval	start)
{
	struct timeval	now;

	gettimeofday(&now, &g_tz);
	while ((now.tv_usec - start.tv_usec)
		+ (now.tv_sec - start.tv_sec) * 1000000 < len_in_ms)
	{
		usleep(30);
		gettimeofday(&now, &g_tz);
	}
}
