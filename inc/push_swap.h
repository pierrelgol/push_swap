/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:16:54 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/20 14:16:57 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/******************************************************************************/
/*                                                                            */
/*                                Dependencies                                */
/*                                                                            */
/******************************************************************************/

# include "plib.h"

/******************************************************************************/
/*                                                                            */
/*                                Type definition                             */
/*                                                                            */
/******************************************************************************/

typedef struct s_vec3
{
	int	a;
	int	b;
	int	c;
}		t_vec3;

typedef struct s_psw
{
	int	*sta;
	int	*stb;
	int	al;
	int	bl;
}		t_psw;

/******************************************************************************/
/*                                                                            */
/*                                Define / Macros                             */
/*                                                                            */
/******************************************************************************/

# define ASCEND 0
# define DESCEND 1
# define PRINT_COMMAND 0
# define DEBUG_COMMAND 1

/******************************************************************************/
/*                                                                            */
/*                                Push Swap Main                              */
/*                                                                            */
/******************************************************************************/

void	psw_start(char **inputs);

/******************************************************************************/
/*                                                                            */
/*                                Push Swap Parser                            */
/*                                                                            */
/******************************************************************************/
int		psw_parse(t_psw *stacks, char **inputs, int size);

/******************************************************************************/
/*                                                                            */
/*                                Push Swap Command A                         */
/*                                                                            */
/******************************************************************************/
void	psw_sa(t_psw *c, int print);
void	psw_pa(t_psw *c, int print);
void	psw_ra(t_psw *c, int print);
void	psw_rra(t_psw *stacks, int print);

/******************************************************************************/
/*                                                                            */
/*                                Push Swap Command B                         */
/*                                                                            */
/******************************************************************************/
void	psw_sb(t_psw *stacks, int print);
void	psw_pb(t_psw *stacks, int print);
void	psw_rb(t_psw *stacks, int print);
void	psw_rrb(t_psw *stacks, int print);

/******************************************************************************/
/*                                                                            */
/*                                Push Swap Command C                         */
/*                                                                            */
/******************************************************************************/

void	psw_ss(t_psw *stacks, int print);
void	psw_rr(t_psw *stacks, int print);
void	psw_rrr(t_psw *stacks, int print);

/******************************************************************************/
/*                                                                            */
/*                                Push Swap Sort                              */
/*                                                                            */
/******************************************************************************/
int		psw_sort(t_psw *stacks, int size);
int		psw_is_stack_sorted(int *stack, int size, int order);
int		psw_sort2(t_psw *c, int is_b);
void	psw_sort3(t_psw *c);
void	psw_median_sort(int *tmp_stack, int size);

/******************************************************************************/
/*                                                                            */
/*                                Push Swap Quick Sort                        */
/*                                                                            */
/******************************************************************************/

int		psw_qsort_a(t_psw *stacks, int low, int high);
int		psw_qsort_b(t_psw *stacks, int high, int low);
int		psw_sort_small_a(t_psw *stacks, int length);
int		psw_sort_small_b(t_psw *stacks, int length);
int		psw_sort_push(t_psw *stacks, int length, int operation_code);
int		psw_find_median(int *pivot, int *stack, int size);

/******************************************************************************/
/*                                                                            */
/*                                Push Swap Utils1                            */
/*                                                                            */
/******************************************************************************/

void	psw_swap(int *a, int *b);
t_vec3	psw_top_to_vec3(int *stack);
int		psw_top_is_sorted(int *stack);

#endif
