#include <stdlib.h>
#include <stdio.h>

void push(int *a, int *b)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (a[i])
		i++;
	i--;
	while (b[j])
		j++;
	b[j] = a[i];
	a[i] = 0;
//	printf("push\n");
}
/*
void rotate_rev(int *a)
{
	int tmp;
	int tmp2;
	int i;
	int j;

	i = 0;
	while (a[i])
		i++;
	i--;

	tmp = a[0];
	a[i]= a[0];
	j = 1;
	while (j < i)
	{
		tmp2 = a[j];
		a[j]= tmp;
		tmp = a[j+1];
		a[j+1] = tmp2;
		j++;
		j++;
	}
}*/

void link(int *a, int*b)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (a[i])
		i++;
	while (b[j])
	{
		a[i++] = b[j];
		b[j++] = 0;
	}
}

void rotate(int *a)
{
	int tmp;
	int tmp2;
	int i;
	int j;

	i = 0;
	while (a[i])
		i++;
	i--;

	tmp = a[0];
	a[0]= a[i];
	j = 1;
	while (j < i)
	{
		tmp2 = a[j];
		a[j]= tmp;
		tmp = a[j+1];
		a[j+1] = tmp2;
		j++;
		j++;
	}
	if (i % 2)
	{
		a[j] = tmp;
	}
//	printf("r\n");
}

void print_tab(int *a)
{
	int i;

	i = 0;
	while (a[i])
		printf("%d, ", a[i++]);
	printf("\n");
}


void	ft_sort_int_tab(int *tab, int size)
{
	int swap;
	int i;
	int j;

	i = size - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < i)
		{
			if (tab[i] < tab[j])
			{
				swap = tab[i];
				tab[i] = tab[j];
				tab[j] = swap;
			}
			j++;
		}
		i--;
	}
}

int main(void)
{
	int tab_input[10] = {10, 100, 20, 45, 89, 1, 27, 47, 2, 0};
	int tab_a[10] = {0};
	int tab_b[10] = {0};
	int i;
	int j;
	int k;
	print_tab(tab_input);

	i = -1;
	while (tab_input[++i])
		tab_a[i] = tab_input[i];
	ft_sort_int_tab(tab_input, 9);
	print_tab(tab_input);
	print_tab(tab_a);
	i = 0;
	while (tab_a[i])
	{
		j = 0;
		while (tab_input[j])
		{
			if (tab_a[i] == tab_input[j])
				tab_a[i] = j + 1;
			j++;
		}
		i++;
	}
	//	rotate(tab_a);
//	push(tab_a, tab_b);
	print_tab(tab_a);
//	rotate(tab_a);
//	rotate(tab_a);
//	rotate(tab_a);
	j = 0;
	while ((1 << j) < 9)
	{
		i = 0;
		while (i++ < 9)
		{
			k = 0;
			while (tab_a[k])
				k++;
			k--;
			if (tab_a[k] & 1 << j)
				rotate(tab_a);
			else
				push(tab_a, tab_b);
		}
		while (tab_b[0])
			push(tab_b, tab_a);
		j++;
	}
	print_tab(tab_a);
	return (0);
}
