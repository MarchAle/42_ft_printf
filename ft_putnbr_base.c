/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 20:00:15 by amarchal          #+#    #+#             */
/*   Updated: 2021/11/19 14:26:54 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static void	ft_put_char_base(int index, char *base)
{
	int	c;

	c = base[index];
	write(1, &c, 1);
}

static void	ft_print_nbr(long long nbr, int base_size, char *base)
{
	long long	lnbr;
	long		index;

	lnbr = nbr;
	index = 0;
	if (lnbr < 0 && base_size != 0)
	{
		lnbr *= -1;
		write (1, "-", 1);
	}
	if (lnbr >= base_size && base_size != 0)
	{
		index = lnbr % base_size;
		ft_print_nbr((lnbr / base_size), base_size, base);
		ft_put_char_base(index, base);
	}
	else
		ft_put_char_base(lnbr, base);
}

int	ft_putnbr_base(long long nbr, char *base)
{
	int	size;
	int	base_size;

	size = 0;
	base_size = ft_strlen(base);
	ft_print_nbr(nbr, base_size, base);
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		size++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		size++;
		nbr /= base_size;
	}
	return (size);
}

int	ft_putnbr_base_u(unsigned long long nbr, char *base)
{
	int					size;
	unsigned long long	base_size;

	size = 1;
	base_size = ft_strlen(base);
	if (nbr >= base_size)
		size += ft_putnbr_base_u((nbr / base_size), base);
	ft_putchar(base[nbr % base_size]);
	return (size);
}
