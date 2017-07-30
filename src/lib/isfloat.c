/*
** stkstr.c for concatenate strings in /home/binary/All/Need4stek/src/lib
** 
** Made by Laroche Achille
** Login   <binary@epitech.net>
** 
** Started on  Thu May 11 21:23:31 2017 Laroche Achille
** Last update Sun May 21 16:48:40 2017 Laroche Achille
*/

#include "nfs.h"

double	isfloat(char *str)
{
  int	i;

  i = 0;
  if (!str)
    return (-1);
  while (str[i])
    {
      if (str[i] == ':')
	break;
      if ((str[i] < '0' && str[i] != '.') || str[i] > '9')
	return (-1);
      i++;
    }
  return (atof(str));
}
