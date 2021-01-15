/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 10:22:11 by cjung             #+#    #+#             */
/*   Updated: 2020/12/23 10:22:11 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lit_len;

	if (*little == 0)
		return ((char *)big);
	lit_len = ft_strlen(little);
	while (*big && len-- >= lit_len)
	{
		if (*big == *little && ft_strncmp(big, little, lit_len) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
