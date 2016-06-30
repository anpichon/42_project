/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 06:10:13 by anpichon          #+#    #+#             */
/*   Updated: 2015/12/07 06:12:48 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;

	while ((ptr = (**alst).next))
	{
		(*del)((**alst).content, (**alst).content_size);
		free(*alst);
		*alst = ptr;
	}
	(*del)((**alst).content, (**alst).content_size);
	free(*alst);
	*alst = NULL;
}
