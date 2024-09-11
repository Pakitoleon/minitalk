/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:16:40 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/09/11 10:59:32 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minitalk.h"

t_mini	*client(void)
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

void	send_signal(t_mini *talk, char *str)
{
	int				i;
	int				bit;
	int				signal;

	i = -1;
	while (i++ <= ((int)ft_strlen(str)-1))
	{
		bit = -1;
		signal = 0;
		while (++bit < 8)
		{
			if ((str[i] >> (7 - bit)) & 1)
				signal = SIGUSR2;
			else
				signal = SIGUSR1;
			kill(talk->pid_server, signal);
			usleep(100);
		}
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_mini		*talk;

	talk = NULL;
	if (argc != 3)
	{
		ft_putstr("ERROR, Use \"./server\" with 3 arguments\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		talk = client();
		talk->pid_server = ft_atoi(argv[1]);
		if (talk->pid_server < 0)
		{
			ft_putstr("ERROR, invalid PID format (0 x-x)\n");
			exit(EXIT_FAILURE);
		}
		send_signal(talk, argv[2]);
	}
	return (EXIT_SUCCESS);
}
