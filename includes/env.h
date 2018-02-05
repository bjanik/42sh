/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:50:58 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/21 16:18:57 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

# define TRUE 1
# define FALSE 0

enum {
	LOCAL,
	GLOBAL,
	GLOBAL_AND_LOCAL,
};

typedef struct s_env_list
{
	char				*name;
	char				*value;
	unsigned short		exportable;
	struct s_env_list	*next;
}						t_env_list;

typedef struct s_env
{
	struct s_env_list	*env_list;
	char				**env_array;
	size_t				env_len;
	unsigned short		has_changed;
}						t_env;

int						init_env(t_env *env, char **environ);

t_env_list				*ft_getenv(t_env_list *env_list,
						const char *const name);

char					**convert_env_to_array(t_env_list *env_list,
						const size_t len);

t_env_list				*convert_environ_to_list(char **environ);

int						display_global_env(t_env_list const *env_list);
int						display_local_env(t_env_list const *env_list);
int						display_global_local_env(t_env_list const *env_list);

int						append_variable_to_env(t_env *env,
						const char *const name, const char *const value,
						unsigned short exportable);

int						remove_variable_from_env(t_env *env,
						const char *const name);