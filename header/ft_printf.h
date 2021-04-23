/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:13:52 by heom              #+#    #+#             */
/*   Updated: 2021/03/25 21:32:09 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <libft.h>

typedef struct		s_info
{
	int				left_align;
	int				zero;
	int				width;
	int				prec;
	int				sign;
	char			type;
}					t_info;

/*
** ------------------- additional -------------------------
*/

unsigned long long	simple_atoi(char **temp);
int					ft_putnbr(unsigned long long n);
int					ft_puthex(unsigned long long n, t_info *ft_box);

/*
** -------------------- main fuction -------------------
*/

int					ft_printf(const char *format, ...);
int					process_ft(const char *format, va_list ap);

/*
** -------------------- parsing function ----------------
*/

void				parsing_ft(char **temp, t_info *ft_box, va_list ap);
void				parsing_flags(char **temp, t_info *ft_box);
void				parsing_width(char **temp, t_info *ft_box, va_list ap);
void				parsing_pre(char **temp, t_info *ft_box, va_list ap);
void				parsing_type(char **temp, t_info *ft_box);

/*
** --------------------- printf function -----------------
*/

int					print_process(va_list ap, t_info *ft_box);
int					print_c(va_list ap, t_info *ft_box);

int					process_s(va_list ap, t_info *ft_box);
int					print_sr(t_info *ft_box, char *s, int length);
int					print_sl(t_info *ft_box, char *s, int length);
int					print_len(char *s, int length);

int					process_num(unsigned long long num, t_info *ft_box);
int					cntnumlen(unsigned long long num, t_info *ft_box);
int					parse_len(unsigned long long num,\
								t_info *ft_box, int num_len);
int					print_d(unsigned long long num,\
								t_info *ft_box, int b_len, int z_len);
int					print_h(unsigned long long num,\
								t_info *ft_box, int b_len, int z_len);
int					num_print(unsigned long long num);

int					print_percent(t_info *ft_box);

int					print_zero(int num);
int					print_blank(int num);
#endif
