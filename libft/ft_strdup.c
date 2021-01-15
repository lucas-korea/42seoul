/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:04:25 by cjung             #+#    #+#             */
/*   Updated: 2020/12/26 06:43:35 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*result;
	char	*dum;

	len = ft_strlen(s1);
	if (!(result = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dum = result;
	while (*s1)
		*result++ = *s1++;
	*result = 0;
	return (dum);
}
