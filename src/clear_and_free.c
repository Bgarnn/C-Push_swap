#include "push_swap.h"

void	free_split(char **ptr)
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

static void	lst_clear(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	*stack = NULL;
}

void	error_clear(t_node **stack_a, t_node **stack_b)
{
	lst_clear(stack_a);
	lst_clear(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_clear_1(t_node **stack)
{
	lst_clear(stack);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}