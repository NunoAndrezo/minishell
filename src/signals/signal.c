/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:05:05 by nuno              #+#    #+#             */
/*   Updated: 2024/12/18 02:07:32 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void siginfo_handler(int sig, siginfo_t *info, void *context);

int main()
{
	struct sigaction sa;
	
	sa.sa_sigaction = siginfo_handler; // Set handler with SA_SIGINFO
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO; // Use SA_SIGINFO to get detailed info
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	while (1)
	{
		write(STDOUT_FILENO, "minishell> ", 11);
		pause(); // Wait for signals
	}
	return 0;
}

void siginfo_handler(int sig, siginfo_t *info, void *context)
{
	// aqui adicionas o que quiseres para o minishell
	context = NULL;
	if (sig == SIGINT)
	{
		printf("\nCaught SIGINT (Ctrl+C) from PID: %d\n", info->si_pid);
	}
	else if (sig == SIGQUIT)
	{
		printf("\nCaught SIGQUIT (Ctrl+\\) from PID: %d\n", info->si_pid);
	}
	else if (sig == SIGTSTP)
	{
		printf("\nCaught SIGSTP (Ctrl+Z) - Ignored\n");
	}
	else
	{
		printf("\nCaught signal %d from PID: %d\n", sig, info->si_pid);
	}
}

/* Handling the Signals

Here’s how to handle the required signals:
Signals to Handle

    SIGINT (Ctrl+C):
        Interrupts the current process.
        it should interrupt the current command input or running child process

    SIGQUIT (Ctrl+):
        Sends a quit signal. Typically terminates the process and creates a core dump.
        ignore it while idle or allow child processes to handle it.

    SIGTSTP (Ctrl+Z):
        Suspends the foreground process.
        you might need to handle job control (advanced feature) or just ignore it for simplicity.

    SIGCHLD:
        Signals that a child process has terminated or changed state.
        use it to clean up zombie processes.

    Ctrl+D (EOF):
        Should gracefully terminate the process by checking EOF on input. */