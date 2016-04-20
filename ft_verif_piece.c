/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 01:47:30 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/17 16:59:48 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int	ft_verif_piece(char *piece, t_piece *display)
{
	struct s_params	params;

	params.i = 0;
	params.nb = 0;
	while (params.i < 20)
	{
		params.j = -1;
		while (++params.j < 4)
		{
			if (piece[params.i] != '#' && piece[params.i] != '.')
				return (INVALID_DESCRIPTION);
			if (piece[params.i] == '#')
			{
				if (params.nb == 4)
					return (INVALID_NB_TETRIMINOS);
				display->tetro[params.nb].line = (params.i / 5);
				display->tetro[params.nb++].column = params.j;
			}
			params.i++;
		}
		if (piece[params.i++] != '\n')
			return (INVALID_DESCRIPTION);
	}
	return ((params.nb == 4) \
			&& (ft_check_display(display->tetro, display) > 0));
}
