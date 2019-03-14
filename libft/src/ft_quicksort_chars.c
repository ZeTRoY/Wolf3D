/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 07:52:21 by aroi              #+#    #+#             */
/*   Updated: 2019/01/25 16:00:06 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		swap(char **first, char **second)
{
	char *tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

static int		partition(char **arr, int start, int end)
{
	char	*pivot;
	int		left;
	int		right;

	pivot = arr[end];
	left = start - 1;
	right = start;
	while (right <= end - 1)
	{
		if (ft_strcmp(arr[right], pivot) <= 0)
		{
			left++;
			swap(&arr[left], &arr[right]);
		}
		right++;
	}
	swap(&arr[left + 1], &arr[end]);
	return (left + 1);
}

void			ft_quicksort_chars(char **arr, int start, int end)
{
	int pivot;

	if (start >= end)
		return ;
	pivot = partition(arr, start, end);
	ft_quicksort_chars(arr, start, pivot - 1);
	ft_quicksort_chars(arr, pivot + 1, end);
}
