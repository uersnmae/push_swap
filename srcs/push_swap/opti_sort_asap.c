/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort_asap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:50:14 by dong-hki          #+#    #+#             */
/*   Updated: 2025/01/17 14:01:07 by dong-hki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	sort_three_numbers(int *a, int *b, int *c)
{
	if (*a > *b)
		swap(a, b);
	if (*a > *c)
		swap(a, c);
	if (*b > *c)
		swap(b, c);
}

static bool	is_consecutive(int a, int b, int c, int d)
{
	sort_three_numbers(&a, &b, &c);
	return ((b - a == 1) && (c - b == 1) && (d - c == 1));
}

bool	a_partly_sort(t_ps *data, int from)
{
	t_stack	*a;
	int		value;
	int		i;

	a = &data->a;
	i = a->top;
	while (--from)
		i = next_down(a, i);
	while (a->stack[i] != data->a.size)
	{
		value = a->stack[i];
		i = next_down(a, i);
		if (a->stack[i] != value + 1)
			return (false);
	}
	return (true);
}

void	split_max_reduction(t_ps *data, t_chunk *max)
{
	t_stack	*a;

	a = &data->a;
	if (max->loc == TOP_A && max->size == 3 && is_consecutive(get_value(a, 1),
		 get_value(a, 2), get_value(a, 3), get_value(a, 4)) && a_partly_sort(data, 4))
	{
		sort_three(data, max);
		return ;
	}
	if (max->loc == TOP_A && get_value(a, 1) == get_value(a, 3) - 1
	&& a_partly_sort(data, 3))
	{
		swap_a(data);
		max->size--;
	}
	if (max->loc == TOP_A && a_partly_sort(data, 1))
		max->size--;
}
