#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_prm
{
	int			ph_num;
	int			dtime;
	int			etime;
	int			stime;
	int			ml_num;
}				t_prm;

typedef struct s_ph
{
	int				meal_num;
	struct timeval	et;
	pthread_t		*thrd;
}				t_ph;

typedef struct s_hnd_prm
{
	int				first;
	int				second;
}				t_hnd_prm;

struct timeval	g_start_tv;
struct timeval	g_cur_tv;
struct timezone	g_tz;
t_prm			*g_prm;
pthread_mutex_t	**g_frk_arr;
pthread_mutex_t	*g_gettime_mutex;
pthread_mutex_t	*g_printf_mutex;
t_ph			**g_ph_arr;
t_hnd_prm		**g_hand_prm_arr;
int				g_alive;
int				g_death_prnt;

/* libft */
int		check_atoi_input(char *arg, char *max);
long	ft_atoi(const char *str);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
void	*ft_calloc(size_t count, size_t size);

/* philo */
int		main(int argc, char **argv);
void	merror(void*p);
void	mutex_init_error(int mutex_init_res);
void	thrd_crt_error(int ernum);
void	init_params(char **argv);
void	init_mutexes(void);
void	*handler1(void *arg);
void	free_all(void);
void	*death_hand(void *arg);
int		abs_time(struct timeval cur);
int		ph_time(struct timeval cur, int ph_index);
void	my_usleep(int len_in_us, struct timeval	start);
int		check_mealnum(void);
void	gettime_lock(struct timeval *curtime);
void	printf_lock(int time, int ph_index, char *str);

#endif
