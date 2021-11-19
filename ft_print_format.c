/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:40:08 by amarchal          #+#    #+#             */
/*   Updated: 2021/11/19 11:29:38 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_print_format(va_list args, char c, int *pt_count)
{
	if (c == 'c')
		*pt_count += ft_putchar(va_arg(args, int));
	if (c == 's')
		*pt_count += ft_putstr(va_arg(args, char *));
	if (c == 'd' || c == 'i')
		*pt_count += ft_putnbr_base(va_arg(args, int), "0123456789");
	if (c == 'u')
		*pt_count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	if (c == 'x')
		*pt_count += ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789abcdef");
	if (c == 'X')
		*pt_count += ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	if (c == 'p')
	{
		*pt_count += ft_putstr("0x");
		*pt_count += ft_putnbr_base_u(va_arg(args, unsigned long long),
				"0123456789abcdef");
	}
}
