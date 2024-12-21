#include "philo.h"

void	ft_usleep(int time, t_state *state)
{
	unsigned long	end;

	end = get_time() + time;
	while (get_time() < end && !state->is_dead)
		usleep(time);
}

static void	*had_eaten(void *state_v)
{
	t_state	*state;
	int		i;
	int		total;

	state = (t_state *)state_v;
	total = 0;
	while (total < state->meals)
	{
		i = 0;
		while (i < state->num_philos)
			sem_wait(state->philos[i++].count_mutex);
		total++;
	}
	print_msg(&state->philos[0], COUNT);
	sem_post(state->main_mutex);
	return (NULL);
}

static void	*is_dying(void *arg)
{
	t_philo		*philo;
	t_state		*state;

	philo = arg;
	state = philo->state;
	while (1)
	{
		if (state->is_dead)
			return (NULL);
		sem_wait(philo->mutex);
		if (!philo->is_eating && get_time() > philo->time_to_die
			&& !state->is_dead)
		{
			state->is_dead = 1;
			print_msg(philo, DIE);
			sem_post(philo->mutex);
			sem_post(state->main_mutex);
			return (NULL);
		}
		sem_post(philo->mutex);
		usleep(1000);
	}
}

void	process_start(t_philo *arg)
{
	t_philo		*philo;
	pthread_t	tid;
	int			s;

	philo = (t_philo *)arg;
	philo->last_meal = get_time();
	philo->time_to_die = philo->last_meal + philo->state->time_die;
	s = pthread_create(&tid, NULL, is_dying, philo);
	pthread_detach(tid);
	if (s != 0)
		return ;
	while (1)
	{
		take_fork(philo);
		eat(philo);
		ft_sleep(philo);
		think(philo);
	}
}

int	start_routines(t_state *state)
{
	int			i;
	t_philo		*phs;
	pthread_t	tid;

	i = 0;
	phs = state->philos;
	if (state->meals > 0)
	{
		if (pthread_create(&tid, NULL, &had_eaten, state) != 0)
			return (0);
		pthread_detach(tid);
	}
	while (i < state->num_philos)
	{
		phs[i].pid = fork();
		if (phs[i].pid == 0)
		{
			process_start(&phs[i]);
			exit(0);
		}
		usleep(100);
		i++;
	}
	return (1);
}
