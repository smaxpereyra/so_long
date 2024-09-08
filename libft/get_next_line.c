/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:36:35 by spereyra          #+#    #+#             */
/*   Updated: 2023/11/18 13:53:24 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*fd are only positives - read gives -1 if some problems on reading
 -Create my list until i stumble into '\n'
 -fetch the line from the list
 -Keep chars after '/n' in list and clean everything else*/
char	*get_next_line(int fd)
{
	static t_list	*list = 0;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, &next_line, 0) < 0))
	{
		free_list(&list);
		return (0);
	}
	create_list(&list, fd);
	if (list == 0)
		return (0);
	next_line = fetch_line(list);
	if (list == 0)
		return (0);
	clean_list(&list);
	return (next_line);
}

/* Necessary to place \0 -> string\0 */
void	create_list(t_list **list, int fd)
{
	int		read_chars;
	char	*buf;

	buf = 0;
	while (!found_nl(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == 0)
		{
			free_list(list);
			return ;
		}
		read_chars = read(fd, buf, BUFFER_SIZE);
		if (!read_chars)
		{
			free(buf);
			buf = 0;
			return ;
		}
		buf[read_chars] = '\0';
		append(list, buf);
	}
}

/*Count how many chars are till '\n'
 -Copy the line from the list to line_str
*/
char	*fetch_line(t_list *list)
{
	int		line_len;
	char	*line_str;

	if (list == 0)
		return (0);
	line_len = len_to_nl(list);
	line_str = 0;
	line_str = malloc(line_len + 1);
	if (line_str == 0)
	{
		free_list(&list);
		return (0);
	}
	copy_line(list, line_str);
	return (line_str);
}

void	clean_list(t_list **list)
{
	t_list	*last_node;
	int		i;
	int		k;
	char	*buf;

	if (*list == 0)
		return ;
	last_node = 0;
	buf = malloc(BUFFER_SIZE + 1);
	if (buf != 0)
	{
		last_node = *list;
		while (last_node && last_node->next != 0)
			last_node = last_node->next;
		i = 0;
		k = 0;
		while (last_node->buf[i] != '\0' && last_node->buf[i] != '\n')
			i++;
		while (last_node->buf[i] != '\0' && last_node->buf[++i])
			buf[k++] = last_node->buf[i];
		buf[k] = '\0';
		dealloc(list, buf);
	}
	else
		free_list(list);
}

void	free_list(t_list **list)
{
	t_list	*tmp;

	tmp = 0;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->buf);
		free(*list);
		*list = tmp;
	}
	*list = 0;
}
