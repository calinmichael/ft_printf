/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:33:47 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/12 12:18:44 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *a, ...);
int	ft_printf_str(const char *str);
int	ft_printf_char(int c);
int	ft_printf_ptr(void *ptr);
int	ft_printf_nbr(int n);
int	ft_printf_unsigned(unsigned int n);
int	ft_printf_hex(unsigned int n, char format);

#endif
