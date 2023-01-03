#include "libft.h"

void    ft_lstdone(t_list *list, void (*del)(void*)){
    if(list){
        if (del && list->content)
            del(list->content);
        free(list);
    }
}
