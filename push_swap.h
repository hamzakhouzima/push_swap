/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:45:39 by hkhouzim          #+#    #+#             */
/*   Updated: 2026/02/11 18:59:45 by hkhouzim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	long long			value;
	int	index;
	struct s_node	*next;
}	Stack;

//parsing functions 
long long		ft_atoll(const char *str);
int		ft_isdigit(int c);
char	**ft_split(char *s, int c);
int	parse_simple(Stack **a, char **argv);
int     parse_multiple(Stack **a, char **argv, int argc);

//int     *parse_input(char *input)
int	valid_input_string(char *s);
int	count_elements(char *input);
long long	*stack_to_array(Stack *stk);

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(char *s1, int c);
//char    *ft_strdup(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int      valid_input_argv(char **argv);
Stack	*ft_lstnew(long value);
void	ft_lstadd_front(Stack **stack, Stack *new);
Stack	*ft_lstlast(Stack *stack);
int		ft_lstsize(Stack *stack);

void	build_stack(Stack **a, char **numbers);
void	index_stack(Stack *a);
void	init_state(/* your struct if you have one */);

void	swap(Stack **stack);
void	push(Stack **from, Stack **to);
void	rotate(Stack **stack);
void	reverse_rotate(Stack **stack);

void	ra(Stack **a);
void	rb(Stack **b);
void	rr(Stack **a, Stack **b);

void	rra(Stack **a);
void	rrb(Stack **b);
void	rrr(Stack **a, Stack **b);

void	pa(Stack **a, Stack **b);
void	pb(Stack **a, Stack **b);

void	sa(Stack **a);
void	sb(Stack **b);
void	ss(Stack **a, Stack **b);

int		calculate_cost(Stack *a, Stack *b, int index);
Stack	*find_target(Stack *a, int value);

int		find_position(Stack *stack, int index);
void	small_sort(Stack **a);
void	chunk_sort(Stack **a, Stack **b);
void	rebuild(Stack **a, Stack **b);

void	ft_putstr(char *str);
void	free_stack(Stack **stack);
Stack   *create_stack(long size);

#endif
