/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:04:00 by heom              #+#    #+#             */
/*   Updated: 2021/03/25 11:03:24 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_len(char *s, int length)
{
	int count;

	count = write(1, s, length);
	return (count);
}

int		print_sr(t_info *ft_box, char *s, int length)
{
	int count;

	count = 0;
	if (ft_box->zero == 0)
	{
		if (ft_box->width - length > 0)
		{
			count += print_blank(ft_box->width - length);
			count += print_len(s, length);
		}
		else
			count += print_len(s, length);
	}
	else
	{
		if (ft_box->width - length > 0)
		{
			count += print_zero(ft_box->width - length);
			count += print_len(s, length);
		}
		else
			count += print_len(s, length);
	}
	return (count);
}

int		print_sl(t_info *ft_box, char *s, int length)
{
	int	count;

	count = 0;
	if (ft_box->width - length > 0)
	{
		count += print_len(s, length);
		count += print_blank(ft_box->width - length);
	}
	else
		count += print_len(s, length);
	return (count);
}

int		process_s(va_list ap, t_info *ft_box)
{
	char	*s;
	int		count;
	int		length;

	count = 0;
	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	length = ft_strlen(s);
	if (length > ft_box->prec && ft_box->prec != -1)
		length = ft_box->prec;
	if (ft_box->left_align == 0)
		count += print_sr(ft_box, s, length);
	else
		count += print_sl(ft_box, s, length);
	return (count);
}
