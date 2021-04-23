/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:23:53 by heom              #+#    #+#             */
/*   Updated: 2021/03/25 18:34:13 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsing_ft(char **temp, t_info *ft_box, va_list ap)
{
	++*temp;
	(void)ft_box;
	parsing_flags(temp, ft_box);
	parsing_width(temp, ft_box, ap);
	parsing_pre(temp, ft_box, ap);
	parsing_type(temp, ft_box);
}

void	parsing_flags(char **temp, t_info *ft_box)
{
	while (1)
	{
		if (**temp == '-')
			ft_box->left_align = 1;
		else if (**temp == '0')
			ft_box->zero = 1;
		else
			break ;
		++*temp;
	}
}

void	parsing_width(char **temp, t_info *ft_box, va_list ap)
{
	if (**temp == '*')
	{
		ft_box->width = va_arg(ap, int);
		if (ft_box->width < 0)
		{
			ft_box->width = -ft_box->width;
			ft_box->left_align = 1;
		}
		++*temp;
	}
	else
		ft_box->width = simple_atoi(temp);
}

void	parsing_pre(char **temp, t_info *ft_box, va_list ap)
{
	if (**temp == '.')
	{
		++*temp;
		if (**temp == '*')
		{
			++*temp;
			ft_box->prec = va_arg(ap, int);
			if (ft_box->prec < 0)
				ft_box->prec = -1;
		}
		else if (**temp >= '0' && **temp <= '9')
			ft_box->prec = simple_atoi(temp);
		else
			ft_box->prec = 0;
	}
}

void	parsing_type(char **temp, t_info *ft_box)
{
	ft_box->type = **temp;
}
