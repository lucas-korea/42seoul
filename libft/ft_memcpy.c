/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:00:54 by cjung             #+#    #+#             */
/*   Updated: 2020/12/26 17:24:29 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;

	i = -1;
	if (!dst && !src)
		return (NULL);
	while (++i < n)
		((char *)dst)[i] = ((char *)src)[i];
	return (dst);
}
