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

int			check_valid_elf(t_file *file)
{
  Elf32_Ehdr		*elf;
  unsigned char	*e_ident;

  if (file->size < sizeof(Elf32_Ehdr))
    return (1);
  elf = (Elf32_Ehdr*)file->data;
  e_ident = (unsigned char*)(&(elf->e_ident));
  if (!((e_ident[EI_MAG0] == ELFMAG0)
        && (e_ident[EI_MAG1] == ELFMAG1)
        && (e_ident[EI_MAG2] == ELFMAG2)
        && (e_ident[EI_MAG3] == ELFMAG3)))
    {
      dprintf(STDERR_FILENO, "%s: File format not recognized\n", file->name);
      return (1);
    }
  return (0);
}
