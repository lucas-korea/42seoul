/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:25:29 by cjung             #+#    #+#             */
/*   Updated: 2020/12/26 09:56:56 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		*dst2;

	i = -1;
	str = src;
	dst2 = dst;
	while (++i < n)
	{
		dst2[i] = str[i];
		if (str[i] == (unsigned char)c)
			return (&dst2[i + 1]);
	}
	return (NULL);
}
