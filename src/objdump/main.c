#include "objdump.h"

int	main(int ac, char **av)
{
  int	i;

  i = 1;
  while (i < ac)
    {
      display_file(av[i]);
      i++;
    }
  if (i == 1)
    display_file("./a.out");
  return (0);
}

