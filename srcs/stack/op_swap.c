/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:15:07 by dong-hki          #+#    #+#             */
/*   Updated: 2025/01/09 13:24:02 by dong-hki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mystack.h"

void	swap(t_stack *stk)
{
	int	temp;

	if (stk->stack[next_down(stk, stk->top)] == 0)
		return ;
	temp = stk->stack[stk->top];
	stk->stack[stk->top] = stk->stack[next_down(stk, stk->top)];
	stk->stack[next_down(stk, stk->top)] = temp;
}

void	swap_a(t_ps *data)
{
	swap(&data->a);
}

void	swap_b(t_ps *data)
{
	swap(&data->b);
}
