/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 03:42:14 by heom              #+#    #+#             */
/*   Updated: 2021/03/24 03:42:42 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(t_info *ft_box)
{
	int count;

	count = 0;
	if (ft_box->left_align == 0)
	{
		if (ft_box->zero == 1)
			count += print_zero(ft_box->width - 1);
		else
			count += print_blank(ft_box->width - 1);
		count += write(1, "%", 1);
	}
	else
	{
		count += write(1, "%", 1);
		count += print_blank(ft_box->width - 1);
	}
	return (count);
}
