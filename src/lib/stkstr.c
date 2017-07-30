/*
** stkstr.c for concatenate strings in /home/binary/All/Need4stek/src/lib
** 
** Made by Laroche Achille
** Login   <binary@epitech.net>
** 
** Started on  Thu May 11 21:23:31 2017 Laroche Achille
** Last update Sun May 21 15:38:40 2017 Laroche Achille
*/

#include "nfs.h"

char	*stkstr(char *sta, char *stb)
{
  int		i;
  char		*new;

  if (!sta || !stb)
    return (NULL);
  if (!(new = malloc(sizeof(char) * (strlen(sta) + strlen(stb) + 1))))
    return (NULL);
  i = 0;
  while (sta[i])
    {
      new[i] = sta[i];
      i++;
    }
  while (stb[i - strlen(sta)])
    {
      new[i] = stb[i - strlen(sta)];
      i++;
    }
  new[i] = 0;
  return (new);
}
