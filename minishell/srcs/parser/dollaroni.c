#include "../../minishell.h"


// fai indexof e trova index
// fai substr fino index
// fai strjoin di temp e valore $
// ripwti finche muori

char	*ft_dollaroni(char *usd)
{
	int		index;
	char	*canada;

	canada = ft_substr(usd, 1, ft_strlen(usd) - 2);
	index = ft_index_of(usd, "$");

}