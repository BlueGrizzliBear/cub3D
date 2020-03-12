/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:38:07 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:50:04 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 100

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef	struct		s_gnl
{
	void			*content;
	int				fd;
	int				size;
	char			temp[BUFFER_SIZE + 1];
	struct s_gnl	*before;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(int fd, char **line);
char				*read_line(t_gnl *lst, int fd, t_gnl *alst);
char				*write_line(t_gnl *lst, char **line, t_gnl *alst);
char				*gnl_strdup(const char *s1, t_gnl *alst);
char				*gnl_strjoin(const char *s1, const char *s2, t_gnl *alst);
char				*gnl_abort(t_gnl **lst);
int					gnl_free(t_gnl **lst, t_gnl *current);
int					gnl_scan(char *str);
t_gnl				*gnl_scan_fd(t_gnl *lst, int fd);
t_gnl				*gnl_lstnew_addfront(void *content, int fd, t_gnl **alst);

#endif
