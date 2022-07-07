/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:42:01 by amalbrei          #+#    #+#             */
/*   Updated: 2022/07/06 16:27:26 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*DESCRIPTION

Checks if the argument contains a double quotes to hold a sentence for certain
commands.

PARAMETERS

char *command: the argument of a command.
*/
int	check_doublequotes(char *command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (command[i] == '"')
		{
			i++;
			if (ft_strchr(command + i, '"'))
				return (1);
		}
		i++;
	}
	return (0);
}

/*DESCRIPTION

Retrieves the command's path from the pipex.paths variable 
(which is retrieved from the environmental variable) and joins it with the
command given by the command line (av).

PARAMETERS

char **paths: a 2D array containing the paths towards the commands 
stored in the computer.
char *cmd: command retrieved from the arguments stated in the command line.

NOTE

The function loops until the command is found using the access function.
*/
static	char	*retrieve_cmd(char **paths, char *cmd)
{
	char	*temp;
	char	*bash_command;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (*paths)
	{
		if (!cmd)
			break ;
		temp = ft_strjoin(*paths, "/");
		bash_command = ft_strjoin(temp, cmd);
		if (access(bash_command, X_OK) == 0)
		{
			free (temp);
			return (bash_command);
		}
		free (bash_command);
		free (temp);
		paths++;
	}
	return (NULL);
}

/*DESCRIPTION

Process of the first child, which contains the infile as stdin and the pipe[1]
as stdout, which helps that end of the file to write a message towards the other
end of the pipe

PARAMETERS

t_pipex pipex: structure containing the pipe's contents.
char **av: the arguments retrieved from the command line.
char **envp: the environment variable, see int main for more info.

NOTE

execve() is used here which will need the given command's path, the arguments
stated in the command line and the environment variable.

pipe[0] needs to be closed for this process to work.
*/
void	first_child(t_pipex pipex, char **av, char **envp)
{
	dup2(pipex.pipe[1], 1);
	close(pipex.pipe[0]);
	dup2(pipex.infile, 0);
	if (check_doublequotes(av[2]))
		pipex.cmd_args = pipex_split(av[2], ' ');
	else
		pipex.cmd_args = ft_split(av[2], ' ');
	pipex.cmd = retrieve_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		close (pipex.pipe[1]);
		child_free(&pipex);
		msg(av[2]);
		msg(ERR_CMD);
		exit(127);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

/*DESCRIPTION

Process of the second child, which contains the outfile as stdout and the pipe[0]
as stdin, which helps that end of the file to read a message retrieved from the
writing end of the pipe.

PARAMETERS

t_pipex pipex: structure containing the pipe's contents.
char **av: the arguments retrieved from the command line.
char **envp: the environment variable, see int main for more info.

NOTE

execve() is used here which will need the given command's path, the arguments
stated in the command line and the environment variable.

pipe[1] needs to be close for this process to work.
*/
void	second_child(t_pipex pipex, char **av, char **envp)
{
	dup2(pipex.pipe[0], 0);
	close(pipex.pipe[1]);
	dup2(pipex.outfile, 1);
	if (check_doublequotes(av[3]))
		pipex.cmd_args = pipex_split(av[3], ' ');
	else
		pipex.cmd_args = ft_split(av[3], ' ');
	pipex.cmd = retrieve_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		close (pipex.pipe[0]);
		child_free(&pipex);
		msg(av[3]);
		msg(ERR_CMD);
		exit(127);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}
