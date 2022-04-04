/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parsing.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:38:44 by asimon            #+#    #+#             */
/*   Updated: 2022/03/29 22:38:45 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARS_H
# define MINISHELL_PARS_H
# include "../../includes/minishell.h"

// Functions
int			quote_closed(char c, int *bol);
int			get_next_pipe(char *str);


// Work_str
int			pass_file(char *str, int i, int balise, int bol);
static int	get_work_str_size(char *str, int i, int balise);
char		*set_work_str(char *str, int i, int balise);

// Set Cmd
void		set_cmd_arg(char **work_str, t_cmd *cmds);
char		*get_cmd(char **str, t_cmd *cmds);

// Add
char		*set_new_ret(char *old, int size, int *i);
int			get_size(char *str, char del);
char		**add_arg(char *str, t_cmd *cmd, char *first);
void		send_new_arg(char *str, t_cmd *cmd, char *first);
char		*ft_add_var_env(char *old, char **str);
char		*ft_add_single_quote(char *old, char **str);
char		*ft_add_double_quote(char *old, char **str);
int			get_ldbl_quote(char *str);
int			ft_add(char *str, char *ret);
char		*ft_add_char(char *ret, char **str);

// Parsing
char		*set_in_out_work_str(char *str, int i, int pos);
char		*get_cmd_fd(char **str);
void		parse_out_file(char **str, t_cmd *cmd);
void		parse_in_file(char **str, t_cmd *cmd);
int			set_fd_out(char **str, int mod);
int			set_fd_in(char **str);

// Herdoc
char		*find_correct_name(char *file, int count);
char		*set_file_name(int count);
int			create_herdoc_fd(t_cmd *cmd);
char		*set_herdoc_del(t_cmd *cmd, char **work_str);
int			parse_herdoc(char **str, t_cmd *cmd);
char		*ft_add_single_quote_herdoc(char *old, char **str, char del);
char		*get_cmd_quote_herdoc(char *ret, char **str, t_cmd *cmd);
char		*get_herdoc_cmd(char **str, t_cmd *cmd);


#endif