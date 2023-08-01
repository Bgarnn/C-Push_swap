#include "push_swap.h"

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

void	error_clear(t_data *data)
{
	lst_clear(&data->a_top);
	lst_clear(&data->b_top);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void add_to_stack(t_node **stack_a, int val)
{
	t_node *new_node;
	t_node *current;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = val;
	new_node->rank = 0;
	new_node->next = NULL;
	if (*stack_a == NULL)
	{
		*stack_a = new_node;
		(*stack_a)->next = NULL;
		return ;
	}
	current = *stack_a;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}