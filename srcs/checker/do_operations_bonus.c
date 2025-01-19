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

#include "checker_bonus.h"

static enum e_op	string_to_op(char *str)
{
	static const char	*op_string[12] = {
		"null_op", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr", "sa", "sb", "ss"};
	int					i;
	size_t				len;

	i = 0;
	len = ft_strlen(str);
	if (str[len - 1] == '\n')
		--len;
	while (op_string[i])
	{
		if (!ft_strncmp(op_string[i], str, len))
			return (i);
		++i;
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
	char		*op;
	bool		flag;
	enum e_op	convert;

	op = get_next_line(STDIN_FILENO);
	flag = false;
	while (op)
	{
		convert = string_to_op(op);
		if (convert == null_op)
		{
			flag = true;
			break ;
		}
		do_ops(data, convert);
		free(op);
		op = get_next_line(STDIN_FILENO);
	}
	free(op);
	if (flag)
		error(data);
}
