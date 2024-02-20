/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:17:00 by wzeraig           #+#    #+#             */
/*   Updated: 2024/02/16 09:42:35 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define true 1
# define false 0
# define Wall '1'
# define ERROR 1
# define Exit 'E'
# define Collectable 'C'
# define Personnage 'P'
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define GREEN "\033[1;32m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define PINK "\033[38;5;206m"
# define PEACH "\033[38;5;217m"
# define IMG_SIZE 32
# define ERRBER "Extension ou fichier incorrect."
# define ERRWALL "L'encadrement de la map doit être constitue de mur seulement."
# define ERRREC "La map n'est pas rectangulaire."
# define ERRWIN "Aucun chemin ne mène à Rome."
# define ERRNUMBER "1 position start 1 sortie et au moins un collectible."
# define ERRFALSE "Élément inattendu dans la map>"
# define ERRIMG "Initialisation de l'image."
# define ERRFD "Ouverture du FD"
# define ERRDIR "Ce n'est pas un fichier"
# define ERRPLAY "La map n'est pas jouable"
#define	WIN game->win
#define MLX game->mlx
#define	IMGCOIN game->img->coin
#define	IMGWALL game->img->wall
#define	IMGGROUND game->img->ground
#define	IMGPLAYER game->img->player
#define	IMGEXIT game->img->exit
#define IMGxJ j * IMG_SIZE
#define IMGxI i * IMG_SIZE
#define nbrcoin game->map->collectables

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct map
{
	int collectables; // nombre de collectables
	int collected;    // nombre de collectables collecter
	int		exit;
	size_t	lenline;
	char	*mapline;
	int		count;
	char	*line;
	int		countline;
	int		index;
	char	**map;

}			t_map;

typedef struct s_img
{
	void *mlx_img; // ca je sais pas pk
	int width;     // epaisseur de limage 32
	int height;    // taille de limage 32
	void	*wall;
	void	*exit;
	void	*ground;
	void	*player;
	int line_length; // en gros la largeur de limage
	void	*coin;

}			t_img;

typedef struct s_data
{
	void	*mlx;
	void *win; // window pas win game
	int		win_height;
	int		win_width;
	int		step_count;
	int		player_i;
	int		player_j;
	int		exit_i;
	int		exit_j;

	t_map	*map;
	t_img	*img;
}			t_data;

char		*get_next_line(int fd);
char		*ft_strchr(const char *s, int c);
int			search(char *str, char c, int len);
int			doublon(char *str, char c);
int			ft_printf(const char *f, ...);
int			pos_p(char *str);
int			extension(char *path, t_map *map);
int			search2(char *str);
int			checkmap(int fd, t_map *map);
char		*strjoinfree(char const *s1, char const *s2);
void		init_struct(t_data *game);
void		init_game(t_data *game);
void		error_msg(char *str, t_map *map);
int			checkelement(t_data *game);
int			move(t_map *map, char *str, size_t i);
int			init_window(t_data *game);
int			handle_input(int keysym, t_data *game);
int			affichage(t_data *game);
int			openfd(char *path, t_data *game);
int			count(char *str, char c);
int			parse_image(t_data *game);
int			check_next_tile(t_data *game, int keysym, char tile);
void		modulatemap(t_data *game);
int			lclose(t_data *game);
int			loop_images(t_data *game);
void		ft_putstr_fd(char *s, int fd);
int			pos_index(t_data *game);
int			pos_player(t_data *game);
int			init_images(t_data *game);
void		destroy_images(t_data *game);
void		movement(t_data *game, int keysym);
int			checkcollect(t_data *game, int keysym, char tile);
int			pos_exit(t_data *game);
void		ft_free(char **strs);
int			win_game(t_data *game);

#endif

// supprimer les prototypes qui sont deja fait dans la libft capter le bail u know what im saying