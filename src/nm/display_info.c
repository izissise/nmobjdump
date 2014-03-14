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

int	display_file(const char *filename)
{
  t_file	file;
  t_elf	elf;
  int	sym;
  int	j;
  Elf64_Shdr *tab;
  Elf64_Sym *tmp;

  if ((open_file(&file, filename, O_RDONLY, 0) == -1)
      || check_valid_elf(&file) || init_elf(&elf, &file))
    return (1);
  int i = 0;
  elf.elf = file.data;
  tab = get_section_table64(elf.elf, &file);
  sym = 0;
  j = 0;
  void *ptr;
  while ((sym = find_section_type(&elf, SHT_SYMTAB, sym + 1, &file)) != -1)
    {
i = 0;
      tmp = file.data + tab[sym].sh_offset;
      printf("%p\n", (void*)tab[sym].sh_link);
      ptr = file.data + tab[sym].sh_link;
      while (i < 20)
        {
          printf("%c", ((char*)(ptr))[i]);
          i++;
        }

      j++;
    }
  if (j == 0)
    {
      dprintf(STDERR_FILENO, "%s: no symbols\n", filename);
      return (1);
    }
  return (close_file(&file));
}
