/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esivre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:12:05 by esivre            #+#    #+#             */
/*   Updated: 2021/12/07 17:12:09 by esivre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_r(t_list **stack_a, char a)
{
	t_list	*tmp;
	t_list	*first;

	if (*stack_a && (*stack_a)->next)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		first = *stack_a;
		tmp->next = NULL;
		while ((*stack_a)->next)
		{
			*stack_a = (*stack_a)->next;
		}
		(*stack_a)->next = tmp;
		*stack_a = first;
		write(1, "r", 1);
		write(1, &a, 1);
		write(1, "\n", 1);
	}
}

void	ft_rr(t_list **stack_a, char a)
{
	t_list	*first;
	t_list	*tmp;

	if (*stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		while ((*stack_a)->next->next)
		{
			*stack_a = (*stack_a)->next;
		}
		tmp = (*stack_a)->next;
		(*stack_a)->next = NULL;
		(*stack_a) = first;
		tmp->next = *stack_a;
		*stack_a = tmp;
		write(1, "rr", 2);
		write(1, &a, 1);
		write(1, "\n", 1);
	}
}

void	ft_s(t_list **stack_a, char a)
{
	t_list	*tmp;

	if (*stack_a && (*stack_a)->next)
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = (*stack_a)->next->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
		write (1, "s", 1);
		write(1, &a, 1);
		write(1, "\n", 1);
	}
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b)
	{
		tmp = (*stack_b)->next;
		(*stack_b)->next = *stack_a;
		*stack_a = *stack_b;
		*stack_b = tmp;
		write(1, "pa\n", 3);
	}
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_a)
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = *stack_b;
		*stack_b = *stack_a;
		*stack_a = tmp;
		write(1, "pb\n", 3);
	}
}
