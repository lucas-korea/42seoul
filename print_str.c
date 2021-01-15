/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:24:57 by cjung             #+#    #+#             */
/*   Updated: 2021/01/15 13:12:07 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_str(char *str, t_info *info)
{
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	if (str == NULL)
		return (print_str_null(info));
	if (info->minus)
		print_str_minus(str, info, &i, &j);
	else
		print_str_else(str, info, &i, &j);
	if (info->colon == 0 || (info->c_width > 0 && info->c_minus))
		return (ft_strlen(str) > (size_t)info->width ? ft_strlen(str) : \
		(size_t)info->width);
	else
	{
		if (info->c_width > (int)ft_strlen(str))
			info->c_width = (int)ft_strlen(str);
		return (info->width > info->c_width ? info->width : info->c_width);
	}
}

void	print_str_minus(char *str, t_info *info, size_t *i, int *j)
{
	if (info->c_minus && !info->wild)
	{
		while ((*i)++ < (unsigned)info->c_width)
			ft_putchar_fd(' ', 1);
		return ;
	}
	if (info->colon && info->c_width >= 0 && info->c_minus == 0)
	{
		if (info->c_width == 0)
			while ((int)(*i)++ < info->width)
				ft_putchar_fd(' ', 1);
		while (*j < info->c_width && *j < (int)ft_strlen(str))
		{
			ft_putchar_fd(str[*j], 1);
			(*j)++;
		}
		while (*j + (*i)++ < (unsigned)info->width)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		ft_putstr_fd(str, 1);
		while (ft_strlen(str) + (*i)++ < (unsigned)info->width)
			ft_putchar_fd(' ', 1);
	}
}

void	print_str_else(char *str, t_info *info, size_t *i, int *j)
{
	if (info->c_minus && !info->c_wild)
	{
		while ((*i)++ < (unsigned)info->c_width)
			ft_putchar_fd(' ', 1);
		return ;
	}
	if (info->c_width > 0 && !info->c_minus && info->c_width < info->width &&
	(int)ft_strlen(str) >= info->c_width)
	{
		while ((unsigned)info->c_width + *i < (unsigned)info->width)
		{
			ft_putchar_fd(' ', 1);
			(*i)++;
		}
	}
	else
		print_str_else3(str, info, i);
	if (info->colon && !info->c_minus)
		print_str_else2(str, info, i, j);
	else
		ft_putstr_fd(str, 1);
}

void	print_str_else2(char *str, t_info *info, size_t *i, int *j)
{
	if (info->c_width == 0)
		while ((int)(*i)++ < info->width)
			ft_putchar_fd(' ', 1);
	while (*j < info->c_width && *j < (int)ft_strlen(str))
	{
		ft_putchar_fd(str[*j], 1);
		(*j)++;
	}
}

void	print_str_else3(char *str, t_info *info, size_t *i)
{
	while (ft_strlen(str) + *i < (unsigned)info->width)
	{
		if (info->zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		(*i)++;
	}
}
