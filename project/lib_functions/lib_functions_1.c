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

/***********************************
*   3.1.3.1.1. ft_strdup           *
************************************
*/
/*
 * Description:
 *		The  ft_strdup() function is rewrite strdup()
 *		("returns a pointer to a new string which is 
 *		a duplicate of the string s.").
 * Return value:
 * 		The pointer to new string.
*/

char	*ft_strdup(const char *s1)
{
	char	*c_copy;
	int		len;

	len = ft_strlen(s1);
	c_copy = (char *)malloc((len + 1) * sizeof(char));
	if (c_copy == 0)
		return (NULL);
	c_copy[len] = '\0';
	while (len--)
		c_copy[len] = s1[len];
	return (c_copy);
}

/*******************************
*     3.3.1.1. ft_strchr_int   *
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

/*************************************
*     2.2.    ft_memset              *
**************************************
*/
/*
 * Description:
 *		ft_memset - fill memory with a constant byte.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	char	*bb;

	bb = b;
	while (len-- > 0)
		*bb++ = (unsigned char)c;
	return (b);
}

static char	*ft_charnbr(int n, int i, int flag)
{
	char	*s;

	s = calloc(++i, sizeof(char));
	if (!s)
		return (NULL);
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

/*************************************
*     6.5.2.4.1.  ft_itoa            *
**************************************
*/
/*
 * Description:
 *       Converts an integer n to a null-terminated 
 *       string and stores the result in the array 
 *       given by str parameter.
*/

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		c;
	int		flag;

	flag = 0;
	if (n == -2147483648)
	{
		flag = 1;
		n++;
	}
	i = 1;
	c = n;
	c /= 10;
	while (c)
	{
		i++;
		c /= 10;
	}
	if (n < 0)
		++i;
	s = ft_charnbr(n, --i, flag);
	return (s);
}
