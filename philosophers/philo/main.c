#include "philo.h"

int
main(int argc, char *argv[])
{
	t_state state;

	if (!ft_init(argc, argv, &state))
		return (ft_terminate(&state, 1));
	if (!start_routines(&state))
		return (ft_terminate(&state, 2));
	pthread_mutex_lock(&state.main_mutex);
	pthread_mutex_unlock(&state.main_mutex);
	return ft_terminate(&state, EXIT_SUCCESS);
}
