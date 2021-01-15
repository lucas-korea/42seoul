/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 11:31:29 by cjung             #+#    #+#             */
/*   Updated: 2021/01/12 04:28:28 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_unbrlen(t_info *info, __uint64_t n)
{
	size_t	len;
	size_t	den;

	len = 0;
	den = (size_t)info->nbr_base;
	while (n >= den)
	{
		n = n / den;
		len++;
	}
	len++;
	if (info->type == 'p')
		len = len + 2;
	return (len);
}

size_t	ft_nbrlen(t_info *info, int n)
{
	size_t	len;
	int		den;
	int		dum;

	len = 0;
	den = info->nbr_base;
	dum = n;
	if (n == INT_MIN)
		dum = -(INT_MIN + 1);
	else if (n < 0)
	{
		len++;
		dum = -n;
	}
	while (dum >= 0)
	{
		len++;
		dum = dum / den;
		if (dum == 0)
			break ;
	}
	return (len);
}
