/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: operculesanguinaire <operculesanguinair    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:45:36 by kevyn             #+#    #+#             */
/*   Updated: 2022/03/07 13:06:30 by operculesan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "macro.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		pipex(int argc, char **argv, char **env);
char	get_error(int i);
char	**path_fct(char **env);
int		verif_file(int argc, char **argv);
int		verif_exist(char **path, char *argv);
int		child_process(char **argv, char **path, char **env, int *fd);
int		parent_process(char **argv, char **path, char **env, int *fd);

#endif