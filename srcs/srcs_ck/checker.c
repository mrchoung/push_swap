/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:30:35 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/10 17:27:05 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnode(t_node *node)
{
	ft_printf("data : {grey}%d{eoc} - data->prev : {cyan}NULL{eoc}\n", node->data);
	node = node->next;
	while (node)
	{
		ft_printf("data : {grey}%d{eoc} - data->prev : {cyan}%d{eoc}\n", node->data, node->prev->data);
		node = node->next;
	}
}

int	ft_exit_ck(t_node **node)
{
	// free if exist
	(void)node;
	ft_printf("Error\n");
	return (-1);
}

t_node	*ft_new_node(char *integer, int *pi, t_node *prev)
{
	t_node	*node;

	if (!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	node->data = ft_atoi(integer);
	if (node->data < INT_MAX || node->data < INT_MIN)
		return (NULL);
	*pi += ft_ilen(node->data, 10);
	node->next = NULL;
	node->prev = prev;
	return (node);
}

int	ft_fill_node(t_node **node, char *ints)
{
	t_node	*tmp;
	t_node	*prev;
	int		i;
	int		*pi;

	tmp = NULL;
	i = 0;
	pi = &i;	
	while (ints[i] && ft_isdigit(ints[i]) == ' ')
		i++;	
	if (ints[i] == '\0' || ft_isdigit(ints[i]) == 0)
		return (-1);
	if (!(*node = ft_new_node(ints + i, pi, NULL)))
		return (-1);
	tmp = *node;
	while (ints[i])
	{
		if (ints[i] != ' ' || ft_isdigit(ints[i]) == 0)
			return (-1);
		else if (ft_isdigit(ints[i]))
		{
			prev = tmp;
			if (!(tmp->next = ft_new_node(ints + i, pi, prev)))
				return (-1);
			tmp = tmp->next;
		}
		else
			i++;
	}
	ft_putnode(*node);
	return (1);
}

int	main(int ac, char **av)
{
	t_node	*node;

	(void)av;
	if (ac == 1)
		return (ft_exit_ck(&node));
	node = NULL;
	if ((ft_fill_node(&node, av[1])) == -1)		
		return (ft_exit_ck(&node));
	return (0);
}
