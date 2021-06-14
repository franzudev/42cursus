#include "philo.h"

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

void	ft_sleep(t_philo *philo)
{
	print_msg(philo, SLEEP);
	usleep(philo->state->time_sleep * 1000);
}

void	eat(t_philo *philo)
{
	t_state *state;

	pthread_mutex_lock(&philo->mutex);
	state = philo->state;
	print_msg(philo, EAT);
	philo->eaten_meals++;
	usleep(state->time_eat * 1000);
	pthread_mutex_unlock(&state->forks_mutex[philo->lfork]);
	pthread_mutex_unlock(&state->forks_mutex[philo->rfork]);
	pthread_mutex_unlock(&philo->mutex);
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
