/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:39:40 by amalbrei          #+#    #+#             */
/*   Updated: 2022/07/02 19:55:55 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* used to write, read, close, access, pipe, dup, dup2, execve and fork */
# include <unistd.h>

/* malloc, free and exit */
# include <stdlib.h>

/* open and unlink */
# include <fcntl.h>

/* waitpid and wait */
# include <sys/wait.h>

/* strerror */
# include <string.h>

/* perror */
# include <stdio.h>

/* to libft */
# include "libft/libft.h"

# define ERR_INFILE "Infile Error"
# define ERR_OUTFILE "Outfile Error"
# define ERR_INPUT "Invalid number of arguments\n\
Remember: < file1 cmd1 | cmd2 > file2"
# define ERR_PIPE "Pipe Error\n"
# define ERR_CMD " command argument not found\n"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe[2];
	int		infile;
	int		outfile;
	int		status;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;

/* pipex.c */
int		check_arguments(int ac, char **av);
char	*find_path(char **envp);
void	close_pipes(t_pipex *pipex);

/* error_free.c */
int		msg(char *err);
void	msg_error(char *err, t_pipex *pipex);
void	parent_free(t_pipex *pipex);
void	child_free(t_pipex *pipex);

/* processes.c */
int		check_doublequotes(char *command);
void	first_child(t_pipex pipex, char **av, char **envp);
void	second_child(t_pipex pipex, char **av, char **envp);

/* pipex_split.c */
int		pipex_getwordcount(const char *s, char c);
void	pipex_assigns(const char *s, char **str, char c, int count);
char	**pipex_split(const char *s, char c);

#endif