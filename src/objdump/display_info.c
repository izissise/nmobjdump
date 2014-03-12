/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "objdump.h"

void	display_section(t_elf *elf, t_file *file, int i)
{
  void	*tmp;

  tmp = file->data + elf->sh_offset(elf->elf, i, file);
  printf("Contents of section %s:\n",
         elf->sh_section_name(elf->elf, i, file));
  if (tmp + elf->sh_size(elf->elf, i, file) <= file->data + file->size)
    dump_mem(tmp, elf->sh_size(elf->elf, i, file),
             elf->sh_addr(elf->elf, i, file));
}
