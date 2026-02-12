
#include "push_swap.h"
void error_exit(Stack **a)
{
    free_stack(a);
    write(2, "Error\n", 6);
    exit(1);
}
