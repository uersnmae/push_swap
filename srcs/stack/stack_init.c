/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:04:51 by dong-hki          #+#    #+#             */
/*   Updated: 2025/01/08 15:51:22 by dong-hki         ###   ########.fr       */
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

void	fill_stack(t_ps *data, t_stack *stk, int size, char *argv[])
{
	int	*numbers;
	int	i;

	numbers = (int *)malloc(sizeof(int) * size);
	if (!numbers)
		error(data);
	i = 0;
	while (arr[i])
	{
		if (!valid_arg(argv))
			error(data);
		numbers[i] = ft_atoi[i];
		i++;
	}
	ranking(numbers, stk->stack, size);
	free(numbers);
}

void	ranking(int *numbers, int *stack, int size)
{
	int	i;
	int	j;
	int	min_counter;

	i = 0;
	while (i < size)
	{
		j = 0;
		min_counter = 0;
		while (j < size)
			if (numbers[j++] <= numbers[i])
				min_counter++;
		stack[i++] = min_counter;
	}
}
