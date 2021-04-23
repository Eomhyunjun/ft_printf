/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:03:22 by heom              #+#    #+#             */
/*   Updated: 2021/03/24 03:40:13 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int			recur(unsigned long long n, int count)
{
	char	pnt;

	if (n >= 10)
		count += recur(n / 10, count);
	pnt = '0' + (n % 10);
	count += write(1, &pnt, 1);
	return (count);
}

int					ft_putnbr(unsigned long long n)
{
	int count;

	count = 0;
	if (n == 0)
	{
		count += write(1, "0", 1);
		return (count);
	}
	count += recur(n, count);
	return (count);
}
