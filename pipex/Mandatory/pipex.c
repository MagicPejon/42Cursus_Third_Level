/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:40:06 by amalbrei          #+#    #+#             */
/*   Updated: 2022/06/27 12:46:10 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*DESCRIPTION

Finds the path towards the commands known in bash commands

PARAMETERS

char **envp: the environment variables, used to help programs know what
directory to install files in, where to store temporary files and find user
profile settings.

NOTE

Remember that envp is a 2D array, so *envp is each line when comparing, type
env in your terminal to find the environmental variables.

Here strncmp is comparing each first 4 letters of each line with "PATH"
to find the right pointer that starts with "PATH" then skip the "PATH=" with a
+5 to its pointer.

*/
char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

/*DESCRIPTION

Closes pipes so that the reading and writing happening within the pipe can start

PARAMETERS

t_pipex *pipex: pipex structure created within the pipex.h file, used to access
the pipe variables to close.

NOTE

Remember that pipe[0] is the input of the commands while pipe[1] is the output.
*/
void	close_pipes(t_pipex *pipex)
{
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
}

/* Project's PDF: https://cdn.intra.42.fr/pdf/pdf/52114/en.subject.pdf

DESCRIPTION

Creates a pipe which receives an input (that is a read file) and delivers it
to an output (that is the file to write on).

PARAMETERS

int ac: number of arguments from the command line.
char **av: the strings of arguments received from the command line.
char **envp: the environment variables, used to help programs know what
directory to install files in, where to store temporary files and find user
profile settings.

NOTES

pipex.infile will be the file to be read from to be written unto the pipe as 
an output.

pipex.outfile will be the file to become the output of the pipe to be read from
the pipe as an input.

WEXITSTATUS is used to get the return of the children processes by linking it to
a variable (here I used pipex.status) and return it as a parent process.
The parent process's return does not matter, but the child's does.
*/
int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
		return (msg(ERR_INPUT));
	pipex.outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.outfile < 0)
		msg_error(av[ac - 1]);
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
		msg_error(av[1]);
	if (pipe(pipex.pipe) < 0)
		msg_error(ERR_PIPE);
	pipex.paths = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child(pipex, av, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_child(pipex, av, envp);
	close_pipes(&pipex);
	waitpid(pipex.pid1, &pipex.status, 0);
	waitpid(pipex.pid2, &pipex.status, 0);
	parent_free(&pipex);
	return (WEXITSTATUS(pipex.status));
}
