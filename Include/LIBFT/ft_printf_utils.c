/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:14:37 by dparada           #+#    #+#             */
/*   Updated: 2024/12/10 17:10:09 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strdiv(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb < 16)
		i = 1;
	else
	{
		while (nb != 0)
		{
			nb /= 16;
			i++;
		}
	}
	return (i);
}
