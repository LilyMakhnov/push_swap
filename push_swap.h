/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esivre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:15:44 by esivre            #+#    #+#             */
/*   Updated: 2022/01/11 16:01:58 by esivre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list	t_list;

struct s_list
{
	int		value;
	t_list	*next;
};

///////////////////////////INDEX///////////////////////////////

int		get_max_lst(t_list *stack);
int		get_min_lst(t_list *stack);
int		get_index(t_list *stack, int nbr);
int		first_index_key_nbr(t_list *stack, int key_nbr);
int		last_index_key_nbr(t_list *stack, int keynbr);

///////////////////////////SORT/////////////////////////////

void	three_sort(t_list **stack_a);
void	small_sort(t_list **stack_a, t_list **stack_b);
void	big_sort(t_list **stack_a, t_list **stack_b, int chunck);
void	sort_chunk(t_list **stack_a, t_list **stack_b, int keynbr);
void	radix_sort(t_list **stack_a, t_list **stack_b, int size);

/////////////////////////LINKEDLIST////////////////////////

t_list	*ft_lst_create(int number);
int		ft_lst_size(t_list *liste);
void	ft_lst_pushback(t_list **liste, t_list *element);
void	ft_free_linkedlist(t_list **liste);

////////////////////////////UTILS/////////////////////////

int		ft_atoi(const char *nbr);
void	ft_indexation(t_list **stack, int *tab, int size);
void	quit(int a, t_list **stack_a, t_list **stack_b);
void	ft_sort_int_tab(int *tab, int size);
void	ft_fill_stack(t_list **stack_a, int argc, char **argv);

///////////////////////OPERATIONS/////////////////////////

void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_r(t_list **stack_a, char a);
void	ft_rr(t_list **stack_a, char a);
void	ft_s(t_list **stack_a, char a);

////////////////////////MAIN////////////////////////////////

void	check_solve(t_list **stack_a);
void	ft_check_digit(char **argv);
void	ft_check_doublon(char **argv);
void	solve(t_list **stack_a, t_list **stack_b, int argc);

#endif
