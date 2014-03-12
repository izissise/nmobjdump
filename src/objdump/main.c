#include "objdump.h"

int		main(int ac, char **av)
{
  t_file		file;
  t_elf		elf;
  size_t		section_number;
  char		*name;
  unsigned int	i;

  i = 1;
  if (ac == 2)
    {
      if (open_file(&file, av[1], O_RDONLY, 0) == -1)
        return (1);
      if (check_valid_elf(&file) || init_elf(&elf, &file))
        return (1);
      elf.elf = file.data;
      section_number = elf.section_number(elf.elf);
      while (i < section_number)
        {
          name = elf.sh_section_name(elf.elf, i, &file);
          if (!(!strcmp(name, ".bss") || !strcmp(name, ".shstrtab")
                || !strcmp(name, ".symtab") || !strcmp(name, ".strtab")))
            display_section(&elf, &file, i);
          i++;
        }
      close_file(&file);
    }
  return (0);
}

