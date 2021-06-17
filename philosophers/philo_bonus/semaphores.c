#include "philo.h"

sem_t	*ft_sem_open(char *name, int value)
{
	return (sem_open(name, O_CREAT | O_EXCL, 0644, value));
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*res;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * size);
	if (!res)
		return (0);
	while (*s1)
		res[i++] = *(s1++);
	while (*s2)
		res[i++] = *(s2++);
	res[i] = 0;
	return (res);
}

sem_t	*create_philo_sem(char *sem_name, int i)
{
	char	philo_n[3];
	char	*name;
	sem_t	*semaphore;
	int		j;

	j = 0;
	while (i > 0 && j > -1)
	{
		philo_n[j++] = i % 10 + '0';
		i /= 10;
	}
	philo_n[j] = '\0';
	name = ft_strjoin(sem_name, philo_n);
	if (!name)
		return (SEM_FAILED);
	sem_unlink(name);
	semaphore = ft_sem_open(name, 1);
	free(name);
	return (semaphore);
}
