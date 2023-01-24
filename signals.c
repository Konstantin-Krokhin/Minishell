/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:05:21 by mgranero          #+#    #+#             */
/*   Updated: 2023/01/24 21:12:33 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	signals to be handled
		◦ ctrl-C displays a new prompt on a new line. => SIGINT
		◦ ctrl-D exits the shell. => SIGQUIT
			Many programs won't respond to a SIGQUIT (some might, it's up to them)
			but bash itself will. If you're in a bash prompt and it want it to exit
			(like if you're remotely connected to a bash server for example),
			if you hit CTRL + D it'll tell the bash session to end.
		◦ ctrl-\ does nothing. => Ctrl-\ sends a QUIT signal (SIGQUIT);
			by default, this causes the process to terminate and dump core.
*/

		//struct sigaction	sa;

		// 	if (sigaction(SIGINT, &sa, NULL) == -1)
		// {
		// 	write(2, "Error: sigaction SIGINT\n", 23);
		// 	ft_clean_memory();
		// 	return (1);
		// }


void	setup_sighandler(void)
{
	sigemptyset(&g_srv.sa.sa_mask);
	sigaddset(&g_srv.sa.sa_mask, SIGQUIT);
	sigaddset(&g_srv.sa.sa_mask, SIGINT);
	g_srv.sa.sa_flags = SA_SIGINFO;
	g_srv.sa.sa_sigaction = &ft_handle_sig;
}

void	ft_handle_sigint(void)
{
	write(1, "\n>>Cleaning memory", 18);
	ft_lstclear(&(g_srv.lst_encoded), &free);
	g_srv.on_off = 0;
}