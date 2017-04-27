/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:31:41 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/27 17:03:32 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_rotate(t_ctl **ctl)
{
	t_node	*tmpfirst;
	t_node	*tmplast;

	if ((*ctl)->size < 2)
		return ;
	tmpfirst = (*ctl)->first;
	tmplast = (*ctl)->last;
	(*ctl)->first->next->prev = NULL;
	(*ctl)->first = (*ctl)->first->next;
	(*ctl)->last->next = tmpfirst;
	(*ctl)->last = (*ctl)->last->next;
	(*ctl)->last->prev = tmplast;
	(*ctl)->last->next = NULL;
}

void		ft_ra(t_ctl **ctl, int ps)
{
	ft_rotate(ctl);
	if (ps == 1)
		ft_putendl(RA);
}

void		ft_rb(t_ctl **ctl, int ps)
{
	ft_rotate(ctl);
	if (ps == 1)
		ft_putendl(RB);
}

void		ft_rr(t_ctl **a, t_ctl **b, int ps)
{
	ft_rotate(a);
	ft_rotate(b);
	if (ps == 1)
		ft_putendl(RR);
}
