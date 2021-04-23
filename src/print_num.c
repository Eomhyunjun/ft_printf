/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:48:01 by heom              #+#    #+#             */
/*   Updated: 2021/03/25 10:41:31 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_len(unsigned long long num, t_info *ft_box, int num_len)
{
	int count;
	int z_len;
	int b_len;
	int long_len;

	count = 0;
	z_len = 0;
	b_len = 0;
	long_len = num_len >= ft_box->prec ? num_len : ft_box->prec;
	if (ft_box->type == 'p')
		ft_box->width -= 2;
	if (ft_box->prec == 0 && num == 0)
		long_len--;
	if (long_len == ft_box->prec)
		z_len += ft_box->prec - num_len;
	if (((ft_box->width > long_len && ft_box->prec == num_len) &&\
				ft_box->zero == 1) && ft_box->left_align == 0)
		z_len += ft_box->width - long_len - ft_box->sign;
	else
		b_len += ft_box->width - long_len - ft_box->sign;
	if (ft_box->type == 'd' || ft_box->type == 'i' || ft_box->type == 'u')
		count += print_d(num, ft_box, b_len, z_len);
	if (ft_box->type == 'x' || ft_box->type == 'X' || ft_box->type == 'p')
		count += print_h(num, ft_box, b_len, z_len);
	return (count);
}

int		print_h(unsigned long long num, t_info *ft_box, int b_len, int z_len)
{
	int count;

	count = 0;
	if (ft_box->left_align == 0)
		count += print_blank(b_len);
	if (ft_box->type == 'p')
		count += write(1, "0x", 2);
	count += print_zero(z_len);
	if (!(ft_box->prec == 0 && num == 0))
		count += ft_puthex(num, ft_box);
	if (ft_box->left_align == 1)
		count += print_blank(b_len);
	return (count);
}

int		print_d(unsigned long long num, t_info *ft_box, int b_len, int z_len)
{
	int count;

	count = 0;
	if (ft_box->left_align == 0)
		count += print_blank(b_len);
	if ((ft_box->type == 'd' || ft_box->type == 'i') && ft_box->sign == 1)
		count += write(1, "-", 1);
	count += print_zero(z_len);
	if (!(ft_box->prec == 0 && num == 0))
		count += ft_putnbr(num);
	if (ft_box->left_align == 1)
		count += print_blank(b_len);
	return (count);
}

int		cntnumlen(unsigned long long num, t_info *ft_box)
{
	int		i;
	char	type;

	type = ft_box->type;
	i = 1;
	if (type == 'x' || type == 'X' || type == 'p')
	{
		while (num > 15)
		{
			i++;
			num /= 16;
		}
	}
	else
	{
		while (num > 9)
		{
			i++;
			num /= 10;
		}
	}
	return (i);
}

int		process_num(unsigned long long num, t_info *ft_box)
{
	int count;
	int num_len;

	count = 0;
	num_len = 0;
	if ((ft_box->type == 'd' || ft_box->type == 'i') && (int)num < 0)
	{
		ft_box->sign = 1;
		num = -num;
	}
	num_len = cntnumlen(num, ft_box);
	if (ft_box->prec != -1 && ft_box->width > 0)
		ft_box->zero = 0;
	if (ft_box->prec == -1)
		ft_box->prec = num_len;
	count += parse_len(num, ft_box, num_len);
	return (count);
}
