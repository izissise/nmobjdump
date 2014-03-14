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
  Elf64_Shdr *tab;
  Elf64_Shdr *tmp;

  if ((open_file(&file, filename, O_RDONLY, 0) == -1)
      || check_valid_elf(&file) || init_elf(&elf, &file))
    return (1);
  elf.elf = file.data;
  sym = find_section(&elf, ".symtab", &file);
  if ((sym = (sym == -1) ? find_section(&elf, ".dynsym", &file) : sym) == -1)
    {
      dprintf(STDERR_FILENO, "%s: no symbols\n", filename);
      return (1);
    }
  tab = get_section_table64(elf.elf, &file);
  tmp = file.data + tab[sym].sh_offset;
  int i = 0;
  printf("%p\n", (void*)tmp->sh_link);
  printf("%d\n", tmp->sh_type);
  while (i < 20)
    {
      printf("%c", ((char*)(tmp->sh_link))[i]);
      i++;
    }
  return (close_file(&file));
}
