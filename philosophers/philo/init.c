#include "philo.h"

static t_state *check_init(t_state *state)
{
	int i;

	if (state->num_philos < 2 && state->time_die < 1
		&& state->time_eat < 1 && state->time_sleep < 1)
		return (NULL);
	state->forks_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * state->num_philos);
	if (!state->forks_mutex)
	{
		free(state);
		return (NULL);
	}
	i = 0;
	while (i < state->num_philos)
	{
		if (pthread_mutex_init(&state->forks_mutex[i++], NULL) != 0)
		{
			i = 0;
			while (i < state->num_philos)
				free(state->forks_mutex);
			free(state);
			return (NULL);
		}
	}
	return (state);
}

t_state	*ft_init(int argc, char **argv)
{
	t_state *state;

	state = (t_state *)malloc(sizeof(t_state));
	if (!state)
		return (NULL);
	if (!(argc == 5 || argc == 6))
		return (NULL);
	state->num_philos = ft_atoi(argv[1]);
	state->time_die = ft_atoi(argv[2]);
	state->time_eat = ft_atoi(argv[3]);
	state->time_sleep = ft_atoi(argv[4]);
	state->meals = 0;
	if (argv[5])
	{
		state->meals = ft_atoi(argv[5]);
		if (state->meals < 1)
			return (NULL);
	}
	return (check_init(state));
}
