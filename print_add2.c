/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_add2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:24:57 by cjung             #+#    #+#             */
/*   Updated: 2021/01/15 13:10:18 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_add_null(t_info *info, size_t i)
{
	if (info->minus)
		print_add_null1(info, &i);
	else
		print_add_null2(info, &i);
	return (i);
}

void	print_add_null1(t_info *info, size_t *i)
{
	if (info->colon && info->c_width == 0)
	{
		*i = *i + 2;
		ft_putstr_fd("0x", 1);
		while (*i < (unsigned)info->width)
		{
			ft_putchar_fd(' ', 1);
			(*i)++;
		}
	}
	else
	{
		*i = *i + 3;
		ft_putstr_fd("0x0", 1);
		while (*i < (unsigned)info->width)
		{
			ft_putchar_fd(' ', 1);
			(*i)++;
		}
	}
}

void	print_add_null2(t_info *info, size_t *i)
{
	if (info->colon && info->c_width == 0)
	{
		*i = *i + 2;
		while (*i < (unsigned)info->width)
		{
			ft_putchar_fd(' ', 1);
			(*i)++;
		}
		ft_putstr_fd("0x", 1);
	}
	else
	{
		*i = *i + 3;
		while (*i < (unsigned)info->width)
		{
			ft_putchar_fd(' ', 1);
			(*i)++;
		}
		ft_putstr_fd("0x0", 1);
		while (*i < (unsigned)info->c_width + 2)
		{
			ft_putchar_fd('0', 1);
			(*i)++;
		}
	}
}
