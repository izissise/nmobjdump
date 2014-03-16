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

void		**list_symbols(t_elf *elf, int sh, t_file *file)
{
  void		**res;
  void		*sect;
  size_t	size;
  int		symsize;
  int		i;

  sect = file->data + elf->sh_offset(elf->elf, sh, file);
  size = elf->sh_size(elf->elf, sh, file);
  if ((sect == file->data) || (size == 0))
    return (NULL);
  i = 0;
  symsize = (elf->type == ELFCLASS32) ? sizeof(Elf32_Sym) : sizeof(Elf64_Sym);
  if ((res = malloc(((size / symsize) + 1) * sizeof(void*))) == NULL)
    return (NULL);
  while ((size_t)(symsize * i) < size)
    {
      res[i] = sect + (symsize * i);
      i++;
    }
  res[i] = NULL;
  return (res);
}

void	dump_section_symbol(t_elf *elf, int sh, char *symstr, t_file *file)
{
  void	**symbols;
  int	i;

  i = 0;
  if ((symbols = list_symbols(elf, sh, file)) == NULL)
    return ;
  sort_symbol(elf, symbols, symstr, file);
  while (symbols[i])
    {
      elf->dump_symbol(symbols[i], symstr, file);
      i++;
    }
  free(symbols);
}

int		display_file(const char *filename)
{
  t_file	file;
  t_elf		elf;
  int		sym;
  int		j;
  char		*symstr;

  if ((open_file(&file, filename, O_RDONLY, 0) == -1)
      || check_valid_elf(&file) || init_elf(&elf, &file))
    return (1);
  elf.elf = file.data;
  sym = 0;
  j = 0;
  while ((sym = find_section(&elf, ".symtab", sym + 1, &file)) != -1)
    {
      if ((symstr = elf.symbols_str(elf.elf, sym, &file)) != NULL)
        dump_section_symbol(&elf, sym, symstr, &file);
      j++;
    }
  if (j == 0)
    {
      dprintf(STDERR_FILENO, "%s: no symbols\n", filename);
      return (1);
    }
  return (close_file(&file));
}
