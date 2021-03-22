/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:00:08 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/22 01:51:36 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <string.h>

typedef struct	s_flags
{
	char					padding;
	int						precision;
	int						width;
	int						dash;
	int						zero;
	int						read_number;
	int						read_star;
	int						is_negative;
}				t_flags;

typedef struct	s_counter
{
	int						i;
	int						j;
	int						len;
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

int			read_number(t_flags *flag, t_counter *count, const char *input);
void		is_it_star(va_list args, t_flags *flag,
							t_counter *count, const char *input);

void		print_flag_c(t_flags *flag, t_counter *count, int ch);
void		print_flag_s(va_list args, t_flags *flag, t_counter *count);

void		print_flag_d_i(va_list args, t_flags *flag, t_counter *count);
void		print_flag_u(va_list args, t_flags *flag, t_counter *count);

void		print_flag_x_X(va_list args, t_flags *flag,
								t_counter *count, int ch);
void		print_flag_p(va_list args, t_flags *flag, t_counter *count);

void		ft_putchar(t_counter *count, char c);
void		print_padding(t_flags *flag, t_counter *count, int len);
int			ft_putnbr(t_counter *count, int n);
int			ft_putnbr_unsg(t_counter *count, unsigned int n);
void		ft_putstr(t_counter *count, char *str, int len);

void		init_flag(t_flags *flag);
int			ft_toupper(int c);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *str);
int			int_len(int num);
int			unsgn_int_len(unsigned int num);
void		print_zero(t_counter *count, int len);

char		*ft_itoa_hex(unsigned long int number);


#endif