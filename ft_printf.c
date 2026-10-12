/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:11:52 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/12 16:36:23 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	tha_switch(va_list lst, char conv, int count)
{
	char	ch;
	char	*str;
	void	*ptr;

	if (conv == 'c')
	{
		ch = va_arg(lst, int);
		count += ft_printf_char(ch);
	}
	else if (conv == 's')
	{
		str = va_arg(lst, char *);
		count += ft_printf_str(str);
	}
	else if (conv == 'p')
	{
		ptr = va_arg(lst, void *);
		count += ft_printf_ptr(ptr);
	}
	else if (conv == '%')
	{
		write (1, "%", 1);
		count++;
	}
	return (count);
}

int	p2_switch(va_list lst, char conv, int count)
{
	int				decimal;
	/**unsigned int	num;**/

	if (conv == 'd' || conv == 'i')
	{
		decimal = va_arg(lst, int);
		count += ft_printf_nbr(decimal);
	}
	else if (conv == 'u')
	{
		/**num = va_arg(lst, unsigned int);
		count += ft_printf_unsigned(num);**/
	}
	return (count);
}

int	tha_while(va_list lst, int count, const char *a, int i)
{
	char	conv;

	while (a[i])
	{
		if (a[i] == '%')
		{
			if (!a[i + 1])
				return (0);
			i++;
			conv = a[i];
			if (conv == '%')
				count = tha_switch(lst, conv, count);
			else if (conv == 'c' || conv == 's' || conv == 'p')
				count = tha_switch(lst, conv, count);
			else
				count = p2_switch(lst, conv, count);
		}
		else
		{
			write (1, &a[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *a, ...)
{
	size_t	i;
	int		count;
	va_list	lst;

	if (!a)
		return (0);
	va_start(lst, a);
	count = 0;
	i = 0;
	count = tha_while(lst, count, a, i);
	va_end(lst);
	return (count);
}