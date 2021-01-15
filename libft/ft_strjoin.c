/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 08:38:57 by cjung             #+#    #+#             */
/*   Updated: 2020/12/26 07:12:22 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*result;
	size_t	i;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	if (!(result = malloc(sizeof(char) * (total_len + 1))))
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s1))
		result[i] = s1[i];
	i--;
	while (++i < total_len)
		result[i] = s2[i - ft_strlen(s1)];
	result[i] = 0;
	return (result);
}
