/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 08:57:39 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/26 10:00:53 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char **argv)
{
    if (argc != 3)
		return (1);
	pid_t pid = atoi(argv[1]);
	char *msg = argv[2];

	while (*msg)
	{
		kill(pid, SIGUSR1);
		usleep(100);
		msg++;
	}
}