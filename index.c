/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esivre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:14:38 by esivre            #+#    #+#             */
/*   Updated: 2021/12/07 17:14:42 by esivre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_lst(t_list *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->value;
	while (stack)
	{
		if (max < stack->value)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	get_min_lst(t_list *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->value;
	while (stack)
	{
		if (min > stack->value)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	get_index(t_list *stack, int nbr)
{
	int	index;

	index = 1;
	while (stack)
	{
		if (stack->value == nbr)
			return (index);
		stack = stack->next;
		index++;
	}
	return (0);
}

int	first_index_key_nbr(t_list *stack, int key_nbr)
{
	int	index;

	index = 1;
	while (stack)
	{
		if (stack->value <= key_nbr)
			return (index);
		stack = stack->next;
		index++;
	}
	return (0);
}

int	last_index_key_nbr(t_list *stack, int keynbr)
{
	int	index;
	int	i;

	i = 1;
	index = 0;
	while (stack)
	{
		if (stack->value <= keynbr)
			index = i;
		stack = stack->next;
		i++;
	}
	return (index);
}
