/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:30:29 by diegrod2          #+#    #+#             */
/*   Updated: 2025/03/14 13:31:12 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_win(t_vars *vars)
{
	printf("Close Window\n");
	clean_up_all(vars);
	exit(EXIT_FAILURE);
	return (0);
}