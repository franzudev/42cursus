#include "philo.h"

int
main(int argc, char *argv[])
{
	t_state state;

	if (!ft_init(argc, argv, &state))
	{
		write(2, "Invalid arguments\n", 18);
		return (1);
	}
	return ft_terminate(&state, EXIT_SUCCESS);
}
