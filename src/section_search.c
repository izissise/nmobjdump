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

int		find_section(t_elf *elf, const char *section, t_file *file)
{
  char		*tmpname;
  unsigned int	i;
  size_t		section_number;

  if (section == NULL)
    return (-1);
  section_number = elf->section_number(elf->elf);
  i = 0;
  while (i < section_number)
    {
      tmpname = elf->sh_section_name(elf->elf, i, file);
      if ((tmpname != NULL) && !strcmp(tmpname, section))
        return (i);
      i++;
    }
  return (-1);
}
