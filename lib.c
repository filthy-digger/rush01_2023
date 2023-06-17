/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:43:13 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/17 15:46:36 by agabasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

size_t	ft_strlen(char *str)
{
	char	*save;

	save = str;
	while(str != NULL && *str != '\0')
		str++;
	return (str - save); 
}

void	ft_putstr(char *str)
{
	while(str && *str)
		write(1, *(str++), 1);
}

int	*permute(int *prev, size_t size)
{
	int	*next;

	next = (int *)malloc(size * sizeof(int));
	if (next == NULL)
		return next;
	return next;
}
