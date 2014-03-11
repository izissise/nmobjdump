#include "general.h"

int	main(int ac, char **av)
{
  t_file	file;

  if (ac == 2)
    {
      if (open_file(&file, av[1], O_RDONLY, 0) == -1)
        return (1);
      write(1, file.data, file.size);
      close_file(&file);
    }
  return (0);
}
