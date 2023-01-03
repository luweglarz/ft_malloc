#include "libft.h"

t_list      *ft_lstnew(void *content){
    t_list *newElem;

    if (!(newElem = ft_calloc(1, sizeof(t_list))))
        return NULL;
    newElem->content = content;
    newElem->next = NULL;
    return newElem;
}