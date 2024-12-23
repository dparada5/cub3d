/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:52:39 by dparada           #+#    #+#             */
/*   Updated: 2024/12/17 13:15:37 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_char(char c)
{
	write(2, &c, 1);
}

static void	ft_put_str(char	*str)
{
	int	i;

	i = -1;
	if (!str)
	{
		ft_put_str("(null)\n");
		return ;
	}
	while (str[++i])
		ft_put_char(str[i]);
}

static void	ft_putbase(long long int number, int nb)
{
	char	*base;

	base = "0123456789abcdef";
	if (number < 0)
	{
		ft_put_char('-');
		number *= -1;
	}
	if (number >= nb)
		ft_putbase(number / nb, nb);
	ft_put_char(base[number % nb]);
}

void	ft_printf_fd(char const *str, ...)
{
	int		i;
	va_list	box;

	i = -1;
	va_start(box, str);
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (str[i] == 's')
				ft_put_str(va_arg(box, char *));
			else if (str[i] == 'd')
				ft_putbase(va_arg(box, int), 10);
			else if (str[i] == 'x')
				ft_putbase((long long int)va_arg(box, unsigned int), 16);
			else if (str[i] == 'c')
				ft_put_char(va_arg(box, int));
		}
		else
			ft_put_char(str[i]);
	}
	va_end(box);
}
