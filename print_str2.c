/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:24:57 by cjung             #+#    #+#             */
/*   Updated: 2021/01/15 13:11:16 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_str_null(t_info *info)
{
	if (info->c_width >= 1 || info->colon == 0)
		return (print_str("(null)", info));
	else if (info->c_width > 0 && info->c_minus)
	{
		info->colon = 0;
		return (print_str("(null)", info));
	}
	else
		return (print_str("", info));
}
