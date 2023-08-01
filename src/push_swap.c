#include "push_swap.h"

static void	var_init(t_data *data)
{
	data->a_top = NULL;
	data->b_top = NULL;

}

int main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		exit(0);
	var_init(&data);
	input_get(&data, argv);
	
	t_node *curr = data.a_top;
	while (curr)
	{
		printf("stack_a :%d\n", curr->value);
		curr = curr->next;
	}

	t_node *curb = data.b_top;
	while (curb)
	{
		printf("stack_b :%d\n", curb->value);
		curr = curb->next;
	}

}