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

char		*symbol_section_name(t_elf *elf)
{
  char		*names[ET_NUM];
  Elf32_Ehdr	*tmpelf;

  tmpelf = (Elf32_Ehdr*)elf->elf;
  names[ET_NONE] = NULL;
  names[ET_REL] = ".symtab";
  names[ET_EXEC] = ".dynsym";
  names[ET_DYN] = ".dynsym";
  names[ET_CORE] = NULL;
  if (tmpelf->e_type < ET_NUM)
    return (names[tmpelf->e_type]);
  return (NULL);
}

int	display_file(const char *filename)
{
  t_file	file;
  t_elf	elf;
  int	sym;

  if ((open_file(&file, filename, O_RDONLY, 0) == -1)
      || check_valid_elf(&file) || init_elf(&elf, &file))
    return (1);
  elf.elf = file.data;
  if ((sym = find_section(&elf, symbol_section_name(&elf), &file)) == -1
      || elf.sh_size(elf.elf, sym, &file) == 0)
    {
      dprintf(STDERR_FILENO, "%s: no symbols\n", filename);
      return (1);
    }

  return (close_file(&file));
}
