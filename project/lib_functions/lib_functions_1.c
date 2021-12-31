/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_function_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../soLong/soLong.h"

/*******************************
*           ft_strchr_int      *
********************************
 * Description:
 *		The function finds char c in string s.
 * Return value:
 * 		Number of position c in s.
 * 		Length of s, if c not found.
*/

int	ft_strchr_int(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		++i;
	return (i);
}


void	*ft_memset(void *b, int c, size_t len)
{
	char	*bb;

	bb = b;
	while (len-- > 0)
		*bb++ = (unsigned char)c;
	return (b);
}

static char	*ft_charnbr(char *s, int n, int i, int flag)
{
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	if (n == 0)
		*s = '0';
	while (--i >= 0 && n != 0)
	{
		s[i] = n % 10 + '0';
		n /= 10;
	}
	if (flag)
		s[10] = '8';
	return (s);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		c;
	int		flag;

	flag = 0;
	i = 1;
	if (n == -2147483648)
	{
		flag = 1;
		n++;
	}
	c = n;
	while ((c /= 10))
		i++;
	n < 0 ? i++ : 0;
	if (!(s = (char *)malloc(sizeof(char) * ++i)))
		return (NULL);
	s[--i] = 0;
	s = ft_charnbr(s, n, i, flag);
	return (s);
}