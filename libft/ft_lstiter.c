#include "libft.h"

void    ft_lstiter(t_list *list, void (*f)(void*)){
    t_list *tmpList;

    tmpList = list;
    while(tmpList){
        (*f)(tmpList->content);
        tmpList = tmpList->next;
    }
}