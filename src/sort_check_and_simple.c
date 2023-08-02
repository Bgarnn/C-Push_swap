#include "push_swap.h"

static void	sa(t_data *data)
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

static void	rra(t_data *data)
{
	t_node	*tmp;
	t_node	*first;

	if (data->size_a <= 1)
		return ;
	tmp = data->a_top;
	while (tmp->next->next)
		tmp = tmp->next;
	first = data->a_top;
	data->a_top = tmp->next;
	tmp->next = NULL;
	data->a_top->next = first;
	write(1, "rra\n", 4);
}

static void	three_or_less(t_data *data)
{
	if ((data->size_a == 2) && (data->a_top->value > data->a_top->next->value))
		sa(data);
	else if (data->a_top->value > data->a_top->next->value
		&& data->a_top->value < data->a_top->next->next->value)
		sa(data);
	else if (data->a_top->value > data->a_top->next->value
		&& data->a_top->next->value < data->a_top->next->next->value)
		ra(data);
	else if (data->a_top->next->next->value < data->a_top->value
		&& data->a_top->next->next->value < data->a_top->next->value)
		rra(data);
	else if (data->a_top->value < data->a_top->next->next->value
		&& data->a_top->next->value > data->a_top->next->next->value)
	{
		sa(data);
		ra(data);
	}
	else if (data->a_top->value > data->a_top->next->value
		&& data->a_top->next->value > data->a_top->next->next->value)
	{
		sa(data);
		rra(data);
	}
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
	else if (data->size_a <= 100)
	{
		data->size_block = 5;
		a_to_b(data);
		t_node *curb = data->b_top;
		while (curb)
		{
			printf("stack_b :%d\n", curb->rank);
			curb = curb->next;
		}
		b_to_a(data);
	}
	else
	{
		data->size_block = 50;
		a_to_b(data);
		b_to_a(data);		
	}
}