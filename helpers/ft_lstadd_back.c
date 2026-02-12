


#include "push_swap.h"

void ft_lstadd_back(Stack **lst, Stack *new_node)
{
    Stack *last;

    if (!lst || !new_node)
        return;

    if (!*lst)
    {
        *lst = new_node; // list was empty, new_node becomes head
        return;
    }

    last = ft_lstlast(*lst); // get last node
    last->next = new_node;   // append new_node at the end
    new_node->next = NULL;   // ensure new_node->next is NULL
}
    