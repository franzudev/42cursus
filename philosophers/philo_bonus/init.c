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
		philos[i].mutex = create_philo_sem(PHILO_SEM, i);
		if (philos[i].mutex == SEM_FAILED)
			return (NULL);
		philos[i].count_mutex = create_philo_sem(EAT_SEM, i);
		if (philos[i].count_mutex == SEM_FAILED)
			return (NULL);
		i++;
	}
	return (philos);
}

static int	init_semaphores(t_state *state)
{
	t_state	*s;

	sem_unlink(FORKS_SEM);
	sem_unlink(WRITE_SEM);
	sem_unlink(MAIN_SEM);
	s = state;
	s->forks_mutex = ft_sem_open(FORKS_SEM, s->num_philos);
	s->write_mutex = ft_sem_open(WRITE_SEM, 1);
	s->main_mutex = ft_sem_open(MAIN_SEM, 0);
	if (s->forks_mutex == SEM_FAILED
		|| s->write_mutex == SEM_FAILED
		|| s->main_mutex == SEM_FAILED)
		return (0);
	return (1);
}

static t_state	*check_init(t_state *state)
{
	if (state->num_philos < 1 || state->time_die < 1
		|| state->time_eat < 1 || state->time_sleep < 1)
		return (NULL);
	if (!init_semaphores(state))
		return (NULL);
	if (state->forks_mutex == SEM_FAILED)
		return (NULL);
	state->start = get_time();
	state->philos = init_philos(state);
	if (!state->philos)
		return (NULL);
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
