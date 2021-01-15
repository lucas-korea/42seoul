/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:24:57 by cjung             #+#    #+#             */
/*   Updated: 2021/01/15 13:12:07 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_nbr_else(int n, char **nbr, t_info *info, int *flags)
{
	if (info->c_minus)
		return (print_nbr_minus(n, nbr, info, flags));
	if (info->c_minus == 0 && n < 0 && (int)ft_nbrlen(info, n) <= info->c_width)
	{
		info->c_width++;
		if (info->width > info->c_width)
			info->c_width--;
	}
	while ((int)ft_nbrlen(info, n) + flags[3] < info->width || \
	(int)ft_nbrlen(info, n) + flags[3] < info->c_width)
	{
		if (info->zero)
			print_nbr_mflag(n, nbr, info, flags);
		else
			print_nbr_else2(n, nbr, info, flags);
		flags[3]++;
	}
	ft_putstr_fd(*nbr, 1);
}

void	print_nbr_mflag(int n, char **nbr, t_info *info, int *flags)
{
	if (info->colon && info->width > info->c_width)
	{
		if (n >= 0 ? flags[3] >= info->width - info->c_width : \
		flags[3] + 1 >= info->width - info->c_width)
			print_nbr_mflag2(n, nbr, flags);
		else
			ft_putchar_fd(' ', 1);
	}
	else
		print_nbr_mflag2(n, nbr, flags);
}

void	print_nbr_mflag2(int n, char **nbr, int *flags)
{
	if (n < 0 && flags[0])
	{
		ft_putchar_fd('-', 1);
		flags[0] = 0;
		flags[1] = 1;
		(*nbr)++;
	}
	ft_putchar_fd('0', 1);
}

void	print_nbr_else2(int n, char **nbr, t_info *info, int *flags)
{
	if (n > 0 ? flags[3] >= info->width - info->c_width && \
	!info->c_minus : flags[3] + 1 >= info->width - info->c_width && \
	(int)ft_strlen(*nbr) <= info->c_width && !info->c_minus)
		print_nbr_mflag(n, nbr, info, flags);
	else
		ft_putchar_fd(' ', 1);
}

size_t	print_nbr_clear(char *nbr, t_info *info, int *flags)
{
	size_t	len;

	if (flags[1])
		nbr--;
	len = ft_strlen(nbr);
	if (nbr)
		free(nbr);
	if (info->c_width > info->width && !info->c_minus)
		info->width = info->c_width;
	return (len);
}
