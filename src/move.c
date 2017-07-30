/*
** move.c for move file in /home/binary
** 
** Made by Laroche Achille
** Login   <binary@epitech.net>
** 
** Started on  Thu Jun  1 17:40:03 2017 Laroche Achille
** Last update Mon Jun  5 21:33:43 2017 Laroche Achille
*/

#include "nfs.h"

double		split_wheels(int axe)
{
  double	dir;

  if (axe == -1)
    return (axe);
  if (axe == 0 || axe == 7)
    dir = 0.2;
  else if (axe == 1 || axe == 6)
    dir = 0.13;
  else if (axe == 2 || axe == 5)
    dir = 0.08;
  else if (axe == 3 || axe == 4)
    dir = 0.05;
  if (axe >= 4)
    dir *= -1;
  return (dir);
}

void		mov_wheels()
{
  double	axe;
  double	dir;
  char		buf[15];
  char		*mov_str;

  if (buf == NULL || (dir = split_wheels(calc_direction())) == -1)
    return ;
  axe = g_scan[15];
  if (g_part[0] < g_part[7] * 0.1)
    axe = 200;
  else if (g_part[7] < g_part[0] * 0.1)
    axe = 200;
  if (axe <= 1000)
    dir *= (1 + (1 - (axe / 600)));
  else
    dir /= 2;
  fprintf(stderr, "<<%lf>>\n", dir);
  mov_str = stkstr(stkstr("WHEELS_DIR:", gcvt(dir, 10, buf)), "\n");
  putstr(mov_str, 1);
}

void		mov_front()
{
  char		buf[15];
  char		*spd_str;
  double	speed;

  speed = 0;
  if (g_scan[15] < 1000)
    speed = g_scan[15];
  else if (g_scan[20] < 1000)
    speed = g_scan[20];
  else if (g_scan[10] < 1000)
    speed = g_scan[10];
  if (speed == 0 || buf == NULL)
    {
      putstr("car_forward:0.8\n", 1);
      return ;
    }
  speed /= 1000;
  if (g_scan[15] < 200)
    speed = 0.1;
  spd_str = stkstr(stkstr("CAR_FORWARD:", gcvt(speed, 10, buf)), "\n");
  putstr(spd_str, 1);
}

void		check_wall()
{
  int		i;
  double	wheeldir;
  char		buf[10];
  char		*dir;
  int		count;

  count = 0;
  i = 0;
  while (i < 32)
    {
      if (g_scan[i] < 100)
	count++;
      i++;
    }
  if (count < 4 || buf == NULL)
    return ;
  wheeldir = atof(putstr(WHEEL, 1));
  dir = stkstr(stkstr("WHEELS_DIR:", gcvt((wheeldir * -1), 10, buf)), "\n");
  putstr(dir, 1);
  putstr("CAR_BACKWARDS:0.3\n", 1);
  sleep(4);
  putstr("CAR_FORWARD:0.05\n", 1);
}
