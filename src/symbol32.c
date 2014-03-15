/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "general.h"

char		*symbols_str_32(Elf32_Ehdr *elf, int sym, t_file *file)
{
  Elf32_Shdr	*tab;
  char		*res;

  if (((tab = get_section_table32(elf, file)) == NULL)
      || ((void*)(tab + sym) > file->data + file->size)
      || ((void*)(&(tab[tab[sym].sh_link])) > file->data + file->size))
    return (NULL);
  res = file->data + (tab[tab[sym].sh_link]).sh_offset;
  if ((void*)res > file->data + file->size)
    return (NULL);
  return (res);
}

void		dump_symbol32(Elf32_Sym *sym, char *symstr, t_file *file)
{
  if (((void*)(symstr + sym->st_name) >= file->data + file->size)
      || (symstr[sym->st_name] == '\0'))
    return ;
  if (sym->st_value)
    printf(DUMPSYM32, sym->st_value, &symstr[sym->st_name]);
  else
    printf(DUMPSYMNS32, &symstr[sym->st_name]);
}

char	*symbol_name32(Elf32_Sym *sym, char *symstr, t_file *file)
{
  if (((void*)(symstr + sym->st_name) >= file->data + file->size)
      || (symstr[sym->st_name] == '\0'))
    return (NULL);
  return (&symstr[sym->st_name]);
}
