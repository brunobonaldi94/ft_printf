/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_linked_list_bonus.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 02:15:33 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/05/25 21:57:40 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_LINKED_LIST_BONUS_H
# define FORMAT_LINKED_LIST_BONUS_H

void			add_node_back(t_format_opt **head,
					t_format_opt *new_node);
t_format_opt	*create_node(void);
void			clear_list(t_format_opt **format_opt);

#endif // FORMAT_LINKED_LIST_BONUS_H