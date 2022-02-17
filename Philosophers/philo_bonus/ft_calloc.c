#include "philo_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	i;

	res = malloc(size * count);
	if (!res)
		return (NULL);
	i = 0;
	while (i < (count * size) && size > 0)
	{
		((char *)res)[i] = 0;
		i++;
	}
	return (res);
}
