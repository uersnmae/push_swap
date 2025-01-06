/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:05:19 by dong-hki          #+#    #+#             */
/*   Updated: 2025/01/06 11:20:48 by dong-hki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_init_stack(int stack_cnt, char **argv, t_stack *stacks, int *stack_size)
{
	int		index;
	char	**splited;

	if (!argv || !stacks)
		return (0);
	index = 0;
	while (++index < stack_cnt)
	{
		splited = ft_split(argv[index], ' ');
		if (!splited)
			return (0);
		if (!ft_put_num_stack(stacks, splited, stack_size))
			return (0);
		ft_free_split(splited);
	}
	return (1);
}

static int	ft_put_num_stack(t_stack **stacks, char **splited, int *stack_size)
{
	int	index;

	index = -1;
	while (splited[++index])
	{
		if (!ft_valid_arg(splited[index]))
		{
			ft_free_split(splited);
			return (0);
		}
		ft_stack_add_back(stacks, ft_stacknew(ft_atoi(splited[index])));
		(*stack_size)++;
	}
	return (1);
}

static int	ft_valid_arg(char *_argv)
{
	int	index;

	index = 0;
	while (ft_isspace(_argv[index]))
		index++;
	if (_argv[index] == '+' || _argv[index] == '-')
		index++;
	while (_argv[index])
	{
		if (!ft_isdigit(_argv[index]))
			return (0);
		index++;
	}
	return (1);
}

static void	ft_free_split(char **splited)
{
	int	index;

	index = -1;
	while (splited[++index])
		free(splited[index]);
	free(splited);
}

void	error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
