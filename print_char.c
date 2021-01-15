/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:24:57 by cjung             #+#    #+#             */
/*   Updated: 2021/01/12 06:30:31 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_char(char c, t_info *info)
{
	size_t	i;

	i = 0;
	if (info->width > 1)
	{
		if (info->minus)
		{
			ft_putchar_fd(c, 1);
			while (1 + i++ < (unsigned)info->width)
				ft_putchar_fd(' ', 1);
		}
		else
			print_char_else(c, info, i);
	}
	else
		ft_putchar_fd(c, 1);
	return (1 > info->width ? 1 : (size_t)info->width);
}

void	print_char_else(char c, t_info *info, size_t i)
{
	while (1 + i++ < (unsigned)info->width)
	{
		if (info->zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
	}
	ft_putchar_fd(c, 1);
}
