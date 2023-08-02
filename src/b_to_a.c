#include "push_swap.h"

// static void	rrb(t_data *data)
// {
// 	t_node	*tmp;
// 	t_node	*first;

// 	if (data->size_b <= 1)
// 		return ;
// 	tmp = data->b_top;
// 	while (tmp->next->next)
// 		tmp = tmp->next;
// 	first = data->b_top;
// 	data->b_top = tmp->next;
// 	tmp->next = NULL;
// 	data->b_top->next = first;
// 	write(1, "rrb\n", 4);
// }

// static void	max_and_count(t_data *data)
// {
// 	int	i;
// 	int	max;
// 	t_node	*current;

// 	i = 1;
// 	max = data->a_top->rank;
// 	current = data->a_top->next;
// 	while (current)
// 	{
// 		if (current->rank > max)
// 		{
// 			data->move_upper = i;
// 			data->move_lower = ((data->size_b) - i) + 1;
// 			max = current->rank;
// 		}
// 		i++;
// 		current = current->next;
// 	}
// }

// void	b_to_a(t_data *data)
// {
// 	int	i;

// 	max_and_count(data);
// 	if (data->move_upper <= data->move_lower)
// 	{
// 		i = data->move_upper;
// 		while (i > 0)
// 		{
// 			rb(data);
// 			i--;
// 		}
// 		pa(data);
// 	}
// 	else
// 	{
// 		i = data->move_lower;
// 		while (i > 0)
// 		{
// 			rrb(data);
// 			i--;
// 		}
// 		pa(data);
// 	}
// }