/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 08:52:07 by heom              #+#    #+#             */
/*   Updated: 2021/03/24 03:44:43 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_process(va_list ap, t_info *ft_box)
{
	int count;

	count = 0;
	if (ft_box->type == 'c')
		count = print_c(ap, ft_box);
	else if (ft_box->type == 's')
		count = process_s(ap, ft_box);
	else if (ft_box->type == 'i' || ft_box->type == 'd')
		count = process_num(va_arg(ap, int), ft_box);
	else if (ft_box->type == 'x' || ft_box->type == 'X' || ft_box->type == 'u')
		count = process_num(va_arg(ap, unsigned int), ft_box);
	else if (ft_box->type == 'p')
		count = process_num(va_arg(ap, unsigned long long), ft_box);
	else if (ft_box->type == '%')
		count = print_percent(ft_box);
	else
		return (0);
	return (count);
}
