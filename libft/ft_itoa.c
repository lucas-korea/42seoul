/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:16:40 by cjung             #+#    #+#             */
/*   Updated: 2020/12/26 09:15:14 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*set_itoa(int n, int len, int sign)
{
	char	*result;

	if (!(result = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	result[len--] = 0;
	while (n > 0)
	{
		result[len--] = n % 10 + 48;
		n = n / 10;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	int		dum;
	int		len;
	int		sign;

	len = 0;
	sign = 1;
	dum = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = -1;
		len++;
		dum = -n;
		n = -n;
	}
	if (n == 0)
		return (ft_strdup("0"));
	while (dum > 0)
	{
		dum = dum / 10;
		len++;
	}
	return (set_itoa(n, len, sign));
}
