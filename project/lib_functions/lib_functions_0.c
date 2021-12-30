/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_function_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../soLong/soLong.h"

/*****************************************
*           ft_map_list_new              *
******************************************
*/
/*
 * Description:
 *		The function adds new t_map_list. 
 *		In case malloc error run error_occurse with exit code 1.
 * Return value:
 * 		The pointer to new t_map_list.
 * Contains functions:
 *		1. error_occurse;
*/

t_map_list	*ft_map_list_new(t_mlx *all, char *line)
{
	t_map_list	*new_list;

	new_list = (t_map_list *)malloc(sizeof(t_map_list));
	if (!new_list)
		error_occurse(all, ERROR_MALLOC);
	new_list->line = line;
	line = NULL;
	new_list->next = NULL;
	return (new_list);
}

/*****************************************
*           ft_map_list_add_back         *
******************************************
*/
/*
 * Description:
 *		The function adds new t_map_list in back of elements list. 
 * Contains functions:
 *		1. ft_map_list_last;
*/

void	ft_map_list_add_back(t_map_list **lst, t_map_list *new)
{
	t_map_list	*last;

	if (lst && *lst)
	{
		last = ft_map_list_last(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

/*****************************************
*           ft_map_list_last             *
******************************************
*/
/*
 * Description:
 *		The function finds last element in list.
 * Return value:
 * 		Pointer to the last element of the list.
*/

t_map_list	*ft_map_list_last(t_map_list *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

/*****************************************
*           ft_map_list_clear            *
******************************************
*/
/*
 * Description:
 *		The function clear list.
*/

void	ft_map_list_clear(t_mlx *all, t_map_list **lst)
{
	t_map_list	*ptr;

	ptr = *lst;
	while (ptr)
	{
		ptr = (*lst)->next;
		ft_map_list_delone(all, *lst);
		*lst = ptr;
	}
	if (lst)
		lst = NULL;
}

/*****************************************
*           ft_map_list_delone           *
******************************************
*/
/*
 * Description:
 *		The function clear one element t_map_list.
*/

void	ft_map_list_delone(t_mlx *all, t_map_list *lst)
{
	free(lst->line);
	lst->line = NULL;
	all->line = NULL;
	free(lst);
}
