/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:35:42 by franzu            #+#    #+#             */
/*   Updated: 2021/01/06 15:35:46 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int				ft_atoi(const char *str);
int				ft_isdigit(int c);
char			*ft_itoa(long n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar_fd(char c, int fd);
char			*ft_itoa_base(long nbr, char *base);
char			*ft_itoa_base_ull(unsigned long long nbr, char *base);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif
