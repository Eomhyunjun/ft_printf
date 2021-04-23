/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 03:38:16 by heom              #+#    #+#             */
/*   Updated: 2021/03/24 03:38:52 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_c(va_list ap, t_info *ft_box)
{
	char	c;
	int		count;

	count = 0;
	c = (char)va_arg(ap, int);
	if (ft_box->left_align == 0)
	{
		if (ft_box->zero == 1)
			count += print_zero(ft_box->width - 1);
		else
			count += print_blank(ft_box->width - 1);
		count += write(1, &c, 1);
	}
	else
	{
		count += write(1, &c, 1);
		count += print_blank(ft_box->width - 1);
	}
	return (count);
}
