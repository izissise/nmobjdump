#include "general.h"

int		main(int ac, char **av)
{
  t_file		file;
  Elf64_Ehdr	*elf;

  if (ac == 2)
    {
      if (open_file(&file, av[1], O_RDONLY, 0) == -1)
        return (1);
      if (check_valid_elf(&file) == 1)
        return (1);
      elf = file.data;
      print_sh_name(elf, &file);
      close_file(&file);
    }
  return (0);
}
