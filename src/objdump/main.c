#include "objdump.h"

int		main(int ac, char **av)
{
  t_file		file;
  Elf64_Ehdr	*elf;
  Elf64_Shdr	*shtable;

  int i = 0;
  void	*tmp;

  if (ac == 2)
    {
      if (open_file(&file, av[1], O_RDONLY, 0) == -1)
        return (1);
      if (check_valid_elf(&file) == 1)
        return (1);
      elf = file.data;
      print_sh_name64(elf, &file);

      shtable = get_section_table64(elf, &file);
      while (i < elf->e_shnum)
        {
          tmp = file.data + shtable[i].sh_offset;
          dump_mem(tmp, shtable[i].sh_size, shtable[i].sh_addr);
          i++;
        }
      close_file(&file);
    }
  return (0);
}

