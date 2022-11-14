/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:54:12 by asasada           #+#    #+#             */
/*   Updated: 2022/11/06 14:54:13 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	abs_int(int a)
{
	if (a == INT_MIN)
		return (INT_MAX);
	if (a < 0)
		return (a * -1);
	return (a);
}
