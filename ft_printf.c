/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:38:16 by amarchal          #+#    #+#             */
/*   Updated: 2021/11/18 17:38:57 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			i;
	int			count;
	va_list		args;

	va_start (args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				count += write(1, "%", 1);
			else
				ft_print_format(args, format[i + 1], &count);
			i++;
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end (args);
	return (count);
}

// int main(void)
// {
//     printf("%d\n", ft_printf("%p\n", (int)-2147483648));
//     printf("%d\n", printf("%p\n", (int)-2147483648));
// }
