#include "philo.h"

int	ft_terminate(t_state *state, int sig)
{
	int	i;

//	i = 0;
//	while (i < state->num_philos)
//		pthread_join(state->philos[i++].thread_id, NULL);
	i = 0;
	while (i < state->num_philos)
	{
		pthread_mutex_destroy(&state->philos[i].mutex);
		pthread_mutex_destroy(&state->forks_mutex[i++]);
	}
	free(state->philos);
	free(state->forks_mutex);
	return (sig);
}

uint64_t	get_time()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print_msg(t_philo *philo, enum e_msg_type type)
{
	t_state		*state;
	uint64_t	time;

	state = philo->state;
	pthread_mutex_lock(&state->write_mutex);
	time = get_time() - state->start;
	printf("%-10llu %d%s", time,
		   philo->thread_num, get_action(type));
	if (type == EAT)
		philo->last_meal = time;
	pthread_mutex_unlock(&state->write_mutex);
}
