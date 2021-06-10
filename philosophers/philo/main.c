#include "philo.h"

void	ft_sleep(t_philo *philo)
{
	printf("Thread %d is sleeping\n", philo->thread_num);
	usleep(65000);
}

void	eat(t_philo *philo)
{
	t_state *state;

	state = philo->state;
	if (philo->lfork && philo->rfork)
	{
		printf("Thread %d is eating\n", philo->thread_num);
		usleep(65000);
		pthread_mutex_unlock(&state->forks_mutex[philo->thread_num - 1]);
		pthread_mutex_unlock(&state->forks_mutex[philo->thread_num]);
	}
}

void take_fork(t_philo *philo)
{
	t_state *state;

	state = philo->state;
	if (pthread_mutex_lock(&state->forks_mutex[philo->thread_num - 1]) == 0)
	{
		philo->lfork = 1;
		printf("Thread %d has taken fork %d\n", philo->thread_num,
			   philo->thread_num - 1);
	}
	if (philo->thread_num == philo->state->num_philos)
	{
		if (pthread_mutex_lock(&state->forks_mutex[0]) == 0)
		{
			printf("Thread %d has taken fork 0\n", philo->thread_num);
			philo->rfork = 1;
		}
		return;
	}
	else
	{
		if (pthread_mutex_lock(&state->forks_mutex[philo->thread_num]) == 0)
		{
			printf("Thread %d has taken fork %d\n", philo->thread_num,
				   philo->thread_num);
			philo->rfork = 1;
		}
	}
}

void	*thread_start(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		take_fork(philo);
		eat(philo);
		write(1, "porca madonna", 13);
		ft_sleep(philo);
		pthread_mutex_unlock(&philo->mutex);
//		think();
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
//	struct timeval	tv;
//	int time;
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
