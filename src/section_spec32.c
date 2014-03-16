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

size_t		sh_offset32(Elf32_Ehdr *elf, int idx, t_file *file)
{
  Elf32_Shdr	*section_table;

  if ((section_table = get_section_table32(elf, file)) == NULL)
    return (0);
  if ((void*)(section_table + idx) > file->data + file->size)
    return (0);
  return (section_table[idx].sh_offset);
}

size_t		sh_size32(Elf32_Ehdr *elf, int idx, t_file *file)
{
  Elf32_Shdr	*section_table;

  if ((section_table = get_section_table32(elf, file)) == NULL)
    return (0);
  if ((void*)(section_table + idx) > file->data + file->size)
    return (0);
  return (section_table[idx].sh_size);
}

size_t		sh_addr32(Elf32_Ehdr *elf, int idx, t_file *file)
{
  Elf32_Shdr	*section_table;

  if ((section_table = get_section_table32(elf, file)) == NULL)
    return (0);
  if ((void*)(section_table + idx) > file->data + file->size)
    return (0);
  return (section_table[idx].sh_addr);
}

uint32_t		sh_type32(Elf32_Ehdr *elf, int idx, t_file *file)
{
  Elf32_Shdr		*section_table;

  if ((section_table = get_section_table32(elf, file)) == NULL)
    return (0);
  if ((void*)(section_table + idx) > file->data + file->size)
    return (0);
  return (section_table[idx].sh_type);
}

char		*sh_section_name32(Elf32_Ehdr *elf, int idx, t_file *file)
{
  char		*res;
  Elf32_Shdr	*section_table;
  Elf32_Shdr	*shstr;
  char		*sectionnames;

  if ((section_table = get_section_table32(elf, file)) == NULL)
    return (0);
  if (((void*)(section_table + idx) > file->data + file->size)
      || (elf->e_shstrndx == SHN_UNDEF))
    return (NULL);
  shstr = &(section_table[elf->e_shstrndx]);
  sectionnames = file->data + shstr->sh_offset;
  if ((void*)sectionnames > file->data + file->size)
    return (NULL);
  res = &(sectionnames[section_table[idx].sh_name]);
  if ((void*)res > file->data + file->size)
    return (NULL);
  return (res);
}
