/*
** putstr.c for putstr in /home/binary/All/Need4stek/src/lib
** 
** Made by Laroche Achille
** Login   <binary@epitech.net>
** 
** Started on  Thu May 11 18:40:20 2017 Laroche Achille
** Last update Thu Jun  1 17:22:25 2017 Laroche Achille
*/

#include "nfs.h"

char	*get_data(char *ans, int i, int min, int max)
{
  int	tmp;
  char	*new;

  while (max != 3)
    if (ans[min++] == ':')
      max++;
  max = strlen(ans);
  while (ans[--max] != ':');
  tmp = strlen(ans) - min - (strlen(ans) - max);
  if (!(new = malloc(tmp + 1)))
    return (NULL);
  while (i + min < max)
    {
      new[i] = ans[i + min];
      i++;
    }
  new[i] = 0;
  if (new[0] == 'T')
    {
      putstr(new, 2);
      exit(EXIT_SUCCESS);
    }
  free(ans);
  return (new);
}

int	strnchar(char *str, char c)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    {
      if (str[i] == c)
	count++;
      i++;
    }
  return (count);
}

char	*putstr(char *str, int fd)
{
  if (str != NULL)
    write(fd, str, strlen(str));
  if (fd != 1)
    return (NULL);
  str = get_line(0);
  if (strnchar(str, ':') <= 3)
    return (NULL);
  str = get_data(str, 0, 0, 0);
  return (str);
}
