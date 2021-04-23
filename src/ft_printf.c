/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:21:16 by heom              #+#    #+#             */
/*   Updated: 2021/03/24 03:44:01 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			process_ft(const char *format, va_list ap)
{
	char	*temp;
	int		count;
	t_info	ft_box;

	count = 0;
	temp = (char *)format;
	while (*temp)
	{
		if (*temp == '%')
		{
			ft_bzero(&ft_box, sizeof(t_info));
			ft_box.prec = -1;
			parsing_ft(&temp, &ft_box, ap);
			count += print_process(ap, &ft_box);
		}
		else
			count += write(1, temp, 1);
		temp++;
	}
	return (count);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = process_ft(format, ap);
	va_end(ap);
	return (count);
}
