/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:03:42 by spereyra          #+#    #+#             */
/*   Updated: 2023/11/18 13:53:34 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = 0;
	last_node = 0;
	last_node = *list;
	while (last_node != 0 && last_node->next != 0)
		last_node = last_node->next;
	new_node = malloc(sizeof(t_list));
	if (new_node == 0)
	{
		free(buf);
		free_list(list);
		return ;
	}
	if (last_node == 0)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->buf = buf;
	new_node->next = 0;
}

void	copy_line(t_list *list, char *line_str)
{
	int	i;
	int	k;

	if (list == 0)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->buf[i])
		{
			if (list->buf[i] == '\n')
			{
				line_str[k++] = '\n';
				line_str[k] = '\0';
				return ;
			}
			line_str[k++] = list->buf[i++];
		}
		list = list->next;
	}
	line_str[k] = '\0';
}

int	len_to_nl(t_list *list)
{
	int	i;
	int	len;

	if (list == 0)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->buf[i])
		{
			if (list->buf[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

int	found_nl(t_list *list)
{
	int	i;

	if (list == 0)
		return (0);
	while (list)
	{
		i = 0;
		while (list->buf[i] && i < BUFFER_SIZE)
		{
			if (list->buf[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

void	dealloc(t_list **list, char *buf)
{
	t_list	*first_node;

	if (*list == 0)
		return ;
	free_list(list);
	first_node = malloc(sizeof(t_list));
	if (first_node == 0)
	{
		free_list(list);
		return ;
	}
	first_node->buf = buf;
	first_node->next = 0;
	if (first_node->buf[0])
		*list = first_node;
	else
	{
		free(buf);
		free(first_node);
	}
}
