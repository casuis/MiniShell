/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:20:19 by asimon            #+#    #+#             */
/*   Updated: 2022/03/05 16:20:20 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_error(char *prog, char *msg)
{
	write(2, prog, ft_strlen(prog));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
}