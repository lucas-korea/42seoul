/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:32:58 by cjung             #+#    #+#             */
/*   Updated: 2020/12/26 17:24:31 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_p;
	const unsigned char	*src_p;

	if (!dst && !src)
		return (NULL);
	dst_p = (unsigned char *)dst;
	src_p = (const unsigned char *)src;
	if (src_p < dst_p)
		while (len--)
			dst_p[len] = src_p[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
