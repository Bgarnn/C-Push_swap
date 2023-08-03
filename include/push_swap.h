/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:48:27 by kburalek          #+#    #+#             */
/*   Updated: 2023/08/03 14:48:30 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int				size_a;
	int				size_b;
}				t_data;

void	input_get(t_data *data, char **argv);
void	error_clear(t_data *data);
void	lst_clear(t_node **stack);
void	lst_add_back(t_node **stack_a, int val);
int		lst_sorted(t_data *data);
int		lst_len(t_node *stack);
void	sort_check(t_data *data);
void	sa(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rra(t_data *data);

#endif
