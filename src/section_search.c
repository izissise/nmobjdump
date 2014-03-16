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

int		find_section_type(t_elf *elf, uint32_t type,
                        int start, t_file *file)
{
  uint32_t	tmptype;
  unsigned int	i;
  size_t	section_number;

  section_number = elf->section_number(elf->elf);
  i = start;
  while (i < section_number)
    {
      tmptype = elf->sh_type(elf->elf, i, file);
      if (tmptype == type)
        return (i);
      i++;
    }
  return (-1);
}

int		find_section(t_elf *elf, const char *section,
                   int start, t_file *file)
{
  char		*tmpname;
  unsigned int	i;
  size_t	section_number;

  if (section == NULL)
    return (-1);
  section_number = elf->section_number(elf->elf);
  i = start;
  while (i < section_number)
    {
      tmpname = elf->sh_section_name(elf->elf, i, file);
      if ((tmpname != NULL) && !strcmp(tmpname, section))
        return (i);
      i++;
    }
  return (-1);
}
