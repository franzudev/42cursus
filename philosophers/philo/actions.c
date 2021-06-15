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
	else if (type == DIE)
		return " died\n";
	return (0);
}

void	eat(t_philo *philo)
{
	t_state *state;

	state = philo->state;
	if (state->is_dead)
		return ;
	pthread_mutex_lock(&philo->mutex);
	philo->is_eating = 1;
	philo->last_meal = get_time();
	philo->time_to_die = philo->last_meal + philo->state->time_die;
	print_msg(philo, EAT);
	usleep(state->time_eat * 1000);
	philo->eaten_meals++;
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->mutex);
//	pthread_mutex_unlock(&philo->count_mutex);
}

void	ft_sleep(t_philo *philo)
{
	t_state *state;

	state = philo->state;
	if (state->is_dead)
		return ;
	print_msg(philo, SLEEP);
	pthread_mutex_unlock(&state->forks_mutex[philo->lfork]);
	pthread_mutex_unlock(&state->forks_mutex[philo->rfork]);
	usleep(philo->state->time_sleep * 1000);
}

void take_fork(t_philo *philo)
{
	t_state *state;

	state = philo->state;
	if (state->is_dead)
		return ;
	pthread_mutex_lock(&state->forks_mutex[philo->lfork]);
	print_msg(philo, FORK);
	pthread_mutex_lock(&state->forks_mutex[philo->rfork]);
	print_msg(philo, FORK);
}

void	think(t_philo *philo)
{
	if (philo->state->is_dead)
		return ;
	print_msg(philo, THINK);
}
