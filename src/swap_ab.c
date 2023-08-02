#include "push_swap.h"

void	a_to_b(t_data *data)
{
	int	i;
	int	block;

	i = 0;
	block = 1;
	while (data->a_top)
	{
		if(data->a_top->rank <= block * data->size_block)
		{
			pb(data);
			if(data->size_b > 1)
			{
				if(data->b_top->rank < ((block * data->size_block) - (data->size_block / 2)))
					rb(data);
			}
			i++;
		}
		else
			ra(data);
		if (i == (block * data->size_block))
			block++;
	}
}

static void	rrb(t_data *data)
{
	t_node	*tmp;
	t_node	*first;

	if (data->size_b <= 1)
		return ;
	tmp = data->b_top;
	while (tmp->next->next)
		tmp = tmp->next;
	first = data->b_top;
	data->b_top = tmp->next;
	tmp->next = NULL;
	data->b_top->next = first;
	write(1, "rrb\n", 4);
}

// static void	ranking(t_data *data)
// {
// 	int	i;
// 	t_node	*current;
// 	t_node	*loop;

// 	loop = data->a_top;
// 	while (loop)
// 	{
// 		current = data->a_top;
// 		i = 1;
// 		while (current)
// 		{
// 			if (current->value < loop->value)
// 				i++;
// 			current = current->next;
// 		}
// 		loop->rank = i;
// 		loop = loop->next;
// 	}
// }

static void	max_and_count(t_data *data)
{
	int	i;
	int	max;
	t_node	*current;

	i = 1;
	max = data->b_top->rank;
	current = data->b_top->next;
	while (current)
	{
		if (current->rank > max)
		{
			data->move_upper = i;
			data->move_lower = ((data->size_b) - i) + 1;
			max = current->rank;
		}
		i++;
		current = current->next;
	}
}

void	b_to_a(t_data *data)
{
	int	i;

	while (data->b_top)
	{
		max_and_count(data);
		if (data->move_upper <= data->move_lower)
		{
			i = data->move_upper;
			while (i > 0)
			{
				rb(data);
				i--;
			}
			pa(data);
		}
		else
		{
			i = data->move_lower;
			while (i > 0)
			{
				rrb(data);
				i--;
			}
			pa(data);
		}
	}
}