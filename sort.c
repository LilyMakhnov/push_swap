/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esivre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:15:57 by esivre            #+#    #+#             */
/*   Updated: 2021/12/09 22:08:35 by esivre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_list **stack_a)
{
	int	i;
	int	j;
	int	k;

	i = (*stack_a)->value;
	j = (*stack_a)->next->value;
	k = (*stack_a)->next->next->value;
	if (k > i && i > j)
		ft_s(stack_a, 'a');
	if (i > j && j > k)
	{
		ft_s(stack_a, 'a');
		ft_rr(stack_a, 'a');
	}
	if (i > k && k > j)
		ft_r(stack_a, 'a');
	if (i < k && k < j)
	{
		ft_s(stack_a, 'a');
		ft_r(stack_a, 'a');
	}
	if (i > k && j > i)
		ft_rr(stack_a, 'a');
}

void	small_sort(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int	i;

	i = 0;
	while (ft_lst_size(*stack_a) > 3)
	{
		index = get_index(*stack_a, get_min_lst(*stack_a));
		while (index != 1)
		{	
			if (ft_lst_size(*stack_a) / 2 > index)
				ft_r(stack_a, 'a');
			else
				ft_rr(stack_a, 'a');
			index = get_index(*stack_a, get_min_lst(*stack_a));
		}
		ft_pb(stack_a, stack_b);
		i++;
	}
	three_sort(stack_a);
	while (i--)
		ft_pa(stack_a, stack_b);
}

void	big_sort(t_list **stack_a, t_list **stack_b, int chunck)
{
	int	i;
	int	index;
	int	keynbr;

	keynbr = ft_lst_size(*stack_a) / chunck;
	i = 0;
	while (++i < chunck)
		sort_chunk(stack_a, stack_b, i * keynbr);
	small_sort(stack_a, stack_b);
	while (*stack_b)
	{
		index = get_index(*stack_b, get_max_lst(*stack_b));
		while (index != 1)
		{
			if (ft_lst_size(*stack_b) / 2 > index && index != 2)
				ft_r(stack_b, 'b');
			else if (index == 2)
				ft_s(stack_b, 'b');
			else
				ft_rr(stack_b, 'b');
			index = get_index(*stack_b, get_max_lst(*stack_b));
		}
		ft_pa(stack_a, stack_b);
	}
}

void	sort_chunk(t_list **stack_a, t_list **stack_b, int keynbr)
{
	int	index;

	index = first_index_key_nbr(*stack_a, keynbr);
	while (index)
	{
		if (index == 1)
			ft_pb(stack_a, stack_b);
		else if (ft_lst_size(*stack_a) / 2 > index)
			ft_r(stack_a, 'a');
		else
			ft_rr(stack_a, 'a');
		index = first_index_key_nbr(*stack_a, keynbr);
	}
}

void	radix_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	j;
	int	i;

	j = 0;
	while ((1 << j) <= size)
	{
		i = 0;
		while (i++ < size)
		{
			if ((*stack_a)->value & 1 << j)
				ft_r(stack_a, 'a');
			else
				ft_pb(stack_a, stack_b);
		}
		while (*stack_b)
			ft_pa(stack_a, stack_b);
		j++;
		check_solve(stack_a);
	}
}

int below(int value, t_list *stack)
{
	int below;

	below = 0;
	while (stack)
	{
		if (stack->value < value)
			if (below < stack->value)
				below = stack->value;
		stack = stack->next;
	}
	return (below);
}

int cout_stack_b(int value, t_list *stack_b)
{
	int cout;
	int index;

	index = get_index(stack_b, below(value, stack_b));
	if (index == 0)
		index = get_index(stack_b, get_min_lst(stack_b));
	if (ft_lst_size(stack_b) / 2 > index)
			cout = index - 1;
		else
			cout = ft_lst_size(stack_b) - index;
	return (cout);
}

int cout_stack_a(int value, t_list *stack_a)
{
	int cout;
	int index;

	index = get_index(stack_a, value);
	if (ft_lst_size(stack_a) / 2 > index)
			cout = index - 1;
		else
			cout = ft_lst_size(stack_a) - index;
	return (cout);
}

int lowest_cost(t_list *stack_a, t_list *stack_b)
{
	int cout;
	int low_cout;
	int value;

	low_cout = cout_stack_b(stack_a->value, stack_b) 
			 + cout_stack_a(stack_a->value, stack_a);
	value = stack_a->value;
	while (stack_a)
	{
		cout = cout_stack_b(stack_a->value, stack_b) 
			 + cout_stack_a(stack_a->value, stack_a);
		if (low_cout < cout)
		{
			low_cout = cout;
			value = stack_a->value;
		}
		stack_a = stack_a->next;
	}
	return (value);
}

#include <stdio.h>

void	jonathan_sort(t_list **stack_a, t_list **stack_b)
{
	int value_low_moov;
	int index;

	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);

	while (*stack_a)
	{
		value_low_moov = lowest_cost(*stack_a, *stack_b);
		//printf("value low : %d\n", value_low_moov);
		index = get_index(*stack_a, value_low_moov);
		while (index != 1)
		{	
			if (ft_lst_size(*stack_a) / 2 > index)
				ft_r(stack_a, 'a');
			else
				ft_rr(stack_a, 'a');
			index = get_index(*stack_a, value_low_moov);
		}
		index = get_index(*stack_b, below(value_low_moov, *stack_b));
		if (index == 0)
			index = get_index(*stack_b, get_max_lst(*stack_b));
		while (index != 1)	
		{	
			if (ft_lst_size(*stack_b) / 2 > index)
				ft_r(stack_b, 'b');
			else
				ft_rr(stack_b, 'b');
			index = get_index(*stack_b, below(value_low_moov, *stack_b));
			if (index == 0)
				index = get_index(*stack_b, get_max_lst(*stack_b));
		}
		ft_pb(stack_a, stack_b);
	}
	while (get_index(*stack_b, get_max_lst(*stack_b)) != 1)
	{
		if (ft_lst_size(*stack_b) / 2 > get_index(*stack_b, get_max_lst(*stack_b)))
			ft_r(stack_b, 'b');
		else
			ft_rr(stack_b, 'b');
	}
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}
/*
void	jonathan_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	j;
	int	i;
	int tab *i;
	int indextomove;
	t_list tmp;





	tab = malloc(sizeof(int) * ft_lst_size(*stack_a));

	i = -1;
	while (++i < ft_lst_size(*stack_a) / 2)
		tab[i] = i;
	j = i - 1; 
	while (++i < ft_lst_size(*stack_a))
		tab[i] = j--;

	i = -1
	tmp = *stack_a;
	while (++i < ft_lst_size(*stack_a))
	{
		if(tmp->value > get_max_lst(*stack_b))
			tab[i] += get_index(get_max_lst(*stack_b));
		if (tmp->next)
			tmp = tmp->next;	
	}
	int min;
	min = tab[0];
	indextomove = 1;

	i = -1
	while (++i < ft_lst_size(*stack_a))
	{
		if (min > tab[i])
		{
			min = tab[i];
			indextomove = i+1;
		}
	}
	free(tab);
}*/
