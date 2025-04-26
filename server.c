/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 08:58:29 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/26 09:52:37 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    handle_signal(int sig)
{
    if (sig == SIGUSR1)
        write(1, "1", 1);
    else if (sig == SIGUSR2)
        write(1, "0", 1);
}
int main(void)
{
    __pid_t pid;

    pid = getpid();
    ft_printf("PID = %d", pid);
    signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
    while (1)
    {
        pause();
    }
}