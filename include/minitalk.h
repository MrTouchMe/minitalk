/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:11:39 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/25 17:38:49 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/include/libft.h"
# include <sys/types.h>
# include <string.h>
# include <stdio.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>

# define BIT_ONE SIGUSR1
# define BIT_ZERO SIGUSR2

// typedef struct s_global
// {
// 	char	*message;
// 	int		index;
// 	int		bit_index;
// 	int		size;
// }			t_global;

typedef struct s_server
{
	size_t			size;
	bool			init;
	size_t			message_index;
	char*			message;
	unsigned char	byte;
	int				byte_index;
	int				client_pid;
	unsigned long	timeout;
}	t_server;

typedef struct s_client
{
	char	*message;
	size_t	index;
	int		bit_index;
	size_t	size;
	int		server_pid;
}			t_client;

#endif
