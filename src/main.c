/*
** main.c for core file for ia in /home/binary/All/Need4stek/src
** 
** Made by Laroche Achille
** Login   <binary@epitech.net>
** 
** Started on  Thu May 11 17:11:36 2017 Laroche Achille
** Last update Sun Jun  4 21:50:56 2017 Choppy Thibaut
*/

#include "nfs.h"

int		ia_mazing()
{
  scan_front(putstr(LIDAR, 1));
  mov_front();
  mov_wheels();
  check_wall();
  radar_viewer();
  return (1);
}

int		main()
{
  if (!(g_scan = malloc(sizeof(double) * 32)) ||
      !(g_part = malloc(sizeof(int) * 9)))
    return (84);
  putstr(START, 1);
  while (ia_mazing());
  putstr(STOP, 1);
  free(g_scan);
  free(g_part);
  return (0);
}
