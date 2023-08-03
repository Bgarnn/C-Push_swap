/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:49:25 by kburalek          #+#    #+#             */
/*   Updated: 2023/08/03 14:49:27 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_len(t_node *stack)
{
	int		i;
	t_node	*current;

	i = 0;
	current = stack;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int	lst_sorted(t_data *data)
{
	t_node	*ptr;

	ptr = data->a_top;
	while (ptr && ptr->next)
	{
		if (ptr->rank > ptr->next->rank)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

void	lst_add_back(t_node **stack_a, int val)
{
	t_node	*new_node;
	t_node	*current;

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

void	lst_clear(t_node **stack)
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

void	sa(t_data *data)
{
	t_node	*tmp;

	if (data->size_a < 2)
		return ;
	tmp = data->a_top;
	data->a_top = data->a_top->next;
	tmp->next = data->a_top->next;
	data->a_top->next = tmp;
	write(1, "sa\n", 3);
}
