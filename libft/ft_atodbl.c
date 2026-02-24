/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:46:47 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/31 21:07:41 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atodbl(char *nptr)
{
	long	integer_part;
	double	fractional_part;
	int		sign;
	double	pow;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	while (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign = sign * -1;
	while (*nptr != '.' && ft_isdigit(*nptr))
		integer_part = (integer_part * 10) + (*nptr++ - 48);
	if (*nptr == '.')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		pow /= 10;
		fractional_part = fractional_part + (*nptr++ -48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*nbr;

	nbr = "     -532";
	printf("%d\n", ft_atoi(nbr));
	printf("%d\n", atoi(nbr));
	return (0);
}
*/