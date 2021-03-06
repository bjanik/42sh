/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbj.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 10:55:18 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/27 13:26:08 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBJ_H
# define LIBBJ_H
# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>

# define TEMP_SIZE 4096
# define FD_MAX 7168

typedef struct		s_fd
{
	char			*tmp;
	char			*nl;
	size_t			mem_size;
}					t_fd;

typedef struct		s_dlst
{
	void			*data;
	size_t			data_size;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}					t_dlst;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_abs(int i);
int					ft_str_isdigit(char *str);
void				ft_free_string_tab(char ***tab);
void				ft_swap(void **a, void **b);
char				*ft_strnjoin(char *s1, int n, ...);
void				ft_dlstadd(t_dlst **alst, t_dlst *new);
t_dlst				*ft_dlstnew(void const *data, size_t data_size);
void				ft_dlstdel(t_dlst **alst, void (*del)(void *, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
size_t				ft_tab_len(char **tab);
int					get_next_line(int fd, char **line);
#endif
