/*
** scan.c for scanner file in /home/binary
** 
** Made by Laroche Achille
** Login   <binary@epitech.net>
** 
** Started on  Thu Jun  1 17:40:14 2017 Laroche Achille
** Last update Mon Jun  5 21:47:45 2017 Laroche Achille
*/

#include "nfs.h"

void		scan_front(char *str)
{
  int		i;
  char		**pre;

  i = 0;
  if ((pre = wordtab(str, ':')) != NULL)
    while (i < 32)
      {
	if (pre[i] != NULL)
	  g_scan[i] = atof(pre[i]);
	else
	  g_scan[i] = 0;
	i++;
      }
  free(pre);
  free(str);
}

void	radar_viewer()
{
  double max = 0;
  int i = 0;
  int nb = 0;
  int nbb = 0;

  while (i < 32)
    {
      if (g_scan[i] > max)
	max = g_scan[i];
      i++;
    }
  i = 0;
  while (i < 32)
    {
      nb = g_scan[i] / max * 50;
      nbb = 50 - nb;
      fprintf(stderr, "%d::", i);
      if (nb == 50) fprintf(stderr, "%lf::", g_scan[i]);
      while (nb-- > 0)
	putstr("_", 2);
      while (nbb-- > 0)
	putstr("#", 2);
      putstr("\n", 2);
      i++;
    }
}

int		greater_pos(int *arr, int size, int max)
{
  int		i;
  int		tmp;

  i = 0;
  tmp = 0;
  while (i < size)
    {
      fprintf(stderr, "%d:%d\n", i, arr[i]);
      if (arr[i] > tmp && arr[i] != max)
	tmp = arr[i];
      i++;
    }
  i = 0;
  while (arr[i] != tmp)
    i++;
  fprintf(stderr, "%d", i);
  return (i);
}

int		calc_direction()
{
  int		i;
  int		nb;

  i = 0;
  while (i < 8)
    g_part[i++] = 0;
  i = 0;
  nb = 0;
  while (i < 32)
    {
      g_part[nb] += g_scan[i];
      i++;
      if ((i % 4) == 0)
	nb++;
    }
  nb = 0;
  i = 0;
  if (g_scan[15] > 1000 && g_part[0] > 300 && g_part[7] > 300)
    while (i < 8)
      {
	if (g_part[i] > nb)
	  nb = g_part[i];
	i++;
      }
  return (greater_pos(g_part, 8, nb));
}
