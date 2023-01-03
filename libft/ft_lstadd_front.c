#include "libft.h"

void    ft_lstadd_front(t_list **list, t_list *new){
    new->next = *list;
    *list = new;
}
