/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:04:23 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/24 12:41:15 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_split_stack(t_ctl **a_ctl, t_ctl **b_ctl, int size)
{
	int		i;
	int		o;
	int		median;

	if ((*a_ctl)->size == 0)
		return ;
	median = ft_get_medstack(a_ctl, size);
	i = 0;
	o = 0;
	while (i < size)
	{
		if ((*a_ctl)->first->index <= median)
		{
			if ((*a_ctl)->first->index == median)
				(*a_ctl)->first->status = 1;
			ft_pb(a_ctl, b_ctl, 1);
			if ((*b_ctl)->first->index == median)
				ft_rb(b_ctl, 1);
		}
		else
			ft_ra(a_ctl, 1);
		i++;	
	}
	ft_rrb(b_ctl, 1);
}

int			ft_get_stack_part(t_ctl *ctl)
{
	int		stack_part;
	t_node	*stack;

	stack = ctl->first;
	stack_part = 0;
	while (stack && stack->status != 1)
	{
		stack_part++;
		stack = stack->next;
	}
	return (stack_part);
}

void		ft_debugread(void)
{
	char	line[5];
	int		ret;

	ret = read(0, line, 5);
	line[ret] = '\0';
}

int			ft_push_swap(t_ctl *a_ctl, t_ctl *b_ctl)
{
	int		stack_part;
	int		stack_part_cpy;
	int		stack_part_cpy2;

	while (a_ctl->size != 1)
		ft_split_stack(&a_ctl, &b_ctl, a_ctl->size, 0);
	while (b_ctl->size != 0)
	{
		if (b_ctl->first->status == 1)
		{
			PSTR("ON PUSH DIRECT")	
			ft_pa(&b_ctl, &a_ctl, 1);
			ft_putnode(a_ctl->first, b_ctl->first);
		}
		else if ((stack_part = ft_get_stack_part(b_ctl)) > 2)
		{
			PSTR("ON REPUSH SUR A")	
			stack_part_cpy = stack_part;
			stack_part_cpy2 = stack_part;
			while (stack_part-- > 0)
				ft_pa(&b_ctl, &a_ctl, 1);	
			ft_putnode(a_ctl->first, b_ctl->first);
			PSTR("ON RECALCULE UNE MEDIANE SUR NOTRE PORTION DE STACK : ")	
			ft_split_stack(&a_ctl, &b_ctl, stack_part_cpy, 1);
			ft_putnode(a_ctl->first, b_ctl->first);
		}
		else
		{
			PSTR("ON TRIE DIRECT")
			if (ft_is_dsort(&b_ctl) > 2)
				ft_sb(&b_ctl, 1);
			ft_pa(&b_ctl, &a_ctl, 1);
			ft_pa(&b_ctl, &a_ctl, 1);
			ft_putnode(a_ctl->first, b_ctl->first);
		}	
		ft_debugread();
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_node	*stack_a;
	t_ctl	*a;
	t_ctl	*b;

	stack_a = NULL;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if ((ft_init_ctl(&a, &b)) == -1)
		return (ft_exit_ps(&a, &b));
	if ((ft_fill_node(&stack_a, &a, av)) == -1)
		return (ft_exit_ps(&a, &b));
	if ((ft_push_swap(a, b)) == -1)
		return (-1);
	return (0);
}
