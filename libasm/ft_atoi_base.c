int	ft_isspace(char str)
{
	if (str == '\t' || str == '\n' || str == '\v' ||
		str == '\f' || str == '\r' || str == ' ')
	{
		return (1);
	}
	return (0);
}

int	is_char_int(char str)
{
	if (str >= '0' && str <= '9')
	{
		return (1);
	}
	return (0);
}

int	is_char(char str)
{
	if (str >= 'A' && str <= 'Z')
	{
		return (1);
	}
	if (str >= 'a' && str <= 'z')
	{
		return (1);
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int len;
	int chrs[255];

	len = 0;
	while (len < 255)
		chrs[len++] = 0;
	len = ft_strlen(base);
	if (len < 2 || !base)
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-' || ft_isspace(*base))
			return (0);
		if (chrs[(unsigned char)*base])
			return (0);
		chrs[(unsigned char)*base] = 1;
		base++;
	}
	return (1);
}

int ft_strchr(char *str, int ch)
{
	while (*str)
		if (*(str++) == ch)
			return (1);
	return (0);
}

int ft_pow(int num, int pow)
{
	int nb;

	nb = 1;
	if (!pow)
		return 1;
	if (pow == 1)
		return num;
	while(pow--)
		nb *= num;
	return nb;
}

int ft_index(char *str, int ch)
{
	int i;

	i = 0;
	while (str[i])
		if (str[i++] == ch)
			return (--i);
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int negative;
	int res;
	int ba;

	if (!check_base(base))
		return (0);
	ba = ft_strlen(base);
	res = 0;
	negative = 1;
	while (*str && ft_isspace(*str))
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	int i = 0;
	int diff = ft_strlen(str) - 1;
	while (ft_strchr(base, str[i]) && str[i])
		res = res + ((ft_index(base, str[i++])) * (ft_pow(ba, diff--)));
	return (res * negative);
}