/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:24:57 by cjung             #+#    #+#             */
/*   Updated: 2021/01/15 15:24:58 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_unbr(unsigned int n, t_info *info)
{
	size_t	i;
	int		flag3;

	i = 0;
	flag3 = 1;
	if (info->colon == 1 && info->c_width == 0 && n == 0)
	{
		while (i++ < (unsigned)info->width)
			ft_putchar_fd(' ', 1);
		return ((unsigned)info->width);
	}
	if ((int)ft_unbrlen(info, n) < info->width || \
	(int)ft_unbrlen(info, n) < info->c_width + 1)
	{
		if (info->minus)
			print_unbr_minus(n, info, i);
		else
			print_unbr_else(n, info, i);
	}
	else
		ft_putunbr_fd(n, 1);
	if (info->c_width > info->width)
		info->width = info->c_width;
	return (ft_unbrlen(info, n) > (size_t)info->width ?
	ft_unbrlen(info, n) : (size_t)info->width);
}

void	print_unbr_minus(unsigned n, t_info *info, size_t i)
{
	if ((info->c_minus && info->c_wild) || \
	((int)ft_unbrlen(info, n) < info->c_width && info->c_wild) || info->minus)
	{
		while ((int)(ft_nbrlen(info, n) + i) < info->c_width && !info->c_minus)
		{
			ft_putchar_fd('0', 1);
			i++;
		}
		while ((int)(ft_nbrlen(info, n) + i) < info->width && !info->minus)
		{
			if (info->zero)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			i++;
		}
	}
	if (n == 0 && !info->c_wild && info->c_width > 0 && info->c_minus)
		ft_putchar_fd(' ', 1);
	else
		ft_putunbr_fd(n, 1);
	if (info->c_minus && !info->c_wild)
		info->width = info->c_width;
	while (ft_unbrlen(info, n) + i++ < (unsigned)info->width)
		ft_putchar_fd(' ', 1);
}

void	print_unbr_else(unsigned n, t_info *info, size_t i)
{
	if (info->c_minus)
		return (print_unbr_minus(n, info, i));
	if (info->c_width >= 0)
	{
		while ((int)(ft_unbrlen(info, n) + i) < info->width || \
		(int)(ft_unbrlen(info, n) + i) < info->c_width)
		{
			if (info->zero)
				print_unbr_zero(info, i);
			else
			{
				if (info->width - info->c_width <= (int)i && \
				(int)ft_unbrlen(info, n) < info->c_width)
					ft_putchar_fd('0', 1);
				else
					ft_putchar_fd(' ', 1);
			}
			i++;
		}
	}
	ft_putunbr_fd(n, 1);
}

void	print_unbr_zero(t_info *info, size_t i)
{
	if (info->colon && info->width > info->c_width)
	{
		if ((int)i >= info->width - info->c_width)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
	}
	else
		ft_putchar_fd('0', 1);
}
