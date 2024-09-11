/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:05:43 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/09/11 10:59:10 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minitalk.h"

t_mini	*server(void)
{
	t_mini	*talk;

	talk = malloc(sizeof(t_mini));
	if (!talk)
	{
		ft_putstr("ERROR!, malloc failed :( !\n");
		exit(EXIT_FAILURE);
	}
	talk->pid_server = 0;
	talk->pid_client = 0;
	return (talk);
}

void	server_sigsent(int sigsent)
{
	static int	bit;
	static char	letter;

	letter = letter << 1 | (sigsent == SIGUSR2);
	bit++;
	if (bit == 8)
	{
		if (!letter)
			write(1, "\n", 1);
		else
			write(1, &letter, 1);
		bit = 0;
		letter = 0;
	}
	return ;
}

void	server_signal(t_mini *talk)
{
	while (1)
	{
		if ((signal(SIGUSR1, server_sigsent) == SIG_ERR)
			|| (signal(SIGUSR2, server_sigsent) == SIG_ERR))
		{
			ft_putstr("ERROR!, Signal error!\n");
			free(talk);
			exit(EXIT_FAILURE);
		}
		sleep(2);
	}
	return ;
}

int	main( int argc, char *argv[] )
{
	t_mini	*talk;

	(void)argv;
	talk = NULL;
	if (argc != 1)
	{
		ft_putstr("ERROR!, invalid number of arguments!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		talk = server();
		talk->pid_server = getpid();
		ft_putstr("Server PID: ");
		ft_putnbr(talk->pid_server);
		write(1, "\n", 1);
	}
	server_signal(talk);
	free(talk);
	return (0);
}
