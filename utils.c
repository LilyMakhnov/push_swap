/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esivre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:16:20 by esivre            #+#    #+#             */
/*   Updated: 2022/01/11 15:52:13 by esivre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				c = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = c;
			}
			j++;
		}
		i++;
	}
}

int	ft_atoi(const char *nbr)
{
	unsigned long	res;
	int				sign;

	res = 0;
	sign = 1;
	while (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13))
		nbr++;
	if (*nbr == '+' || *nbr == '-')
		if (*nbr++ == '-')
			sign *= -1;
	while (*nbr >= '0' && *nbr <= '9')
	{
		if (res > 2147483648 || (res == 2147483648 && sign == 1))
			quit(1, 0, 0);
		res = res * 10 + *nbr++ - '0';
	}
	if (res > 2147483648 || (res == 2147483648 && sign == 1))
		quit(1, 0, 0);
	return (sign * res);
}

void	ft_indexation(t_list **stack, int *tab, int size)
{
	int		i;
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] == tmp->value)
			{
				tmp->value = i + 1;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	ft_fill_stack(t_list **stack_a, int argc, char **argv)
{
	int		i;
	int		*tab;
	t_list	*tmp;

	*stack_a = ft_lst_create(ft_atoi(argv[1]));
	i = 1;
	while (argv[++i])
	{
		tmp = ft_lst_create(ft_atoi(argv[i]));
		if (!tmp)
			quit(1, stack_a, 0);
		ft_lst_pushback(stack_a, tmp);
	}
	tab = malloc(sizeof(int) * (argc - 1));
	if (!tab)
		quit(1, stack_a, 0);
	i = -1;
	while (++i + 1 < argc)
		tab[i] = ft_atoi(argv[i + 1]);
	ft_sort_int_tab(tab, argc - 1);
	ft_indexation(stack_a, tab, argc - 1);
	free(tab);
}

void	quit(int a, t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		ft_free_linkedlist(stack_a);
	if (stack_b)
		ft_free_linkedlist(stack_b);
	if (a == 1)
	{
		write (2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (a == 0)
		exit(EXIT_SUCCESS);
}
