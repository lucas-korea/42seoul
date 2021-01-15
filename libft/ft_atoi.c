/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:24:57 by cjung             #+#    #+#             */
/*   Updated: 2020/12/27 00:34:51 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int		ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int		check_over_range(unsigned long long sum, int sign)
{
	if (sum > LLONG_MAX - 1 && sign == -1)
		return (0);
	if (sum > LLONG_MAX && sign == 1)
		return (-1);
	return (sum * sign);
}

int		ft_atoi(const char *str)
{
	unsigned long long		nbr;
	int						sign;

	nbr = 0;
	sign = 1;
	while (*str != 0 && ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (*str != 0 && *str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	return (check_over_range(nbr, sign));
}
