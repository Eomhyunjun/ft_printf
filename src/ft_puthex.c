/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 23:58:22 by heom              #+#    #+#             */
/*   Updated: 2021/03/24 03:39:27 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int			recur(unsigned long long n, int count, t_info *ft_box)
{
	char	pnt;

	if (n >= 16)
		count += recur(n / 16, count, ft_box);
	if (ft_box->type == 'X')
		pnt = "0123456789ABCDEF"[n % 16];
	else
		pnt = "0123456789abcdef"[n % 16];
	count += write(1, &pnt, 1);
	return (count);
}

int					ft_puthex(unsigned long long n, t_info *ft_box)
{
	int count;

	count = 0;
	if (n == 0)
	{
		count += write(1, "0", 1);
		return (count);
	}
	count += recur(n, count, ft_box);
	return (count);
}
