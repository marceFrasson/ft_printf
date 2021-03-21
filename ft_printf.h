/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:00:08 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/21 11:08:12 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <string.h>
#include <stdio.h>

# define FLAGS		"-0.*"

typedef struct	s_flags
{
	int						justify;
	char					padding;
	size_t					precision;
	size_t					width;
	int						dash;
	int						zero;
	int						dot;
	int						star;
	int						read_number;
	int						read_star;
	int						zero_size;
	size_t					size;
	char					ch;
	int						difference;
	char					*str;
	int						read_number_precision;
	int						read;
	int						is_digit;
	int						is_alpha;
	int						is_hexa;
	int						is_pntr;
	int						is_prcnt;
	int						is_upper;
}				t_flags;

typedef struct	s_counter
{
	int						i;
	int						len;
	size_t					size;
}				t_counter;

typedef	struct	s_itoa_hex
{
	char	*hex;
	int		to_hex;
	int		length;
	int		case_c;
	char	temp;
}				t_itoa_hex;

int			ft_printf(const char *input, ...);
void		which_format(va_list args, t_counter *count, const char *input);
void		which_flag(va_list args, t_flags *flag,
							t_counter *count, const char *input);
void		get_measures(va_list args, t_flags *flag, const char *input);
int			read_number(t_flags *flag, t_counter *count, const char *input);
int			read_number_precision(t_flags *flag, t_counter *count, const char *input);
int			read_number_width(t_flags *flag, t_counter *count, const char *input);
void		print_flag_c(va_list args, t_flags *flag, t_counter *count);
void		print_flag_s(va_list args, t_flags *flag, t_counter *count);
void		print_flag_d_i_u(va_list args, t_flags *flag, t_counter *count);
int			print_flag_p(va_list args, t_flags *flag, t_counter *count);
void		print_flag_x_X(va_list args, t_flags *flag, t_counter *count);
void		print_flag_prcnt(t_flags *flag, t_counter *count);
int			int_len(int num);
int			unsgn_int_len(unsigned int num);
void		ft_putchar(t_counter *count, char c);
void		put_space(t_flags *flag, t_counter *count);
char		*ft_substr(char const *str, unsigned int index, size_t size);
void		ft_putstr(t_counter *count, char *str);
int			ft_putnbr(t_counter *count, int n);
int			ft_putnbr_unsg(t_counter *count, int n);
int			ft_isdigit(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_strupcase(char *str);
void		ft_putstr_size(t_flags *flag, t_counter *count, char *str);
void		ft_putstr_up(t_counter *count, char *str);
void		ft_putstr_low(t_counter *count, char *str);
void		ft_putcstr(t_counter *count, char *str, int size);
char		*ft_strchr(const char *str, int c);
size_t		ft_strlen(const char *str);
char		*ft_itoa_hex(t_counter *count, unsigned long int number);
void		print_padding(t_flags *flag, t_counter *count);
void		print_padding_precision(t_flags *flag, t_counter *count);
void		print_padding_width(t_flags *flag, t_counter *count);
void		print_flag_s(va_list args, t_flags *flag, t_counter *count);
void		print_putstr_size(t_flags *flag, t_counter *count, char *str);
void		init_flag(t_flags *flag);
void		set_format(va_list args, t_flags *flag,
							t_counter count, const char *input);

#endif