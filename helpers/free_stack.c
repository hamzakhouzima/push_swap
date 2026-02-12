#include "push_swap.h"

void free_stack(Stack **stk)
{
    Stack *tmp;
    Stack *next;

    if (!stk || !*stk)
        return ;

    tmp = *stk;
    while (tmp)
    {
        next = tmp->next; // save next before freeing
        free(tmp);
        tmp = next;
    }
    *stk = NULL; // avoid dangling pointer
}
