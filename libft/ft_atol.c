/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:24:07 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/16 18:58:38 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atol(const char *nptr)
{
	int				i;
	long long int	sign;
	long long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((('\t' <= nptr[i]) && (nptr[i] <= '\r')) || nptr[i] == ' ')
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		++i;
	}
	if (ft_isdigit(nptr[i]))
	{
		while (ft_isdigit(nptr[i]))
		{
			result = result * 10 + (nptr[i] - '0');
			++i;
		}
	}
	return (result * sign);
}
