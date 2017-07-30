/*
** nfs.h for include file in /home/binary/All/Need4stek/include
** 
** Made by Laroche Achille
** Login   <binary@epitech.net>
** 
** Started on  Thu May 11 16:48:17 2017 Laroche Achille
** Last update Thu Jun  1 17:45:39 2017 Laroche Achille
*/

#ifndef NFS_H_
# define NFS_H_

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# define START	"START_SIMULATION\n"
# define STOP	"STOP_SIMULATION\n"
# define LIDAR	"GET_INFO_LIDAR\n"
# define INFO	"GET_INFO_SIMTIME\n"
# define WHEEL	"GET_CURRENT_WHEELS\n"
# define SPEED	"GET_CURRENT_SPEED\n"

double	*g_scan;
int	*g_part;

int	main();
int	ia_mazing();
void	mov_wheels();
int	calc_direction();
void	radar_viewer();
void	scan_front(char *);
void	mov_front();
void	check_wall();

char	**wordtab(char *, char);
char	*stkstr(char *, char *);
char	*grabstr(char *, int, int, char);
char	*get_line(const int);
char	*reall_add(char *, char);
double	isfloat(char *);
char	*putstr(char *, int);

#endif /* !NFS_H_ */
