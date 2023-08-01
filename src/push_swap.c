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
	input_get(&data.a_top, &data.b_top, argv);

}