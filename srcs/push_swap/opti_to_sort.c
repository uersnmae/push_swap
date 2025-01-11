/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_to_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:51:27 by dong-hki          #+#    #+#             */
/*   Updated: 2025/01/11 19:00:56 by dong-hki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_to_top(t_ps *data, t_chunk *to_sort)
{
	if (to_sort->loc == BOTTOM_B && curr_size(&data->b) == to_sort->size)
		to_sort->loc = TOP_B;
	if (to_sort->loc == BOTTOM_A && curr_size(&data->a) == to_sort->size)
		to_sort->loc = TOP_A;
}
