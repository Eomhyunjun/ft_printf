/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 07:39:41 by heom              #+#    #+#             */
/*   Updated: 2021/03/25 17:14:47 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long			simple_atoi(char **temp)
{
	unsigned long long num;

	num = 0;
	while ('0' <= **temp && **temp <= '9')
	{
		num = num * 10 + (**temp - '0');
		++*temp;
	}
	return (num);
}

int							print_blank(int num)
{
	int count;

	count = 0;
	while (num-- > 0)
		count += write(1, " ", 1);
	return (count);
}

int							print_zero(int num)
{
	int count;

	count = 0;
	while (num-- > 0)
		count += write(1, "0", 1);
	return (count);
}
