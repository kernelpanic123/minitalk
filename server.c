/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 08:58:29 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/28 04:40:26 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	bin_to_char(unsigned char c, int bit)
{
	return ((c << 1) | (bit & 1));
}

void	handler(int sig)
{
	static unsigned char	c = 0;
	static int				byte_count = 0;

	if (sig == SIGUSR1)
		c = bin_to_char(c, 0);
	else if (sig == SIGUSR2)
		c = bin_to_char(c, 1);
	byte_count++;
	if (byte_count == 8)
	{
		write(1, &c, 1);
		c = 0;
		byte_count = 0;
	}
}

int	main(void)
{
	ft_printf("PID = %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
