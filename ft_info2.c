/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 11:31:29 by cjung             #+#    #+#             */
/*   Updated: 2021/01/15 13:12:07 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	info_minus(t_info *info, int *flag)
{
	info->minus = 1;
	info->zero = 0;
	*flag = 1;
}

void	info_wild(int wild_num, t_info *info)
{
	info->wild = 1;
	if (wild_num < 0)
	{
		info->minus = 1;
		info->width = -wild_num;
	}
	else
		info->width = wild_num;
}

void	info_colon(t_info *info, char *format, va_list ap)
{
	char	p_size[10];
	char	*p_size_dum;
	size_t	cnt;

	set_psize(p_size);
	cnt = 0;
	info->colon = 1;
	if (*format == '-')
		p_size[cnt++] = '-';
	if (*format == '*')
		return (info_colon_wild(info, ap));
	while (ft_isdigit(format[cnt]))
	{
		p_size[cnt] = format[cnt];
		cnt++;
	}
	p_size_dum = malloc(sizeof(char) * (cnt + 1));
	ft_strlcpy(p_size_dum, p_size, cnt + 1);
	info->c_width = ft_atoi(p_size_dum);
	if (info->c_width < 0)
	{
		info->c_width = -info->c_width;
		info->c_minus = 1;
	}
	free(p_size_dum);
}

void	info_colon_wild(t_info *info, va_list ap)
{
	info->c_wild = 1;
	info->c_width = va_arg(ap, int);
	if (info->c_width < 0)
	{
		info->c_width = -info->c_width;
		info->c_minus = 1;
	}
}

void	set_psize(char *p_size)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		p_size[i++] = '0';
	}
	p_size[i] = 0;
}
