/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:38:28 by dong-hki          #+#    #+#             */
/*   Updated: 2025/01/11 19:44:43 by dong-hki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_ps *data)
{
	t_chunk	chunk_all;

	chunk_all.loc = TOP_A;
	chunk_all.size = data->a.size;
	rec_chunk_sort(data, &chunk_all);
}

void	rec_chunk_sort(t_ps *data, t_chunk *to_sort)
{
	t_split_dest	dest;

	chunk_to_top(data, to_sort);
	if (to_sort->size <= 3)
	{
		if (to_sort->size == 3)
			sort_three(data, to_sort);
		else if (to_sort->size == 2)
			sort_two(data, to_sort);
		else if (to_sort->size == 1)
			sort_one(data, to_sort);
		return ;
	}
}
