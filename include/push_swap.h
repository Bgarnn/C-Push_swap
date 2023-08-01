#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
}				t_node;

typedef struct s_data
{
	struct s_node	*a_top;
	struct s_node	*b_top;
}				t_data;

void	input_get(t_node **stack_a, t_node **stack_b, char **argv);
void	error_clear(t_node **stack_a, t_node **stack_b);
void	free_split(char **ptr);
void	error_clear_1(t_node **stack);

#endif