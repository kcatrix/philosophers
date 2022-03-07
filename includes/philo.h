/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: operculesanguinaire <operculesanguinair    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:45:36 by kevyn             #+#    #+#             */
/*   Updated: 2022/03/07 14:51:48 by operculesan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "macro.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		philo(int argc, char **argv);
char	get_error(int i);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int 	parse(int argc, char **argv);

#endif