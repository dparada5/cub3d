/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:24:21 by dparada           #+#    #+#             */
/*   Updated: 2024/12/10 17:09:02 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digit_u(long n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}

char	*ft_convert_u(long n, char *ptr, size_t i)
{
	ptr[0] = '0';
	while (n != 0)
	{
		ptr[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (ptr);
}

char	*ft_itoa_u(unsigned int n)
{
	char	*ptr;
	size_t	i;
	long	nl;

	nl = (long)n;
	i = ft_digit_u(nl);
	ptr = malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	ptr = ft_convert_u(nl, ptr, i);
	return (ptr);
}
