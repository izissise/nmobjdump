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
  char	*symstr;

  if ((open_file(&file, filename, O_RDONLY, 0) == -1)
      || check_valid_elf(&file) || init_elf(&elf, &file))
    return (1);
  elf.elf = file.data;
  sym = 0;
  j = 0;
  while ((sym = find_section(&elf, ".symtab", sym + 1, &file)) != -1)
    {
      symstr = elf.symbols_str(elf.elf, sym, &file);

      j++;
    }
  if (j == 0)
    {
      dprintf(STDERR_FILENO, "%s: no symbols\n", filename);
      return (1);
    }
  return (close_file(&file));
}
