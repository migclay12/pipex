/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:36:36 by miggonza          #+#    #+#             */
/*   Updated: 2023/02/22 14:08:02 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_pf(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

int	ft_putchar_pf(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_pf(char	*s)
{
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}
