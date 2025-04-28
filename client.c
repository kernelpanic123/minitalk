/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 08:57:39 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/28 04:19:22 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_bin(pid_t pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(500);
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	nombre;
	int	signe;

	i = 0;
	nombre = 0;
	signe = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nombre = nombre * 10 + (str[i] - '0');
		i++;
	}
	return (nombre * signe);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;
	int		i;

	if (argc != 3)
		exit(0);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	while (str[i] != '\0')
	{
		char_to_bin(pid, str[i]);
		i++;
	}
	char_to_bin(pid, '\0');
	i++;
	char_to_bin(pid, '\n');
	i++;
	return (0);
}
