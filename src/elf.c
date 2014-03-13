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

int	init_elf(t_elf *elf, t_file *file)
{
  elf->elf = file->data;
  elf->type = ((Elf32_Ehdr*)(elf->elf))->e_ident[EI_CLASS];
  if (!((elf->type == ELFCLASS32) || (elf->type == ELFCLASS64)))
    return (1);
  elf->get_section_table = IS_32(&get_section_table64, &get_section_table64);
  elf->section_number = IS_32(&section_number64, &section_number64);
  elf->sh_offset = IS_32(&sh_offset64, &sh_offset64);
  elf->sh_size = IS_32(&sh_size64, &sh_size64);
  elf->sh_addr = IS_32(&sh_addr64, &sh_addr64);
  elf->sh_section_name = IS_32(&sh_section_name64, &sh_section_name64);
  elf->print_elf_info = IS_32(&print_elf_info64, &print_elf_info64);
  return (0);
}
