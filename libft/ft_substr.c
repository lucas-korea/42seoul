/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 08:38:57 by cjung             #+#    #+#             */
/*   Updated: 2020/12/26 16:44:30 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	return_len;
	size_t	j;

	j = -1;
	return_len = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	return_len = (len > (ft_strlen(s) - start) ? ft_strlen(s) - start : len);
	if (!(result = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++j < return_len)
		result[j] = s[start + j];
	result[j] = 0;
	return (result);
}
