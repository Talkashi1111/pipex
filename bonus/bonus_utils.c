/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:35:43 by tkashi            #+#    #+#             */
/*   Updated: 2024/03/01 18:41:43 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_heredoc_child(t_pipex *pa)
{
	char	*line;
	char	*limiter;

	limiter = pa->argv[2];
	process_fd_and_pipes(pa);
	while (TRUE)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line || (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
				&& line[ft_strlen(limiter)] == '\n'))
		{
			free(line);
			break ;
		}
		if (write(STDOUT_FILENO, line, ft_strlen(line)) < 0)
		{
			ft_fprintf(STDERR_FILENO, "write: %s\n", strerror(errno));
			free(line);
			ft_clean_pipex(pa);
			exit(EXIT_FAILURE);
		}
		free(line);
	}
	ft_clean_pipex(pa);
	exit(EXIT_SUCCESS);
}