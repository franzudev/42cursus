#include "philo.h"

t_philo	*init_philos(t_state *state)
{
	int				i;
	t_philo			*philos;

	philos = (t_philo *) malloc(sizeof(t_philo) * state->num_philos);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < state->num_philos)
	{
		philos[i].thread_num = i + 1;
		philos[i].eaten_meals = 0;
		philos[i].state = state;
		philos[i].lfork = i;
		philos[i].rfork = philos[i].thread_num % state->num_philos;
		pthread_mutex_init(&philos[i].mutex, NULL);
//		pthread_mutex_init(&philos[i].count_mutex, NULL);
//		pthread_mutex_lock(&philos[i].count_mutex);
		i++;
	}
	return (philos);
}

static void	init_forks(t_state *state)
{
	int	i;

	state->forks_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* state->num_philos);
	if (!state->forks_mutex)
	{
		state->forks_mutex = NULL;
		return ;
	}
	i = 0;
	while (i < state->num_philos)
	{
		if (pthread_mutex_init(&state->forks_mutex[i++], NULL) != 0)
		{
			i = 0;
			while (i < state->num_philos)
				free(state->forks_mutex);
			state->forks_mutex = NULL;
		}
	}
}

static t_state	*check_init(t_state *state)
{
	if (state->num_philos < 1 || state->time_die < 1
		|| state->time_eat < 1 || state->time_sleep < 1)
		return (NULL);
	init_forks(state);
	if (!state->forks_mutex)
		return (NULL);
	state->start = get_time();
	state->philos = init_philos(state);
	if (!state->philos)
		return (NULL);
	pthread_mutex_init(&state->write_mutex, NULL);
	pthread_mutex_init(&state->main_mutex, NULL);
	pthread_mutex_lock(&state->main_mutex);
	return (state);
}

t_state	*ft_init(int argc, char **argv, t_state *state)
{
	state->forks_mutex = NULL;
	state->philos = NULL;
	if (!(argc == 5 || argc == 6))
		return (NULL);
	state->num_philos = ft_atoi(argv[1]);
	state->time_die = ft_atoi(argv[2]);
	state->time_eat = ft_atoi(argv[3]);
	state->time_sleep = ft_atoi(argv[4]);
	state->meals = 0;
	state->is_dead = 0;
	if (argv[5])
	{
		state->meals = ft_atoi(argv[5]);
		if (state->meals < 1)
			return (NULL);
	}
	return (check_init(state));
}
