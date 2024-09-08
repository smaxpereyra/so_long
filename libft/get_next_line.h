/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:30:55 by spereyra          #+#    #+#             */
/*   Updated: 2023/09/02 11:39:03 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

/* Node of the linked list */
typedef struct s_list
{
	char			*buf;
	struct s_list	*next;	
}				t_list;

char	*get_next_line(int fd);
char	*fetch_line(t_list *list);
void	create_list(t_list **list, int fd);
void	append(t_list **list, char *buf);
void	clean_list(t_list **list);
void	copy_line(t_list *list, char *line_str);
int		len_to_nl(t_list *list);
int		found_nl(t_list *list);
void	dealloc(t_list **list, char *buf);
void	free_list(t_list **list);

#endif
