/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 06:06:15 by anpichon          #+#    #+#             */
/*   Updated: 2015/12/07 06:07:46 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;
	void	*data;

	if (!(ptr = (t_list*)malloc(sizeof(t_list) * 1)))
		return (NULL);
	(*ptr).next = NULL;
	if (!content)
	{
		ptr->content = NULL;
		ptr->content_size = 0;
		return (ptr);
	}
	if (!(data = malloc(sizeof(content) * content_size)))
		return (NULL);
	ptr->content = ft_memcpy(data, content, content_size);
	ptr->content_size = content_size;
	return (ptr);
}
