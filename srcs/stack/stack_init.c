/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:04:51 by dong-hki          #+#    #+#             */
/*   Updated: 2025/01/08 12:40:08 by dong-hki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	init_data(t_ps *data, int argc, char *argv[])
{
	--size;
	init_stack(data, &data->a, argc);
	init_stack(data, &data->b, argc);
	fill_stack(data, &data->a, ++argv);
	data->op_list = NULL;
}

void	init_stack(t_ps *data, t_stack *stk, int size)
{
	stk->stack = (t_stack)malloc(sizeof(t_stack));
	if (!stk->stack)
		error(data);
	stk->size = size;
	stk->top = 0;
	stk->bottom = 0;
	ft_memset(stk->stack, 0, (sizeof(int) * stk->size));
}

void	fill_stack(t_ps *data, t_stack *stk, char *number_str[])
{
	
}
