/*
** str_to_wordtab.c for string to wordtab in /home/binary/CPE_2016_stumper3/src/str_to_wordtab
** 
** Made by Laroche Achille
** Login   <binary@epitech.net>
** 
** Started on  Thu May  4 16:07:16 2017 Laroche Achille
** Last update Thu May 11 18:05:09 2017 Laroche Achille
*/

#include "nfs.h"

char	*grabstr(char *str, int seplvl, int i, char c)
{
  int	y;

  y = 0;
  char	*new;

  while (i < seplvl)
    {
      if (str[y] == c)
	i++;
      y++;
    }
  i = 0;
  while (str[i] != c)
    i++;
  new = malloc(sizeof(char) * (i + 1));
  i = 0;
  while (str[y] != c && str[y])
    {
      new[i] = str[y];
      i++;
      y++;
    }
  new[i] = 0;
  return (new);
}

char	**wordtab(char *str, char c)
{
  int	i;
  int	y;
  char	**new;

  i = 1;
  y = 0;
  if (!str)
    return (NULL);
  while (str[y])
    {
      if (str[y] == c)
	i++;
      y++;
    }
  if ((new = malloc(sizeof(char*) * (i + 1))) == NULL)
    return (NULL);
  y = 0;
  while (y < i)
    {
      new[y] = grabstr(str, y, 0, c);
      y++;
    }
  new[y] = NULL;
  return (new);
}
