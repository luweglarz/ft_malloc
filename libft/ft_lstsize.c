#include "libft.h"

int ft_lstsize(t_list *list){
    int    i = 0;
    t_list *tmpList = list;

    while(tmpList){
        tmpList = tmpList->next;
        i++;
    }
    return (i);
}
