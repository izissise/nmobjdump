#include "objdump.h"

int		main(int ac, char **av)
{
  t_file		file;
  t_elf		elf;
  size_t		section_number;

  unsigned int i = 0;
  void	*tmp;

  if (ac == 2)
    {
      if (open_file(&file, av[1], O_RDONLY, 0) == -1)
        return (1);
      if (check_valid_elf(&file) || init_elf(&elf, &file))
        return (1);
      elf.elf = file.data;
      print_sh_name64(elf.elf, &file);

      section_number = elf.section_number(elf.elf);
      while (i < section_number)
        {
          tmp = file.data + elf.sh_offset(elf.elf, i, &file);
          printf("Contents of section %s:\n",
                 elf.sh_section_name(elf.elf, i, &file));
          if (tmp + elf.sh_size(elf.elf, i, &file) <= file.data + file.size)
            dump_mem(tmp, elf.sh_size(elf.elf, i, &file),
                     elf.sh_addr(elf.elf, i, &file));
          i++;
        }
      close_file(&file);
    }
  return (0);
}

