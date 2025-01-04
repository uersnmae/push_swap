#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

typedef	struct s_stack
{
	int	*stack;
	int	size;
	int	top;
	int	bottom;
}	t_stack

typedef	s_push_swap
{
	t_stack	a;
	t_stack	b;
	t_list	*op_list;
	bool	writing_mode;
}	t_ps;

enum	e_op
{
	null_op,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	sa,
	sb,
	ss
};

#endif
