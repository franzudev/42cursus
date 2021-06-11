#include "philo.h"

enum e_msg_type {
	EAT = 1,
	SLEEP,
	FORK,
	THINK
};

char *get_action(int type)
{
	if (type == EAT)
		return " is eating\n";
	else if (type == SLEEP)
		return " is sleeping\n";
	else if (type == FORK)
		return " has taken a fork\n";
	else if (type == THINK)
		return " is thinking\n";
	return (0);
}

void print_msg(t_philo *philo, enum e_msg_type type)
{
	t_state *state;

	state = philo->state;
	pthread_mutex_lock(&state->write_mutex);
	printf("%-10llu %d%s", get_time() - state->start,
	   philo->thread_num, get_action(type));

	pthread_mutex_unlock(&state->write_mutex);
}

void	ft_sleep(t_philo *philo)
{
	print_msg(philo, SLEEP);
	usleep(philo->state->time_sleep * 1000);
}

void	eat(t_philo *philo)
{
	t_state *state;

	state = philo->state;
	print_msg(philo, EAT);
	usleep(state->time_eat * 1000);
	pthread_mutex_unlock(&state->forks_mutex[philo->lfork]);
	pthread_mutex_unlock(&state->forks_mutex[philo->rfork]);
}

void take_fork(t_philo *philo)
{
	t_state *state;

	state = philo->state;
	pthread_mutex_lock(&state->forks_mutex[philo->lfork]);
	print_msg(philo, FORK);
	pthread_mutex_lock(&state->forks_mutex[philo->rfork]);
	print_msg(philo, FORK);
}

void	think(t_philo *philo)
{
	print_msg(philo, THINK);
}

void	*thread_start(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		take_fork(philo);
		eat(philo);
		ft_sleep(philo);
		think(philo);
		pthread_mutex_unlock(&philo->mutex);
	}
	return philo;
}

int	ft_terminate(t_state *state, int sig)
{
	(void)state;
//	free(state->philos);
//	free(state->forks_mutex);
//	free(state);
	return (sig);
}

int
main(int argc, char *argv[])
{
	t_state *state;
	int i;

	state = ft_init(argc, argv);
	if (!state)
	{
		free(state);
		write(2, "Invalid arguments\n", 18);
		return (1);
	}
	i = 0;
	while (i < state->num_philos)
		pthread_join(state->philos[i++].thread_id, NULL);
	i = 0;
	while (i < state->num_philos)
	{
		pthread_mutex_destroy(&state->philos[i].mutex);
		pthread_mutex_destroy(&state->forks_mutex[i++]);
	}
	return /*ft_terminate(state,*/ EXIT_SUCCESS/*)*/;
}
