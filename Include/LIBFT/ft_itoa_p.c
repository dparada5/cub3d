/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:21:05 by dparada           #+#    #+#             */
/*   Updated: 2024/12/10 17:09:42 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digit_p(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}

char	*ft_convert_p(long n, char *ptr, size_t i)
{
	ptr[0] = '0';
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		ptr[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (ptr);
}

char	*ft_itoap(int n)
{
	char	*ptr;
	size_t	i;
	long	nl;

	nl = (long)n;
	i = ft_digit_p(nl);
	ptr = malloc ((i + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ptr[i] = '\0';
	ptr = ft_convert_p(nl, ptr, i);
	return (ptr);
}
