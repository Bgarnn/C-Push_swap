#include "push_swap.h"

static void	a_to_b(t_data *data)
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

static void	three_or_less(t_data *data)
{
	if (data->size_a == 2)
	{
		if (data->a_top->rank > data->a_top->next->rank)
			sa(data);
	}
	else
	{
		if (data->a_top->rank > data->a_top->next->rank)
			sa(data);
		if (data->a_top->rank > data->a_top->next->next->rank)
			ra(data);
		else if ((data->a_top->rank < data->a_top->next->next->rank) 
			&& !lst_sorted(data))
			sa(data);
		if (data->a_top->rank > data->a_top->next->next->rank)
			ra(data);
	}
}


static void	push_back(t_data *data)
{
	if (data->b_top->next == NULL)
	{
		pa (data);
		return ;
	}
	else if (data->b_top->next->rank > data->b_top->rank)
		rb (data);
	pa (data);
}

static void	five_or_less(t_data *data)
{
	t_node	*current;
	int	i;

	current = data->a_top;
	i = data->size_a - 3;
	while (i > 0)
	{
		if (current->rank <= (data->size_a - 3))
		{
			pb (data);
			i--;
		}
		else
			ra (data);
	}
	three_or_less (data);
	while (data->b_top)
	{
		push_back(data);
	}
}

void	sort_check(t_data *data)
{
	data->size_a = lst_len(data->a_top);
	if (data->size_a <= 3)
		three_or_less(data);
	else if (data->size_a <= 5)
		five_or_less(data);
	else if (data->size_a <= 100)
	{
		data->size_block = 20;
		a_to_b(data);
		b_to_a(data);
	}
	else
	{
		data->size_block = 50;
		a_to_b(data);
		b_to_a(data);		
	}
}