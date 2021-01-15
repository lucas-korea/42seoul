/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 11:31:29 by cjung             #+#    #+#             */
/*   Updated: 2021/01/15 12:53:05 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	info_init(t_info *info)
{
	info->minus = 0;
	info->nbr_base = 10;
	info->nbr_size = 0;
	info->type = 0;
	info->width = 0;
	info->zero = 0;
	info->wild = 0;
	info->colon = 0;
	info->c_minus = 0;
	info->c_width = 0;
	info->c_zero = 0;
	info->c_wild = 0;
}

size_t	check_info(char *format, t_info *info, va_list ap)
{
	size_t	flen;
	int		flag;

	flag = 1;
	flen = check_info_while(format, info, ap, flag);
	info->type = format[flen];
	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->nbr_base = 16;
	return (flen);
}

size_t	check_info_while(char *format, t_info *info, va_list ap, int flag)
{
	char	*type_list;
	size_t	flen;

	type_list = "cspdiuxX%%\0";
	flen = 0;
	while (!ft_strchr(type_list, format[++flen]))
	{
		if (ft_isdigit(format[flen]) && flag)
			chekc_while_isdigit(format, info, &flag, flen);
		else if (format[flen] == '-')
			info_minus(info, &flag);
		else if (format[flen] == '*')
			info_wild(va_arg(ap, int), info);
		else if (format[flen] == '.')
		{
			info_colon(info, &format[flen + 1], ap);
			while (!ft_strchr(type_list, format[flen]))
				flen++;
			break ;
		}
	}
	return (flen);
}

void	chekc_while_isdigit(char *format, t_info *info, int *flag, size_t flen)
{
	info_width(info, &format[flen]);
	*flag = 0;
}

void	info_width(t_info *info, char *format)
{
	char	p_size[10];
	char	*p_size_dum;
	size_t	cnt;

	cnt = 0;
	set_psize(p_size);
	if (*format == '0')
		info->zero = 1;
	while (ft_isdigit(format[cnt]))
	{
		p_size[cnt] = format[cnt];
		cnt++;
	}
	p_size_dum = malloc(sizeof(char) * (cnt + 1));
	ft_strlcpy(p_size_dum, p_size, cnt + 1);
	info->width = ft_atoi(p_size_dum);
	free(p_size_dum);
}
