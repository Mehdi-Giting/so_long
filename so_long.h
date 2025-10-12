/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 01:17:57 by marvin            #+#    #+#             */
/*   Updated: 2025/10/11 01:17:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "fcntl.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "mlx.h"

char	**parse(char *filename);

#endif