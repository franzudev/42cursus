#include "philo.h"

void static	print_error(int sig)
{
	if (sig == 1)
		write(2, "Invalid arguments\n", 18);
	if (sig == 2)
		write(2, "Fatal error\n", 12);
}

int	ft_terminate(t_state *state, int sig)
{
	t_philo	*philos;
	int		i;

	philos = state->philos;
	i = 0;
	sem_close(state->write_mutex);
	sem_close(state->main_mutex);
	sem_close(state->forks_mutex);
	if (state->philos)
	{
		while (i < state->num_philos)
		{
			sem_close(philos[i].count_mutex);
			sem_close(philos[i].mutex);
			kill(philos[i++].pid, SIGKILL);
		}
		free(state->philos);
	}
	print_error(sig);
	return (sig);
}

uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void 	set_color(enum e_msg_type type)
{
	if (type == DIE)
		printf("\e[91m");
	else if (type == EAT)
		printf("\e[92m");
	else if (type == SLEEP)
		printf("\e[94m");
	else if (type == FORK)
		printf("\e[33m");
	else if (type == THINK)
		printf("\e[36m");
	else if (type == COUNT)
		printf("\e[35m");
}

void	print_msg(t_philo *philo, enum e_msg_type type)
{
	t_state		*state;
	uint64_t	time;

	state = philo->state;
	sem_wait(state->write_mutex);
	time = get_time() - state->start;
	set_color(type);
	printf("%-10llu %d%s\e[0m", time,
		   philo->thread_num, get_action(type));
	if (type == EAT)
		philo->last_meal = time;
	if (!(type == DIE || type == COUNT))
		sem_post(state->write_mutex);
}
