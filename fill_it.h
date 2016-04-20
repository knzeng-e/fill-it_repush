/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 21:40:40 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/17 17:55:34 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_IT_H
# define FILL_IT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# define NB_CARAC_IN_PIECE 20
# define GET_PIECE(x, t) read(x, t, NB_CARAC_IN_PIECE)
# define READ_NL(x, t) read(x, t, 1)
# define MAX_PIECES 26
# define UNABLE_TO_OPEN -1
# define ERROR_ALLOCATION -2
# define INVALID_NB_TETRIMINOS 0
# define INVALID_DESCRIPTION 0
# define NO 0
# define YES 1
# define VALID_DESCRIPTION 1
# define INVALID_DISPLAY -3
# define VALID_DISPLAY 2
# define INSERT_SUCCESS 3
# define ERROR_MALLOC -4
# define ERROR_INIT_MAP -5
# define INIT_SUCCESS 5
# define GAME_OVER 4

typedef enum		e_type_piece
{
	SQUARE,
	HORIZONTAL,
	VERTICAL,
	L_VERTIC_HAUT_GAUCHE,
	L_VERTIC_BAS_DROIT,
	L_VERTIC_BAS_GAUCHE,
	L_VERTIC_HAUT_DROIT,
	L_HORIZONTAL_BAS_DROIT,
	L_HORIZONTAL_BAS_GAUCHE,
	L_HORIZONTAL_HAUT_DROIT,
	L_HORIZONTAL_HAUT_GAUCHE,
	Z_HORIZONTAL_RIGHT,
	Z_HORIZONTAL_LEFT,
	Z_VERTICAL_LEFT,
	Z_VERTICAL_RIGHT,
	T_UP,
	T_RIGHT,
	T_DOWN,
	T_LEFT,
	END
}					t_forme;

typedef struct		s_tetro
{
	int				line;
	int				column;
}					t_tetro;

typedef struct		s_piece
{
	t_tetro			tetro[4];
	int				x;
	int				y;
	t_forme			forme;
	int				is_inserted;
}					t_piece;

typedef struct		s_map
{
	int				size;
	int				begin_line;
	int				begin_column;
	int				nb_pieces;
	int				clear;
	char			**tab;
	char			*c;
}					t_map;

typedef struct		s_params
{
	int				lus;
	int				line_at_end;
	int				cpt;
	int				i;
	int				j;
	int				ret;
	int				nb;
}					t_params;

int					ft_check_file(char *file, t_piece *piece);
int					ft_verif_piece(char *piece, t_piece *display);
int					ft_check_display(t_tetro *tetro, t_piece *piece);
int					ft_check_line_and_square(t_tetro *tetro, t_piece *piece);
int					ft_check_l_piece(t_tetro *tetro, t_piece *piece);
int					ft_check_l_piece2(t_tetro *tetro, t_piece *piece);
int					ft_check_t_piece(t_tetro *tetro, t_piece *piece);
int					ft_check_z_piece(t_tetro *tetro, t_piece *piece);
int					ft_insert_square(t_map *map, int line, int col);
int					ft_insert_vertic_line(t_map *map, int line, int col);
int					ft_insert_horiz_line(t_map *map, int line, int col);
int					ft_insert_lvertic_up_left(t_map *map, int line, int col);
int					ft_insert_lvertic_down_left(t_map *map, int line, int col);
int					ft_insert_lvertic_down_right(t_map *map, int line, int col);
int					ft_insert_lvertic_up_right(t_map *map, int line, int col);
int					ft_insert_lhoriz_down_right(t_map *map, int line, int col);
int					ft_insert_lhoriz_down_left(t_map *map, int line, int col);
int					ft_insert_lhoriz_up_right(t_map *map, int line, int col);
int					ft_insert_lhoriz_up_left(t_map *map, int line, int col);
int					ft_insert_zhoriz_right(t_map *map, int line, int col);
int					ft_insert_zhoriz_left(t_map *map, int line, int col);
int					ft_insert_zvertic_left(t_map *map, int line, int col);
int					ft_insert_zvertic_right(t_map *map, int line, int col);
int					ft_insert_t_up(t_map *map, int line, int col);
int					ft_insert_t_right(t_map *map, int line, int col);
int					ft_insert_t_down(t_map *map, int line, int col);
int					ft_insert_t_left(t_map *map, int line, int col);
int					ft_clear_square(t_map *map, int line, int col);
int					ft_clear_vertic_line(t_map *map, int line, int col);
int					ft_clear_horiz_line(t_map *map, int line, int col);
int					ft_clear_lvertic_up_left(t_map *map, int line, int col);
int					ft_clear_lvertic_down_left(t_map *map, int line, int col);
int					ft_clear_lvertic_down_right(t_map *map, int line, int col);
int					ft_clear_lvertic_up_right(t_map *map, int line, int col);
int					ft_clear_lhoriz_down_right(t_map *map, int line, int col);
int					ft_clear_lhoriz_down_left(t_map *map, int line, int col);
int					ft_clear_lhoriz_up_right(t_map *map, int line, int col);
int					ft_clear_lhoriz_up_left(t_map *map, int line, int col);
int					ft_clear_zhoriz_right(t_map *map, int line, int col);
int					ft_clear_zhoriz_left(t_map *map, int line, int col);
int					ft_clear_zvertic_left(t_map *map, int line, int col);
int					ft_clear_zvertic_right(t_map *map, int line, int col);
int					ft_clear_t_up(t_map *map, int line, int col);
int					ft_clear_t_right(t_map *map, int line, int col);
int					ft_clear_t_down(t_map *map, int line, int col);
int					ft_clear_t_left(t_map *map, int line, int col);
int					ft_init(t_map *map, int size_map, char c, int begin_line, \
		int begin_column);
int					ft_put_in_map(int line, int column, t_piece *piece, \
		t_map *map);
int					ft_init_map(t_map *map, int size_map, char c, int
		nb_pieces);
int					insert(t_piece *piece, t_map *map, int *current_pos);
size_t				ft_strlen(const char *s);
t_map				*ft_resize_map(t_map *old);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);
void				ft_print_map(t_map *map);
void				ft_resolve(t_piece *pieces, t_map *map, int nb_pieces);
void				ft_set_insertfunctions(int (*f[19])(t_map *, int, int));
void				ft_set_clearfunctions(int (*f[19])(t_map *, int, int), \
		t_map *map);

#endif
