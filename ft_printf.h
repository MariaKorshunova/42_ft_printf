/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:20:37 by jmabel            #+#    #+#             */
/*   Updated: 2021/11/30 17:24:43 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *fmt, ...);

int		ft_parser_specifier(char **p, va_list *ap);
int		ft_print_dec_to_hexadec(unsigned long number, int *i, char flag);
int		ft_single_character(char **p, va_list *ap);
int		ft_string_of_characters(char **p, va_list *ap);
int		ft_pointer_argument(char **p, va_list *ap);
int		ft_decimal_integer(char **p, va_list *ap);
int		ft_unsigned_decimal(char **p, va_list *ap);
int		ft_hexadecimal_lowercase(char **p, va_list *ap);
int		ft_hexadecimal_uppercase(char **p, va_list *ap);
int		ft_percent_sign(char **p);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_unsigned(unsigned int n, int fd);
size_t	ft_strlen(const char *s);
int		ft_longlen(long long n);

#endif