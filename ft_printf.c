/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 11:31:29 by cjung             #+#    #+#             */
/*   Updated: 2021/01/15 12:54:29 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	parse_format(va_list ap, char *format)
{
	size_t	ret;
	t_info	*info;

	ret = 0;
	if (!(info = malloc(sizeof(t_info))))
		return (0);
	while (*format)
	{
		info_init(info);
		if (*format == '%')
			parse_percent(ap, info, &format, &ret);
		else
		{
			ft_putchar_fd(*format, 1);
			ret++;
		}
		++format;
	}
	free(info);
	return (ret);
}

void	parse_percent(va_list ap, t_info *info, char **format, size_t *ret)
{
	size_t	dum;

	dum = check_info(*format, info, ap);
	*format += dum;
	if (info->type == 0)
	{
		*format -= dum;
		*ret += dum;
		while (--dum)
			ft_putchar_fd(*((*format)++), 1);
	}
	else
		*ret += printf_format(ap, info, *format);
}

size_t	printf_format(va_list ap, t_info *info, char *format)
{
	if (*format == 'c')
		return (print_char(va_arg(ap, int), info));
	else if (*format == 's')
		return (print_str(va_arg(ap, char *), info));
	else if (*format == 'p')
		return (print_add((__uint64_t)va_arg(ap, void *), info));
	else if (*format == 'd' || *format == 'i')
		return (print_nbr(va_arg(ap, int), info));
	else if (*format == 'u')
		return (print_unbr(va_arg(ap, unsigned int), info));
	else if (*format == 'x')
		return (print_hex((unsigned)va_arg(ap, unsigned), info, LOWER));
	else if (*format == 'X')
		return (print_hex((unsigned)va_arg(ap, unsigned), info, UPPER));
	else if (*format == '%')
		return (print_char(*format, info));
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	ret;

	ret = 0;
	va_start(ap, format);
	ret = parse_format(ap, (char *)format);
	va_end(ap);
	return (ret);
}
