#include "libft.h"

void    ft_lstclear(t_list **list, void(*del)(void*)){
    t_list *tmpList ;

    if (list && del){
        while(*list){
            tmpList = (*list)->next;
            (*del)((*list)->content);
            free(*list);
            *list = tmpList;
        }
    }
}
