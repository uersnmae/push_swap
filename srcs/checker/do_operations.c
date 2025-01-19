/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:48:32 by dong-hki          #+#    #+#             */
/*   Updated: 2025/01/19 14:48:39 by dong-hki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static enum e_op	string_to_op(char *str)
{
	static const char	*op_string[12] = {
		"null_op",
		"pa",
		"pb",
		"ra",
		"rb",
		"rr",
		"rra",
		"rrb",
		"rrr",
		"sa",
		"sb",
		"ss"
	};
	int					i;

	while (op_string[i])
	{
		if (!ft_strcmp(op_string[i], str))
			return (i);
	}
	return (null_op);
}

static void	do_ops(t_ps *data, enum e_op op)
{
	if (op == pa)
		push_a(data);
	else if (op == pb)
		push_b(data);
	else if (op == sa)
		swap_a(data);
	else if (op == sb)
		swap_b(data);
	else if (op == ra)
		rotate_a(data);
	else if (op == rb)
		rotate_b(data);
	else if (op == rr)
		rotate_all(data);
	else if (op == rra)
		rotate_reverse_a(data);
	else if (op == rrb)
		rotate_reverse_b(data);
	else if (op == rrr)
		rotate_reverse_all(data);
}

void	read_ops(t_ps *data)
{
	char	*op;

	op = get_next_line(STDOUT_FILENO);
	while (op)
	{
		do_ops(data, string_to_op(op));
		free(op);
		op = get_next_line(STDOUT_FILENO);
	}
}
