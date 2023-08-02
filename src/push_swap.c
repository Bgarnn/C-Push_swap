#include "push_swap.h"

static void	dup_check(t_data *data)
{
	t_node	*current;
	t_node	*loop;

	loop = data->a_top;
	while (loop)
	{
		current = loop->next;
		while (current)
		{
			if (current->value == loop->value)
				error_clear(data);
			current = current->next;
		}
		loop = loop->next;
	}
}

static void	ranking(t_data *data)
{
	int	i;
	t_node	*current;
	t_node	*loop;

	loop = data->a_top;
	while (loop)
	{
		current = data->a_top;
		i = 1;
		while (current)
		{
			if (current->value < loop->value)
				i++;
			current = current->next;
		}
		loop->rank = i;
		loop = loop->next;
	}
}

static void	var_init(t_data *data)
{
	data->a_top = NULL;
	data->b_top = NULL;
	data->size_a = 0;
	data->size_b = 0;
	data->size_block = 0;
	data->move_upper = 0;
	data->move_lower = 1;
}

int main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		exit(0);
	var_init(&data);
	input_get(&data, argv);
	dup_check(&data);
	ranking(&data);


	
	if (!lst_sorted(&data))
		sort_check(&data);
	
	// data.size_a = lst_len(data.a_top);
	// // ra(&data);
	// rra(&data);

	t_node *curr = data.a_top;
	while (curr)
	{
		printf("stack_a :%d\n", curr->rank);
		curr = curr->next;
	}

	t_node *curb = data.b_top;
	while (curb)
	{
			printf("stack_b :%d\n", curb->rank);
			curb = curb->next;
	}

	lst_clear(&data.a_top);
	lst_clear(&data.b_top);
	return (0);
}