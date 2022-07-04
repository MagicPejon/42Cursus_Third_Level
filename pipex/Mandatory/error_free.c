/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:40:39 by amalbrei          #+#    #+#             */
/*   Updated: 2022/07/02 17:21:58 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*DESCRIPTION

Returns the error message, this one is a variant case if perror() will not work.

PARAMETERS

char *err: error message given, indicated by pipex.h.

NOTE

Returns 1 as well for the int main, which indicates an error happening during
compilation.
*/
int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

/*DESCRIPTION

Returns the error message, using the perror function.

PARAMETERS

char *err: error message given, indicated by pipex.h.

NOTE

uses exit (1) to terminate the program.
*/
void	msg_error(char *err, t_pipex *pipex)
{
	if (pipex->infile < 0)
		close (pipex->outfile);
	if (pipex->infile > 2)
	{
		close (pipex->outfile);
		close (pipex->infile);
	}
	perror(err);
	exit (1);
}

/*DESCRIPTION

Frees the pipe from the parent's process, by closing files 
and freeing the contents

PARAMETERS

t_pipex pipex: the structure containing the pipe's variables.
*/
void	parent_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
}

/*DESCRIPTION

Frees the pipe from the child's process, by freeing the contents

PARAMETERS

t_pipex pipex: the structure containing the pipe's variables.
*/
void	child_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
	i = 0;
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
}
