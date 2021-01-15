/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:24:57 by cjung             #+#    #+#             */
/*   Updated: 2021/01/15 15:24:58 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_nbr(int n, t_info *info)
{
	char	*nbr;
	size_t	len;
	int		flags[4];

	nbr = ft_itoa(n);
	flags[1] = 0;
	flags[2] = 1;
	flags[3] = 0;
	if (info->colon == 1 && info->c_width == 0 && n == 0)
		return (print_nbr_null(nbr, info, flags));
	if (n < 0)
		flags[0] = 1;
	if ((unsigned)info->width > ft_nbrlen(info, n) ||
	(unsigned)info->c_width + 1 > ft_nbrlen(info, n))
		if (info->minus)
			print_nbr_minus(n, &nbr, info, flags);
		else
			print_nbr_else(n, &nbr, info, flags);
	else
		ft_putstr_fd(nbr, 1);
	len = print_nbr_clear(nbr, info, flags);
	return (len > (size_t)info->width ? len : (size_t)info->width);
}

size_t	print_nbr_null(char *nbr, t_info *info, int *flags)
{
	while (flags[3]++ < info->width)
		ft_putchar_fd(' ', 1);
	free(nbr);
	return (flags[3] - 1);
}

void	print_nbr_minus(int n, char **nbr, t_info *info, int *flags)
{
	if (n < 0)
		info->c_width++;
	if ((info->c_minus && info->c_wild) || \
	((int)ft_nbrlen(info, n) < info->c_width && info->c_wild) || info->minus)
		print_nbr_minus2(n, nbr, info, flags);
	if (n == 0 && !info->c_wild && info->c_width > 0 && info->c_minus)
		ft_putchar_fd(' ', 1);
	else
		ft_putstr_fd(*nbr, 1);
	if (info->c_minus && !info->c_wild)
		info->width = info->c_width;
	while ((int)ft_nbrlen(info, n) + flags[3] < info->width)
	{
		ft_putchar_fd(' ', 1);
		flags[3]++;
	}
}

void	print_nbr_minus2(int n, char **nbr, t_info *info, int *flags)
{
	while ((int)ft_nbrlen(info, n) + flags[3] < info->c_width && \
	info->c_minus == 0)
	{
		print_nbr_mflag2(n, nbr, flags);
		flags[3]++;
	}
	while ((int)ft_nbrlen(info, n) + flags[3] < info->width && !info->minus)
	{
		if (info->zero)
			print_nbr_mflag2(n, nbr, flags);
		else
			ft_putchar_fd(' ', 1);
		flags[3]++;
	}
}
