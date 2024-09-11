/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:59:44 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/09/11 10:58:39 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct s_mini
{
	int		pid;
	int		pid_server;
	int		pid_client;
}			t_mini;

t_mini	*client(void);
void	send_signal(t_mini *talk, char *str);
void	client_sigsent(int sigsent);
void	client_signal(t_mini *talk);
t_mini	*server(void);
void	server_sigsent(int sigsent);
void	server_signal(t_mini *talk);
size_t	ft_strlen(char *str);
int		ft_atoi(const char *str);
int		ft_putstr(char *str);
void	ft_putnbr(int num);

#endif
