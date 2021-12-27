#include "../soLong/soLong.h"

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

t_map_list	*ft_map_list_last(t_map_list *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

t_map_list	*ft_map_list_new(char *line)
{
	t_map_list	*new_list;

	if (!(new_list = (t_map_list*)malloc(sizeof(t_map_list))))
		return (NULL);
	new_list->line = line;
    // line = NULL;
	new_list->next = NULL;
	return (new_list);
}

void	ft_map_list_clear(t_map_list **lst, void (*del)(t_map_list*))
{
	t_map_list	*ptr;

	ptr = *lst;
	while (ptr)
	{
		ptr = (*lst)->next;
        del(*lst);
		*lst = ptr;
	}
	if (lst)
		lst = NULL;
}

void	ft_map_list_delone(t_map_list *lst)
{
    free(lst->line);
    lst->line = NULL;
    free(lst);
}

// char		*ft_strdup(const char *s1)
// {
// 	char	*c_copy;
// 	int		len;

// 	len = ft_strlen(s1);
// 	if ((c_copy = malloc((len + 1) * sizeof(char))) == 0)
// 		return (NULL);
// 	c_copy[len] = 0;
// 	while (len--)
// 	{
// 		c_copy[len] = s1[len];
// 	}
// 	return (c_copy);
// }