/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:49:51 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/04 20:58:11 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>
# include <termios.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"
# include "get_next_line.h"

# define SINGLE 0
# define DOUBLE 1
# define NONE 2 

# define IN 1
# define OUT 2
# define APPEND 3
# define HEREDOC 4

# define NON_VALID 0
# define VALID 1

# define SUCCESS 0
# define ERROR 1

# define NONE_ERR 0
# define NUMERIC_REQUIRED 1
# define TOO_MANY_ARGUMENTS 2

extern int	g_exit_state;

typedef struct s_rd
{
	int			type;
	char		*argument;
	int			is_quote;
	struct s_rd	*next;
}	t_rd;

typedef struct s_data
{
	char			*path;
	char			*content;
	char			**argv;
	struct s_data	*next;
	int				is_heredoc;
	t_rd			*rd;
}	t_data;

typedef struct s_env
{
	char			*content;
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_temp_node
{
	char				*str;
	int					is_quote;
	struct s_temp_node	*next;
}	t_temp;

typedef struct s_exec_vars
{
	int		prev_fd;
	int		t_size;
	int		filedes_here[2];
}	t_exec_vars;

enum e_parse_type
{
	CMD,
	t_IN,
	t_OUT,
	t_APPEND,
	t_HEREDOC
} ;

typedef struct s_parse
{
	char			*arg;
	int				type;
	int				is_syntax;
	struct s_parse	*next;
}	t_parse;
// minishell_utils.c
int		ft_builtin_for_parents(char **argv);
void	init(int argc, char **argv, char **env, t_env **custom_env);
char	*ft_get_line(t_env *envp);
t_data	*ft_parsing_process(char *line, t_env *envp);
void	ft_wait_process(int size, pid_t pid);
// list/t_data_lst.c
void	t_data_lstadd_back(t_data **lst, t_data *new);
void	t_data_lstclear(t_data **lst);
void	t_data_lst_delone(t_data *lst);
t_data	*ft_new_parsing_node(char *content);
int		t_data_lstsize(t_data *lst);
// list/t_rd_lst.c
void	t_rd_lstadd_back(t_rd **lst, t_rd *new);
t_rd	*t_rd_lstnew(t_parse *p);
void	t_rd_lst_delone(t_rd *lst);
void	t_rd_lstclear(t_rd **lst);
// list/t_parse_lst.c
void	t_parse_lst_delone(t_parse *lst);
void	t_parse_lstclear(t_parse **lst);
int		t_parse_lstsize(t_parse *parse_node);
void	t_parse_lstadd_back(t_parse **lst, t_parse *new);
t_parse	*t_parse_lstnew(char *arg);
// list/t_temp_lst.c
void	quote_lstadd_back(t_temp **lst, t_temp *new);
void	t_temp_lstdelone(t_temp *lst);
void	t_temp_lst_clear(t_temp **lst);
t_temp	*ft_quote_add_node(char *str, int is_quote);
char	*ft_create_new_argv(t_temp *head);
// list/t_env_lst.c
int		t_env_lstsize(t_env *lst);
void	t_env_lstclear(t_env **lst);
void	t_env_lst_delone(t_env *lst);
// parse/parse.c
t_data	*ft_parse(t_data *p_node, t_env *envp);
t_parse	*ft_make_parse_node(char *str);
t_parse	*ft_quota_env_convert(t_parse *parse_node, t_env *envp);
t_data	*ft_process_redirection(t_data *new_parsing_node, t_parse *parse_node);
t_data	*ft_parsing_pipe(char *line, t_data *p_node, int start);
// parse/make_parse_arg.c
t_parse	*ft_make_parse_arg(t_parse *parse_node, char *str, int start, int i);
int		ft_loop_quote(char *str, int i);
int		ft_loop_redirection(char *str, int i);
int		ft_loop_start(char *str, int i);
char	**ft_make_argv(t_parse *parse_node, int lst_size);
// parse/make_parse_type.c
int		ft_get_parse_node_type(char *str);
t_parse	*ft_insert_parse_type(t_parse *parse_node);
// parse/quote_converter.c
t_temp	*ft_divied_quote(char *str, t_temp *head);
size_t	ft_count_size(char *str, int *flag);
char	*ft_trim_env(char const *s, unsigned int start, size_t len);
int		ft_is_quote(char c);
//	parse/env_converter.c
t_temp	*ft_find_env(t_temp *head, t_env *envp);
int		ft_total_size(char *p, t_env *envp);
char	*ft_env_converter(char *str, char *af_s, char *ft_env, t_env *envp);
int		ft_check_env(char c);
char	*ft_env_convert(char *ft_env, t_env *envp);
// parse/make_path.c
char	*ft_find_path(char **env_path, char *cmd);
t_data	*ft_path(t_data *parsing_data, t_env *envp);
char	*ft_getenv(char *key, t_env *envp);
// parse/parse_utils.c
int		ft_env_dollar_count(char *str);
int		ft_validate_arg(char *arg);
t_parse	*ft_is_redirect_arg(t_parse *p);
int		ft_syntax_is_flag(t_rd *rd);
int		ft_is_space(char c);
// parse/parse_check.c
int		ft_check_env_dollar(char *ft_env);
t_data	*ft_check_syntax(t_data *p_data);
t_data	*ft_check_pipe(char *line, t_data *p_node);
int		ft_check_quote(char *line);
t_data	*ft_print_syntax(t_data *p_data, char *str);
// execute/utils.c
void	ft_tolower_env(char *str);
char	**ft_list_to_arr(t_env *envp);
void	ft_check_path(char *path, t_data *parsing_data, t_env *envp);
int		ft_is_directory(char *path, t_data *parsing_data);
void	ft_wait(pid_t pid, int *flag);
// execute/redirection.c
void	ft_other_redirection(char *argument, int std_fd, int option);
void	ft_redirection(t_data *parsing_data, int *filedes);
int		ft_heredoc_parents(t_rd *rd, int *filedes, t_env *envp);
char	*ft_handling_env(char *buf, t_env *custom_env);
// excute/heredoc.c
char	*ft_heredoc_get_line(char *limit);
void	ft_heredoc_child(int *filedes);
void	ft_fork_heredoc(t_rd *rd, int *filedes, t_env *envp);
int		ft_waitpid_heredoc(pid_t pid);
void	close_fd_heredoc(t_exec_vars *e_vars, int *filedes, int size);
// execute/process.c
void	ft_main_process(t_data **p_data, int *fd, int size, t_exec_vars *e_var);
void	ft_sub_end(t_data *p_data, int prev_fd, t_env *envp, int *fdes_here);
void	ft_sub(t_data *p_data, int *filedes, t_exec_vars *e_vars, t_env *envp);
// execute/execute.c
int		ft_check_built_in(t_data *parsing_data);
void	ft_excute_built_in(t_data *parsing_data, t_env *custom_env);
void	ft_execve(char *path, t_data *parsing_data, t_env *envp);
void	ft_pipe(int *filedes);
void	ft_excute(t_data *parsing_data, int size, t_env *envp);
// builtin/ft_cd.c
void	ft_check_oldpwd(t_env *custom_env);
char	*ft_add_str(char *content, char *value);
void	ft_search_key(char *origin_wd, t_env *custom_env);
void	ft_not_moving(char *origin_wd, char *argv);
int		ft_cd(t_data *parsing_data, t_env *custom_env);
// builtin/ft_cd_home.c
char	*ft_find_home(t_env *custom_env);
int		ft_print_error_cd(char *argv);
void	ft_add_home(t_data *parsing_data, t_env *custom_env);
int		ft_set_home(t_data *parsing_data, t_env *custom_env, char *origin_wd);
// builtin/ft_echo.c
int		ft_validate_option(char *argv);
int		ft_check_null(char *argv);
int		ft_echo(t_data *parsing_data, int i);
// builtin/ft_env.c
int		ft_env(t_env *custom_env, char **argv);
// builtin/ft_exit.c
int		ft_is_num(char *str);
void	ft_exit_error(int flag);
int		ft_validate_exit_arg(t_data *parsing_data, int *flag);
void	ft_malloc_exit(void);
void	ft_exit(t_data *parsing_data);
// builtin/ft_export_add_env.c
int		ft_valid_data(char *str);
void	ft_free_env(t_env *env);
void	ft_change_value(t_env **lst, t_env *new);
void	env_lstadd_back(t_env **lst, t_env *new);
t_env	*env_lstnew(char *content);
// builtin/ft_export_print.c
t_env	*ft_merge(t_env *left, t_env *right);
void	ft_move_next(t_env **slow, t_env **fast);
void	ft_mergesort(t_env **headRef);
void	ft_print_env(t_env *new_list);
t_env	*ft_duplicate_list(t_env *custom_env);
// builtin/ft_export.c
int		ft_export(t_data *parsing_data, t_env *custom_env);
// builtin/ft_pwd.c
int		ft_pwd(void);
// builtin/ft_unset.c
int		ft_unset(t_data *parsing_data, t_env *custom_env);
// upd_split_utils.c
int		not_charset(char c, char charset);
void	quote_flag(char quote, int *flag);
int		word_count(char const *s, char c);
void	ft_memfree(char **result, int word);
int		ft_count_str_in_quote(char const *s, char c, int flag[2], int j);
// upd_split.c
void	excute_ft_split(char **result, char const *s, char c, int i);
char	**upd_split(char const *s, char c);
// signal
void	sig_handler(int signum);
void	sig_handler_excute(int signum);
// error
void	ft_defined_error(char *error_message, char *arg);
void	ft_standard_error(char *argv);
char	*ft_make_err_arg(char *arg);
// setting_terminal.c
void	ft_set_termios(void);
void	ft_reset_termios(void);
// free.c
void	ft_double_free(char **argv);
// Add
char	*ft_remove_quote(char *str);
#endif