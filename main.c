/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esivre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:15:29 by esivre            #+#    #+#             */
/*   Updated: 2021/12/07 17:15:35 by esivre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_solve(t_list **stack_a)
{
	int		tmp;
	t_list	*tmp_lst;

	tmp_lst = *stack_a;
	while (tmp_lst && tmp_lst->next)
	{
		tmp = tmp_lst->value;
		tmp_lst = tmp_lst->next;
		if (tmp_lst->value < tmp)
			return ;
	}
	quit(1, stack_a, 0);
}

void	ft_check_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (!argv[1][0])
		quit(0, 0, 0);
	while (argv[i])
	{
		j = 0;
		if (!((argv[i][j] <= '9' && argv[i][j] >= '0')
			|| argv[i][j] == '-' || argv[i][j] == '+'))
			quit(0, 0, 0);
		j++;
		if (!argv[i][j])
			if (argv[i][j - 1] == '-' || argv[i][j - 1] == '+')
				quit(0, 0, 0);
		while (argv[i][j])
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
				quit(0, 0, 0);
			j++;
		}
		i++;
	}
}

void	ft_check_doublon(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = i;
		while (argv[++j])
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				quit(0, 0, 0);
	}
}

void	solve(t_list **stack_a, t_list **stack_b, int argc)
{
	(void)argc;
	check_solve(stack_a);
	jonathan_sort(stack_a, stack_b);
	/*
	if (argc > 400)
		radix_sort(stack_a, stack_b, argc - 1);
	if (argc <= 400 && argc > 200)
		big_sort(stack_a, stack_b, 12);
	if (argc <= 200 && argc > 50)
		big_sort(stack_a, stack_b, 5);
	if (argc > 3 && argc <= 50)
		small_sort(stack_a, stack_b);
	if (argc == 3)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			ft_s(stack_a, 'a');
	}*/
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (0);
	ft_check_digit(argv);
	ft_check_doublon(argv);
	ft_fill_stack(&stack_a, argc, argv);
	stack_b = NULL;
	solve(&stack_a, &stack_b, argc);
	quit(1, &stack_a, &stack_b);
}
