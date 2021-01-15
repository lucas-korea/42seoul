/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:07:34 by cjung             #+#    #+#             */
/*   Updated: 2021/01/12 07:18:53 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*set_hexlist(int uorl)
{
	char	*hex_list;

	if (uorl == UPPER)
		hex_list = ft_strdup("0123456789ABCDEF\0");
	else if (uorl == LOWER)
		hex_list = ft_strdup("0123456789abcdef\0");
	else
	{
		printf("wrong uorl");
		exit(0);
	}
	return (hex_list);
}

void		ft_puthex_fd(__uint64_t n, int uorl, int fd)
{
	char	*hex_list;

	hex_list = set_hexlist(uorl);
	if (n >= 16)
	{
		ft_puthex_fd(n / 16, uorl, fd);
		ft_putchar_fd(hex_list[n % 16], fd);
	}
	else
	{
		ft_putchar_fd(hex_list[n], fd);
	}
	free(hex_list);
}
