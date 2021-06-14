#include "philo.h"

void	*monitoring(void *arg)
{
	(void)arg;
	t_philo *philo;
	t_state	*state;

	philo = (t_philo *)arg;
	state = philo->state;
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		printf("monitor\n");
		pthread_mutex_unlock(&philo->mutex);
	}
	return NULL;
}

void	*thread_start(void *arg)
{
	t_philo *philo;
//	int		s;

	philo = (t_philo *)arg;
//	s = pthread_create(&philo->thread_id, NULL, &monitoring, &philo);
//	pthread_detach(philo->thread_id);
//	if (s != 0)
//		return (NULL);
	while (1)
	{
//		pthread_mutex_lock(&philo->mutex);
		take_fork(philo);
		eat(philo);
		ft_sleep(philo);
		think(philo);
//		pthread_mutex_unlock(&philo->mutex);
	}
	return philo;
}
