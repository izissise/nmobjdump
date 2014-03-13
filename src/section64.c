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

void	*get_section_table64(Elf64_Ehdr *elf, t_file *file)
{
  Elf64_Shdr	*shtable;

  shtable = ((size_t)file->data) + deref(&(elf->e_shoff), file);
  return (shtable);
}

size_t	section_number64(Elf64_Ehdr *elf)
{
  return (elf->e_shnum);
}

void	print_elf_info64(Elf64_Ehdr *elf)
{
  int	flags;
  char	*stuff;

  flags = 0x112;
  stuff = "EXEC_P, HAS_SYMS, D_PAGED";
  printf("architecture: i386:x86-64, flags 0x%08x:\n", flags);
  printf("%s\n", stuff);
  printf("start address 0x%016lx\n", elf->e_entry);
}
