#include "../includes/push_swap.h"
// #include "push_swap.h"

size_t	strcnt(const char **str)
{
	size_t i;
	
	i = 0;
	if (!str)
		return (0);
	while (str[i] != NULL)
		i++;
	return (i);
}

int		check_args(int len, t_ps *temp)
{
	int i;

	i = 0;

	while (i < len - 1)
	{
		if (temp->a[i] > temp->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		check_double(t_ps *temp, int len, int val, int *valid)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (temp->a[i] == val)
			return (ft_error(valid));
		i++;
	}
	return (1);
}

int		val_nbr(const char *str, int *valid)
{
	int i;

	i = 0;
	if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
	{
		if (str[i] == '-')
		{
			if (ft_strlen(str) <= 1)
				return (ft_error(valid));
			i++;
		}
		while (str[i] != '\0')
		{
			if (str[i] < '0' || str[i] > '9')
				return (ft_error(valid));
			i++;
		}
	}
	else
		return (ft_error(valid));
	return (1);
}

int		atoi_ps(const char *str, int *valid)
{
	long long	value;
	int			sign;

	value = 0;
	sign = 1;
	if (!val_nbr(str, valid))
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
			|| *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str <= '9' && *str >= '0')
	{
		value = value * 10 + (*str - '0');
		str++;
		if ((value * sign) > 2147483647 || (value * sign) < -2147483648)
			return (ft_error(valid));
	}
	return (sign * value);
}
