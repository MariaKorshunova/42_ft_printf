/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:18:17 by jmabel            #+#    #+#             */
/*   Updated: 2021/12/12 14:31:21 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_list
{
	int		fminus;
	int		fnull;
	int		fplus;
	int		fblank;
	int		fsharp;
	int		fwidth;
	int		fprecision;
	int		value;
	char	*str;
}				t_list;

int		ft_printf(const char *fmt, ...);

int		ft_parser_number(char **p, va_list *ap);
int		ft_print_single_character(char **p, va_list *ap, t_list *pl);
int		ft_print_character_with_width(char c, t_list *pl);
int		ft_print_string_of_characters(char **p, va_list *ap, t_list *pl);
int		ft_print_pointer_argument(char **p, va_list *ap, t_list *pl);
int		ft_print_decimal_integer(char **p, va_list *ap, t_list *pl);
int		ft_print_unsigned_decimal(char **p, va_list *ap, t_list *pl);
int		ft_print_hexadecimal_lowercase(char **p, va_list *ap, t_list *pl);
int		ft_print_hexadecimal_uppercase(char **p, va_list *ap, t_list *pl);
int		ft_percent_sign(char **p);
int		ft_print_percent_sign(char **p, t_list *pl);
char	*ft_modified_width_str(t_list *pl);
char	*ft_decimal_integer(char **p, va_list *ap, t_list *pl);
char	*ft_unsigned_decimal(char **p, va_list *ap, t_list *pl);
char	*ft_hexadecimal_lowercase(char **p, va_list *ap, t_list *pl);
char	*ft_hexadecimal_uppercase(char **p, va_list *ap, t_list *pl);
void	ft_parser(char **p, va_list *ap, int *printed_char);
void	ft_begin_printed_list(t_list *pl);
void	ft_parser_flags(char **p, t_list *pl);
void	ft_parser_specifier(char **p, va_list *ap, t_list *pl, int *print_char);
void	ft_string_of_characters(char **p, va_list *ap, t_list *pl);
void	ft_str_dec_to_hexadec(unsigned long number, char **str, char *key);
void	ft_record_0x(char **str, int i, char flag);
void	ft_pointer_argument(char **p, va_list *ap, t_list *pl);
void	ft_plus_blank_flags(t_list *pl);
void	ft_precision(t_list *pl, long long value);
void	ft_print_negative(t_list *pl);
void	ft_exception_zero_precision(t_list *pl);
void	ft_fill_precision(t_list *pl, char *str);
void	ft_sharp_flags(t_list *pl, char x_case);
void	ft_replace_sign_width(t_list *pl, char *str, int len);

size_t	ft_strlen(const char *s);
int		ft_longlen(long long n);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoinsymb(char **s1, char c);
char	*ft_fillstrbysymb(char *str, char c, int len);
char	*ft_strdup(const char *s1);
char	*ft_itoa(long long nb);
char	*ft_itoa_record(long long n, int len, char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
