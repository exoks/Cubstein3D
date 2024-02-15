/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:17:01 by hael-mou          #+#    #+#             */
/*   Updated: 2023/10/23 16:42:23 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
	{
		ft_perror(ERROR_ALLOC);
		return (NULL);
	}
	return (ft_bzero(ptr, count * size));
}
