/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:37:42 by hael-mou          #+#    #+#             */
/*   Updated: 2023/10/24 19:12:30 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int character)
{
	if (character == '\t' || character == ' ')
		return (true);
	if (character == '\v' || character == '\f')
		return (true);
	if (character == '\n' || character == '\r')
		return (true);
	return (false);
}

static int	ft_isdigit(int character)
{
	if (character >= '0' && character <= '9')
		return (true);
	return (false);
}

int	ft_atoi(const char *string)
{
	int		sign;
	int		nbr;

	nbr = 0;
	sign = 1;
	while (ft_isspace(*string))
		string++;
	if (*string == '-')
	{
		sign = -1;
		string++;
	}
	else if (*string == '+')
		string++;
	while (ft_isdigit(*string))
		nbr = nbr * 10 + (*string++) - '0';
	return (nbr * sign);
}
