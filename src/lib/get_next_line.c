/*
** gnl.c for very simple getnextline in /home/binary/All/Need4stek/src
** 
** Made by Laroche Achille
** Login   <binary@epitech.net>
** 
** Started on  Thu May 11 17:15:16 2017 Laroche Achille
** Last update Thu May 11 18:01:25 2017 Laroche Achille
*/

#include "nfs.h"

char	*reall_add(char *str, char c)
{
  char	*new;
  int	i;

  i = strlen(str);
  if ((new = malloc(sizeof(char) * (i + 2))) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      new[i] = str[i];
      i++;
    }
  new[i++] = c;
  new[i] = '\0';
  free(str);
  return (new);
}

char	*get_line(const int fd)
{
  char	*str;
  char	c;

  str = strdup("");
  c = 0;
  while (read(fd, &c, 1) > 0 && c != '\n')
    if ((str = reall_add(str, c)) == NULL)
      return (NULL);
  if (strcmp(str, "") == 0 && c == 0)
    return (NULL);
  return (str);
}
