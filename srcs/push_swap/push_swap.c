/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:53:50 by dong-hki          #+#    #+#             */
/*   Updated: 2025/01/09 16:22:20 by dong-hki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_ps	data;

	init_data(&data, argc, argv);
	sort(&data);
	print_ops(data.op_list);
	free_data(&data);
	return (0);
}
