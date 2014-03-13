/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "nm.h"

int	main(int ac, char **av)
{
  int	i;

  i = 1;
  while (i < ac)
    {
      if (ac > 2)
        printf("\n%s:\n", av[i]);
      display_file(av[i]);
      i++;
    }
  if (i == 1)
    display_file("./a.out");
  return (0);
}
