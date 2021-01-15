/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:24:57 by cjung             #+#    #+#             */
/*   Updated: 2021/01/15 13:12:07 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_hex(unsigned n, t_info *info, int uorl)
{
	size_t	i;

	i = 0;
	if (info->colon == 1 && info->c_width == 0 && n == 0)
	{
		while (i++ < (unsigned)info->width)
			ft_putchar_fd(' ', 1);
		return ((unsigned)info->width);
	}
	if ((unsigned)info->width > ft_unbrlen(info, n) ||
	(unsigned)info->c_width + 1 > ft_unbrlen(info, n))
	{
		if (info->minus)
			print_hex_minus(n, info, uorl, i);
		else
			print_hex_else(n, info, uorl, i);
	}
	else
		ft_puthex_fd(n, uorl, 1);
	if (info->c_width > info->width)
		info->width = info->c_width;
	return (ft_unbrlen(info, n) > (size_t)info->width ?
	ft_unbrlen(info, n) : (size_t)info->width);
}

void	print_hex_minus(unsigned n, t_info *info, int uorl, size_t i)
{
	if ((info->c_minus && info->c_wild) || \
	((int)ft_unbrlen(info, n) < info->c_width && info->c_wild) || info->minus)
	{
		while ((int)(ft_nbrlen(info, n) + i) < info->c_width && \
		info->c_minus == 0)
		{
			ft_putchar_fd('0', 1);
			i++;
		}
		while ((int)(ft_unbrlen(info, n) + i) < info->width && !info->minus)
		{
			if (info->zero)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			i++;
		}
	}
	ft_puthex_fd(n, uorl, 1);
	while (ft_unbrlen(info, n) + i++ < (unsigned)info->width)
		ft_putchar_fd(' ', 1);
}

void	print_hex_else(unsigned n, t_info *info, int uorl, size_t i)
{
	int	flag3;

	flag3 = 1;
	if (info->c_minus)
		return (print_hex_minus(n, info, uorl, i));
	while ((int)(ft_unbrlen(info, n) + i) < info->width || \
	(int)(ft_unbrlen(info, n) + i) < info->c_width)
	{
		if (info->zero)
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
		else
			print_hex_else2(n, info, i);
		i++;
	}
	ft_puthex_fd(n, uorl, 1);
}

void	print_hex_else2(unsigned n, t_info *info, size_t i)
{
	if (info->width - info->c_width <= (int)i && \
	(int)ft_unbrlen(info, n) < info->c_width)
		ft_putchar_fd('0', 1);
	else
		ft_putchar_fd(' ', 1);
}
