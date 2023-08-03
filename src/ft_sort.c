#include "push_swap.h"

static int	max_len(t_data *data)
{
	int	i;
	int	max;

	i = 1;
	max = lst_len(data->a_top);
	while (max / 2 != 0)
	{
		i++;
		max = max / 2;
	}
	return (i);
}

static void	radix(t_data *data)
{
	int		i;
	int		len;
	int		max_bit;
	t_node	*current;

	i = 0;
	max_bit = max_len(data);
	while (i < max_bit && !lst_sorted(data))
	{
		len = data->size_a;
		while (len--)
		{
			current = data->a_top;
			if ((current->rank & (1 << i)))
				ra(data);
			else
				pb(data);
		}
		len = data->size_b;
		while (len--)
			pa(data);
		i++;
	}
}

static void	three_or_less(t_data *data)
{
	if ((data->size_a == 2) && (data->a_top->rank > data->a_top->next->rank))
		sa(data);
	else if (data->a_top->rank > data->a_top->next->rank
		&& data->a_top->rank < data->a_top->next->next->rank)
		sa(data);
	else if (data->a_top->rank > data->a_top->next->rank
		&& data->a_top->next->rank < data->a_top->next->next->rank)
		ra(data);
	else if (data->a_top->rank < data->a_top->next->next->rank
		&& data->a_top->next->rank > data->a_top->next->next->rank)
	{
		sa(data);
		ra(data);
	}
	else if (data->a_top->rank > data->a_top->next->rank
		&& data->a_top->next->rank > data->a_top->next->next->rank)
	{
		sa(data);
		rra(data);
	}
	else if (data->a_top->next->next->rank < data->a_top->rank
		&& data->a_top->next->next->rank < data->a_top->next->rank)
		rra(data);
}

static void	five_or_less(t_data *data)
{
	int	i;

	i = data->size_a - 3;
	while (data->size_a > 3)
	{
		if (data->a_top->rank <= i)
			pb (data);
		else
			ra (data);
	}
	three_or_less(data);
	while (data->b_top)
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
}

void	sort_check(t_data *data)
{
	data->size_a = lst_len(data->a_top);
	if (data->size_a <= 3)
		three_or_less(data);
	else if (data->size_a <= 5)
		five_or_less(data);
	else
		radix(data);
}