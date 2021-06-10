#include "philo.h"

void	eat(t_philo *philo)
{
	t_state *state = philo->state;
	if (philo->lfork && philo->rfork)
		printf("Thread %d is eating\n", philo->thread_num);
	pthread_mutex_unlock(&state->forks_mutex[philo->thread_num -1]);
	pthread_mutex_unlock(&state->forks_mutex[philo->thread_num]);
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

static void *
thread_start(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	pthread_mutex_lock(&philo->mutex);
	while (1)
	{
		take_fork(philo);
		eat(philo);
//		think();
//		ft_sleep();
	}
	pthread_mutex_unlock(&philo->mutex);
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
	t_state 		*state;
	t_philo			*philos;
	pthread_mutex_t mutex;
	int i;
	int s;

	state = ft_init(argc, argv);
//	if (!state)
//	{
//		write(2, "Invalid arguments\n", 18);
//		return (1);
//	}
	pthread_mutex_init(&mutex, NULL);
	philos = state->philos;
	philos = (t_philo *)malloc(sizeof(t_philo) * state->num_philos);
	if (!philos)
		return (1);
	i = 0;
	while (i < state->num_philos)
	{
		philos[i].thread_num = i + 1;
		philos[i].mutex = mutex;
		philos[i].eaten_meals = 0;
		philos[i].state = state;
		philos[i].lfork = 0;
		philos[i].rfork = 0;

		s = pthread_create(&philos[i].thread_id, NULL,
						   &thread_start, &philos[i]);
		pthread_detach(philos[i].thread_id);
		if (s != 0)
			return 23;
		i++;
		usleep(100);
	}
	i = 0;
	while (i < state->num_philos)
		pthread_mutex_destroy(&state->forks_mutex[i++]);
	pthread_mutex_destroy(&mutex);

	return /*ft_terminate(state,*/ EXIT_SUCCESS/*)*/;
//
//	/* Destroy the thread attributes object, since it is no
//	   longer needed. */
//
//	s = pthread_mutex_destroy(&mutex);

//	if (s != 0)
//		return (-1);;
	/* Now join with each thread, and display its returned value. */

//	for (int tnum = 0; tnum < num_threads; tnum++) {
//		s = pthread_join(tinfo[tnum].thread_id, NULL);
//		if (s != 0)
//			return (-1);
//		printf("Joined with thread %d; returned value was %s\n",
//			   tinfo[tnum].thread_num, (char *) res);
//		free(res);      /* Free memory allocated by thread */
//	}
//
//	free(tinfo);
//	exit(EXIT_SUCCESS);
}
