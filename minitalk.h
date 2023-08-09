/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:58:18 by alvina            #+#    #+#             */
/*   Updated: 2023/02/12 18:33:54 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int		ft_atoi(const char *nptr);
void    fonction(int signum);
char	*binaire(char c);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int	ft_strlen(char *str);
int	ft_recursive_power(int nb, int power);
char	*ft_strjoin(char *s1, char c);
int	print_char(char octet[9]);
void	ft_putnbr(int n);
void	char_receiver(int signum, siginfo_t *client, void *context);
char	*ft_strnstr(const char *big, const char *little, size_t len);

void	char_sender(char c, int pid);
void	test(int signum, siginfo_t *client, void *context);

#endif