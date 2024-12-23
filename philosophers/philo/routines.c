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
			pthread_mutex_lock(&state->philos[i++].count_mutex);
		total++;
	}
	print_msg(&state->philos[0], COUNT);
	pthread_mutex_unlock(&state->main_mutex);
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
		pthread_mutex_lock(&philo->mutex);
		if (!philo->is_eating && get_time() > philo->time_to_die
			&& !state->is_dead)
		{
			state->is_dead = 1;
			print_msg(philo, DIE);
			pthread_mutex_unlock(&philo->mutex);
			pthread_mutex_unlock(&state->main_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->mutex);
		usleep(1000);
	}
}

void	*thread_start(void *arg)
{
	t_philo	*philo;
	int		s;

	philo = (t_philo *)arg;
	philo->last_meal = get_time();
	philo->time_to_die = philo->last_meal + philo->state->time_die;
	s = pthread_create(&philo->thread_id, NULL, &is_dying, philo);
	pthread_detach(philo->thread_id);
	if (s != 0)
		return (NULL);
	while (1)
	{
		take_fork(philo);
		eat(philo);
		ft_sleep(philo);
		think(philo);
	}
	return (philo);
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
		if (pthread_create(&phs[i].thread_id, NULL, &thread_start, &phs[i])
			!= 0)
			return (0);
		pthread_detach(phs[i].thread_id);
		usleep(100);
		i++;
	}
	return (1);
}
