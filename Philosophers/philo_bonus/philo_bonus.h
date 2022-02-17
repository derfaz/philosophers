#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

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
	int				ph_index;
}				t_ph;

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}				t_list;

t_ph			g_ph_strct;
struct timeval	g_start_tv;
struct timeval	g_cur_tv;
struct timezone	g_tz;
t_prm			*g_prm;
sem_t			*g_sem_frks;
sem_t			*g_sem_philos;
sem_t			*g_sem_kill_ch;
sem_t			*g_sem_gettime;
sem_t			*g_sem_print;
sem_t			*g_sem_ml_num;
int				g_alive;

/* libft */
int		check_atoi_input(char *arg, char *max);
long	ft_atoi(const char *str);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
void	*ft_calloc(size_t count, size_t size);

/* philo */
int		main(int argc, char **argv);
void	thrd_crt_error(int ernum);
void	merror(void*p);
void	semerror(sem_t *sm);
void	is_pid_error(pid_t pid);
void	join_thrd(pthread_t	death_thrd);
void	init_params(char **argv);
void	init_sem(void);
void	init_ph_struct(int ph_index);
void	*handler1(int ph_index);
void	free_all(void);
void	*ch_death_hand(void *arg);
void	*main_death_hand(void *arg);
void	*main_death_hand2(void *arg);
int		abs_time(struct timeval cur);
int		ph_time(struct timeval cur);
void	my_usleep(int len_in_ms, struct timeval	start);
int		check_mealnum(void);
void	gettime_lock(struct timeval *curtime);
void	printf_lock(int time, int ph_index, char *str);

/* list operations */
t_list	*ft_create_elem(int data);
t_list	*ft_find_bot_elem(t_list *list);
t_list	*ft_add_bottom_elem(t_list *list, int data);
void	display_list(t_list *list);

#endif
