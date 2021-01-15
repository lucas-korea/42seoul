/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:24:57 by cjung             #+#    #+#             */
/*   Updated: 2021/01/15 13:12:07 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_add(__uint64_t add, t_info *info)
{
	size_t	i;

	i = 0;
	if (add == (__uint64_t)NULL)
	{
		return (print_add_null(info, i));
	}
	if ((unsigned)info->width > ft_unbrlen(info, add) || \
	(unsigned)info->c_width > ft_unbrlen(info, add))
	{
		if (info->minus)
			print_add_minus(add, info, i);
		else
			print_add_else(add, info, i);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_puthex_fd(add, LOWER, 1);
	}
	if (info->c_width + 2 > info->width)
		info->width = info->c_width + 2;
	return (ft_unbrlen(info, add) > (size_t)info->width ?
	ft_unbrlen(info, add) : (size_t)info->width);
}

void	print_add_minus(__uint64_t add, t_info *info, size_t i)
{
	ft_putstr_fd("0x", 1);
	ft_puthex_fd(add, LOWER, 1);
	while (ft_unbrlen(info, add) + i++ < \
	(unsigned)info->width)
		ft_putchar_fd(' ', 1);
}

void	print_add_else(__uint64_t add, t_info *info, size_t i)
{
	while (info->width > info->c_width + 2 + (int)i && \
	info->width > (int)(ft_unbrlen(info, add) + i))
	{
		if (info->zero && info->colon == 0)
			break ;
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putstr_fd("0x", 1);
	while (ft_unbrlen(info, add) + i < (unsigned)info->width || \
	ft_unbrlen(info, add) + i - 2 < (unsigned)info->c_width)
	{
		if (info->zero || (int)ft_unbrlen(info, add) < info->c_width + 2)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		i++;
	}
	ft_puthex_fd(add, LOWER, 1);
}
