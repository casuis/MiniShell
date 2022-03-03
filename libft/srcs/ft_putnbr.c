/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:53:45 by asimon            #+#    #+#             */
/*   Updated: 2022/02/08 21:53:46 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr(int nb, int base)
{
	char	*base_set;
	int		i;
	
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			ft_putstr("-2147483648");
			return ;
		}
		ft_putchar('-');
		nb = -nb;
	}
	i = nb % base;
	base_set = "0123456789abcdef";
	if (nb / base > 0)
		ft_putnbr(nb / base, base);
	ft_putchar(base_set[i]);
}
