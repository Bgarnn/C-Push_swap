#include "push_swap.h"

static int	valid_and_flow(char *str, int sign, int result, t_node **stack_a)
{
	int	i;
	int	digit;
	char	*ptr;

	i = 0;
	ptr = str;
	while (ptr[i])
	{
		if (!(ptr[i] >= '0' && ptr[i] <= '9'))
			error_clear_1(stack_a);
		i++;
	}
	i = 0;
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		digit = ptr[i] - '0';
		if (((sign == 1) && (result > (2147483647 - digit) / 10)) 
			|| ((sign == -1) && (result > (2147483648 - digit) / 10)))
			error_clear_1(stack_a);
		result = (result * 10) + digit;
		i++;
	}
	return (result * sign);
}

static int	re_atoi(char *str, t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	sign;
	int	result;
	char	*ptr;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '\0' || ft_isdigit(str[i]) == 0)
		error_clear(stack_a, stack_b);
	ptr = &str[i];
	return (valid_and_flow(ptr, sign, result, stack_a));
}

// static void add_to_stack(t_node **stack_a, int val)
// {
// 	t_node *new_node;
// 	t_node *current;

// 	new_node = (t_node *)malloc(sizeof(t_node));
// 	if (!new_node)
// 		return ;
// 	new_node->value = val;
// 	new_node->rank = 0;
// 	new_node->next = NULL;
// 	if (*stack_a == NULL)
// 	{
// 		*stack_a = new_node;
// 		(*stack_a)->next = NULL;
// 		return ;
// 	}
// 	current = *stack_a;
// 	while (current->next != NULL)
// 		current = current->next;
// 	current->next = new_node;
// }

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

void	input_get(t_node **stack_a, t_node **stack_b, char **argv)
{
	int i;
	int j;
	char	**argv_split;

	i = 1;
	while (argv[i])
	{
		if ((!argv[i][0]) || (!ft_is_nspace(argv[i])))
			error_clear(stack_a, stack_b);
		argv_split = ft_split(argv[i], ' ');
		if (!argv_split)
			error_clear(stack_a, stack_b);
		j = 0;
		while (argv_split[j])
		{
			int m = re_atoi(argv_split[j], stack_a, stack_b);
			printf("%d\n", m);
			// add_to_stack(stack_a, re_atoi(argv_split[j], stack_a, stack_b));
			j++;
		}
		free_split(argv_split);
		if (!stack_a)
			error_clear(stack_a, stack_b);
		i++;
	}
}