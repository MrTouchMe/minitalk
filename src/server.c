/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:55:33 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/19 17:12:38 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_global	g_global = {.message = NULL, .index = 0, .bit_index = 0, .size = 0};

int	main(void)
{
	ft_printf("server PID: %d\n", getpid());
	g_global.message = "42";
	ft_printf("%s\n", g_global.message);
	return (0);
}
