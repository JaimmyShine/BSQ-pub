/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcayuela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:46:37 by jcayuela          #+#    #+#             */
/*   Updated: 2026/07/26 16:57:58 by jcayuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_puterr(char *str);

int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);

char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strdup(char	*src);
char	**ft_split(char *str, char *charset);

#endif
