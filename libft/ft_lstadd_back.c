#include "libft.h"

void ft_lstadd_back(t_list **list, t_list *newElem){
    t_list *tmpList = *list;

    if (!*list)
        *list = newElem;
    else{
        while(tmpList->next)
            tmpList = tmpList->next;
        tmpList->next = newElem;
    }
}
