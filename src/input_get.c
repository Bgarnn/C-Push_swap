#include "push_swap.h"

static int	valid_and_flow(char *str, int sign, t_data *data)
{
	int	i;
	int	digit;
	int	result;
	char	*ptr;

	i = 0;
	result = 0;
	ptr = str;
	while (ptr[i])
	{
		if (!(ptr[i] >= '0' && ptr[i] <= '9'))
			error_clear(data);
		digit = ptr[i] - '0';
		if (((sign == 1) && (result > (2147483647 - digit) / 10)) 
			|| ((sign == -1) && (result > (2147483648 - digit) / 10)))
			error_clear(data);
		result = (result * 10) + digit;
		i++;
	}
	return (result * sign);
}

static int	re_atoi(char *str, t_data *data)
{
	int	i;
	int	sign;
	char	*ptr;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '\0' || !(str[i] >= '0' && str[i] <= '9'))
		error_clear(data);
	ptr = &str[i];
	return (valid_and_flow(ptr, sign, data));
}

static void	free_split(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static int	ft_is_nspace(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

void	input_get(t_data *data, char **argv)
{
	int i;
	int j;
	char	**argv_split;

	i = 1;
	while (argv[i])
	{
		if ((!argv[i][0]) || (!ft_is_nspace(argv[i])))
			error_clear(data);
		argv_split = ft_split(argv[i], ' ');
		if (!argv_split)
			error_clear(data);
		j = 0;
		while (argv_split[j])
		{
			lst_add_back(&data->a_top, re_atoi(argv_split[j], data));
			j++;
		}
		free_split(argv_split);
		if (!data->a_top)
			error_clear(data);
		i++;
	}
	data->size_a = lst_len(data->a_top);
}