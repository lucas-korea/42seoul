/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 22:49:40 by cjung             #+#    #+#             */
/*   Updated: 2020/12/26 09:17:30 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	if (n == 0)
		return (0);
	i = -1;
	ptr = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (*ptr == *ptr2 && ++i < n)
	{
		ptr++;
		ptr2++;
		if (i == n - 1)
			return (0);
	}
	return ((int)(*ptr - *ptr2));
}
