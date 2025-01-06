/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:04:51 by dong-hki          #+#    #+#             */
/*   Updated: 2025/01/06 17:50:16 by dong-hki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_put_num_stack(t_stack **container, char **splited, int *stack_size);
static void	ft_valid_arg(char *_argv);
static void	ft_free_split(char **splited);

int	ft_init_stack(int stack_cnt, char **argv, t_stack *container)
{
	int		index;
	char	**splited;

	if (!argv || !container)
		return (0);
	index = 0;
	container->stack = malloc(sizeof(int) * (container->size));
	if (!container->stack)
		error();
	while (++index < stack_cnt)
	{
		splited = ft_split(argv[index], ' ');
		if (!splited)
			error();
		if (!ft_put_num_stack(container, splited))
			error();
		ft_free_split(splited);
	}
	return (1);
}

static void	ft_put_num_stack(t_stack *container, char **splited)
{
	int	index;
	int	stack_index;

	index = -1;
	stack_index = 0;
	while (splited[++index])
	{
		if (!ft_valid_arg(splited[index]))
		{
			ft_free_split(splited);
			error();
		}
		(container->stack)[stack_index] = ft_atoi(splited[index]);
		(*stack_size)++;
	}
}

static void	ft_valid_arg(char *_argv)
{
	int	index;
	int	len;
	int	tmp_value;

	index = 0;
	while (ft_isspace(_argv[index]))
		index++;
	if (_argv[index] == '+' || _argv[index] == '-')
		index++;
	while (_argv[index])
	{
		len = ft_strlen(_argv + index);
		tmp_value = ft_atoi(_argv);
		if (!ft_isdigit(_argv[index]) || (tmp_value == 0 && len != 1))
			error();
		index++;
	}
}

static void	ft_free_split(char **splited)
{
	int	index;

	index = -1;
	while (splited[++index])
		free(splited[index]);
	free(splited);
}


