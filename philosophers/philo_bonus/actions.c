#include "philo.h"

char	*get_action(int type)
{
	if (type == EAT)
		return (" is eating\n");
	else if (type == SLEEP)
		return (" is sleeping\n");
	else if (type == FORK)
		return (" has taken a fork\n");
	else if (type == THINK)
		return (" is thinking\n");
	else if (type == DIE)
		return (" died\n");
	else if (type == COUNT)
		return (" they ate\n");
	return (0);
}

void	eat(t_philo *philo)
{
	t_state	*state;

	state = philo->state;
	if (state->is_dead)
		return ;
	sem_wait(philo->mutex);
	philo->is_eating = 1;
	philo->last_meal = get_time();
	philo->time_to_die = philo->last_meal + philo->state->time_die;
	print_msg(philo, EAT);
	ft_usleep(state->time_eat, state);
	philo->eaten_meals++;
	philo->is_eating = 0;
	sem_post(philo->mutex);
	sem_post(philo->count_mutex);
}

void	ft_sleep(t_philo *philo)
{
	t_state	*state;

	state = philo->state;
	if (state->is_dead)
		return ;
	print_msg(philo, SLEEP);
	sem_post(state->forks_mutex);
	sem_post(state->forks_mutex);
	ft_usleep(state->time_sleep, state);
}

void	take_fork(t_philo *philo)
{
	t_state	*state;

	state = philo->state;
	if (state->is_dead)
		return ;
	sem_wait(state->forks_mutex);
	print_msg(philo, FORK);
	sem_wait(state->forks_mutex);
	print_msg(philo, FORK);
}

void	think(t_philo *philo)
{
	if (philo->state->is_dead)
		return ;
	print_msg(philo, THINK);
}
