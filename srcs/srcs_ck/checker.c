/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:30:35 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/10 19:35:59 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_node	*node;

	(void)av;
	if (ac == 1)
		return (ft_exit_pushswap(&node));
	node = NULL;
	if ((ft_fill_node(&node, av[1])) == -1)		
		return (ft_exit_pushswap(&node));
	// read operations
	// make operations
	// check result
	return (0);
}